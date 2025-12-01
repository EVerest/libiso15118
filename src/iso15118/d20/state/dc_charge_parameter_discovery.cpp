// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/dc_charge_parameter_discovery.hpp>
#include <iso15118/d20/state/schedule_exchange.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/d20/state/dc_charge_parameter_discovery.hpp>
#include <iso15118/detail/d20/state/session_stop.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

namespace dt = message_20::datatypes;

using DC_ModeReq = dt::DC_CPDReqEnergyTransferMode;
using BPT_DC_ModeReq = dt::BPT_DC_CPDReqEnergyTransferMode;

using DC_ModeRes = dt::DC_CPDResEnergyTransferMode;
using BPT_DC_ModeRes = dt::BPT_DC_CPDResEnergyTransferMode;

template <typename In, typename Out> void convert(Out& out, const In& in);

template <> void convert(DC_ModeRes& out, const d20::DcTransferLimits& in) {
    out.max_charge_power = in.charge_limits.power.max;
    out.min_charge_power = in.charge_limits.power.min;
    out.max_charge_current = in.charge_limits.current.max;
    out.min_charge_current = in.charge_limits.current.min;
    out.max_voltage = in.voltage.max;
    out.min_voltage = in.voltage.min;
    out.power_ramp_limit = in.power_ramp_limit;
}

template <> void convert(BPT_DC_ModeRes& out, const d20::DcTransferLimits& in) {
    convert(static_cast<DC_ModeRes&>(out), in);

    if (in.discharge_limits.has_value()) {
        auto& discharge_limits = in.discharge_limits.value();
        out.max_discharge_power = discharge_limits.power.max;
        out.min_discharge_power = discharge_limits.power.min;
        out.max_discharge_current = discharge_limits.current.max;
        out.min_discharge_current = discharge_limits.current.min;
    }
}

template <typename DCMode>
bool handle_compatibility_check(const d20::DcTransferLimits& evse_dc_limits, const DCMode& ev_limits) {
    // In IEC 61851-23-3 a compatibility check is required

    constexpr auto MAX_VOLTAGE_OFFSET = 50.f;
    constexpr auto MAX_VOLTAGE_THREASHOLD = 500.f;
    constexpr auto MAX_VOLTAGE_FACTOR = 1.1f;
    constexpr auto MAX_POWER_LIMIT = 200000.f;
    bool compatiblity_flag = true;
    float ev_max_power;
    float ev_max_current;
    float ev_max_voltage;

    if (const auto* mode = std::get_if<DC_ModeReq>(&ev_limits)) {
        ev_max_power = dt::from_RationalNumber(mode->max_charge_power);
        ev_max_current = dt::from_RationalNumber(mode->max_charge_current);
        ev_max_voltage = dt::from_RationalNumber(mode->max_voltage);
    } else if (const auto* mode = std::get_if<BPT_DC_ModeReq>(&ev_limits)) {
        ev_max_power = dt::from_RationalNumber(mode->max_charge_power);
        ev_max_current = dt::from_RationalNumber(mode->max_charge_current);
        ev_max_voltage = dt::from_RationalNumber(mode->max_voltage);
    } else {
        return false;
    }

    const float evse_max_voltage = dt::from_RationalNumber(evse_dc_limits.voltage.max);
    const float evse_min_voltage = dt::from_RationalNumber(evse_dc_limits.voltage.min);
    const float evse_max_current = dt::from_RationalNumber(evse_dc_limits.charge_limits.current.max);
    const float evse_min_current = dt::from_RationalNumber(evse_dc_limits.charge_limits.current.min);
    const float evse_max_power = dt::from_RationalNumber(evse_dc_limits.charge_limits.power.max);
    const float evse_min_power = dt::from_RationalNumber(evse_dc_limits.charge_limits.power.min);

    // CC.5.6 2.a
    if (ev_max_voltage <= MAX_VOLTAGE_THREASHOLD) {
        if (evse_max_voltage >
            std::min({ev_max_voltage + MAX_VOLTAGE_OFFSET, evse_max_voltage, MAX_VOLTAGE_THREASHOLD})) {
            if (evse_max_voltage > MAX_VOLTAGE_THREASHOLD) {
                logf_error("EVSE max voltage %.1f V > EV max voltage 500V", evse_max_voltage);
            } else {
                logf_error("EVSE max voltage %.1f V > EV max voltage + 50V: %.1f V", evse_max_voltage,
                           ev_max_voltage + MAX_VOLTAGE_OFFSET);
            }
            compatiblity_flag = false;
        }
    }
    if (ev_max_voltage > MAX_VOLTAGE_THREASHOLD) {
        if (evse_max_voltage > std::min(ev_max_voltage * MAX_VOLTAGE_FACTOR, evse_max_voltage)) {
            logf_error("EVSE max voltage %.1f V > EV max voltage (> 500 V) multiplied by 1,1: %.1f V", evse_max_voltage,
                       ev_max_voltage * MAX_VOLTAGE_FACTOR);
            compatiblity_flag = false;
        }
    }

    // CC.5.6 2.b
    if (evse_max_current > std::min(ev_max_current, evse_max_current)) {
        logf_error("EVSE max current %.1f A > EV max current %.1f A", evse_max_current, ev_max_current);
        compatiblity_flag = false;
    }

    // CC.5.6 2.c
    float ev_power_max = ev_max_power;
    if (ev_power_max == 0) {
        ev_power_max = std::max(ev_max_voltage * ev_max_current, MAX_POWER_LIMIT);
    }
    if (evse_max_power > std::min(ev_power_max, evse_max_power)) {
        logf_error("EVSE max power %.1f W > EV max power %.1f W", evse_max_power, ev_power_max);
        compatiblity_flag = false;
    }
    // CC.5.6 2.d-f here not implemented because we make no difference between CPD and RATED
    // CC.5.6 2.g
    if (evse_min_power >= ev_power_max) {
        logf_error("EVSE min power %.1f W >= EV max power %.1f W!", evse_min_power, ev_max_power);
        compatiblity_flag = false;
    }
    if (evse_min_voltage >= ev_max_voltage) {
        logf_error("EVSE min voltage %.1f V >= EV max voltage %.1f V!", evse_min_voltage, ev_max_voltage);
        compatiblity_flag = false;
    }
    if (evse_min_current >= ev_max_current) {
        logf_error("EVSE min current %.1f A >= EV max current %.1f A!", evse_min_current, ev_max_current);
        compatiblity_flag = false;
    }
    return compatiblity_flag;
}

message_20::DC_ChargeParameterDiscoveryResponse
handle_request(const message_20::DC_ChargeParameterDiscoveryRequest& req, const d20::Session& session,
               const d20::DcTransferLimits& dc_limits) {

    message_20::DC_ChargeParameterDiscoveryResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, dt::ResponseCode::FAILED_UnknownSession);
    }

    const auto selected_energy_service = session.get_selected_services().selected_energy_service;

    if (std::holds_alternative<DC_ModeReq>(req.transfer_mode)) {
        if (not(selected_energy_service == dt::ServiceCategory::DC or
                selected_energy_service == dt::ServiceCategory::MCS)) {
            return response_with_code(res, dt::ResponseCode::FAILED_WrongChargeParameter);
        }

        auto& mode = res.transfer_mode.emplace<DC_ModeRes>();
        convert(mode, dc_limits);

    } else if (std::holds_alternative<BPT_DC_ModeReq>(req.transfer_mode)) {
        if (not(selected_energy_service == dt::ServiceCategory::DC_BPT or
                selected_energy_service == dt::ServiceCategory::MCS_BPT)) {
            return response_with_code(res, dt::ResponseCode::FAILED_WrongChargeParameter);
        }

        if (not dc_limits.discharge_limits.has_value()) {
            logf_error("Transfer mode is BPT, but only dc limits without discharge limits are provided!");
            return response_with_code(res, dt::ResponseCode::FAILED);
        }

        auto& mode = res.transfer_mode.emplace<BPT_DC_ModeRes>();
        convert(mode, dc_limits);

    } else {
        // Not supported transfer_mode
        return response_with_code(res, dt::ResponseCode::FAILED_WrongChargeParameter);
    }

    // Do compatibility check IEC61851-23-3 CC.5.6
    if (not handle_compatibility_check(dc_limits, req.transfer_mode))
        return response_with_code(res, dt::ResponseCode::FAILED_WrongChargeParameter);

    return response_with_code(res, dt::ResponseCode::OK);
}

void DC_ChargeParameterDiscovery::enter() {
    m_ctx.log.enter_state("DC_ChargeParameterDiscovery");
}

Result DC_ChargeParameterDiscovery::feed(Event ev) {

    if (ev != Event::V2GTP_MESSAGE) {
        return {};
    }

    const auto variant = m_ctx.pull_request();

    if (const auto req = variant->get_if<message_20::DC_ChargeParameterDiscoveryRequest>()) {

        auto dc_max_limits = session::feedback::DcMaximumLimits{};

        if (const auto* mode = std::get_if<DC_ModeReq>(&req->transfer_mode)) {
            dc_max_limits.current = dt::from_RationalNumber(mode->max_charge_current);
            dc_max_limits.voltage = dt::from_RationalNumber(mode->max_voltage);
            dc_max_limits.power = dt::from_RationalNumber(mode->max_charge_power);

            logf_info("Max charge current %fA", dt::from_RationalNumber(mode->max_charge_current));

            // Set EV transfer limits
            m_ctx.session_ev_info.ev_transfer_limits.emplace<DC_ModeReq>(*mode);
        } else if (const auto* mode = std::get_if<BPT_DC_ModeReq>(&req->transfer_mode)) {
            dc_max_limits.current = dt::from_RationalNumber(mode->max_charge_current);
            dc_max_limits.voltage = dt::from_RationalNumber(mode->max_voltage);
            dc_max_limits.power = dt::from_RationalNumber(mode->max_charge_power);

            logf_info("Max charge current %fA", dt::from_RationalNumber(mode->max_charge_current));
            logf_info("Max discharge current %fA", dt::from_RationalNumber(mode->max_discharge_current));

            // Set EV transfer limits
            m_ctx.session_ev_info.ev_transfer_limits.emplace<BPT_DC_ModeReq>(*mode);
        }

        const auto res = handle_request(*req, m_ctx.session, m_ctx.session_config.powersupply_limits);

        m_ctx.respond(res);

        m_ctx.feedback.dc_max_limits(dc_max_limits);
        m_ctx.feedback.response_code(res.response_code);

        if (res.response_code >= dt::ResponseCode::FAILED) {
            m_ctx.session_stopped = true;
            return {};
        }

        return m_ctx.create_state<ScheduleExchange>();
    } else if (const auto req = variant->get_if<message_20::SessionStopRequest>()) {
        const auto res = handle_request(*req, m_ctx.session);

        m_ctx.respond(res);
        m_ctx.session_stopped = true;
        m_ctx.feedback.response_code(res.response_code);

        return {};
    } else {
        m_ctx.log("expected DC_ChargeParameterDiscovery! But code type id: %d", variant->get_type());
        m_ctx.session_stopped = true;

        // Sequence Error
        const message_20::Type req_type = variant->get_type();
        send_sequence_error(req_type, m_ctx);

        m_ctx.feedback.response_code(dt::ResponseCode::FAILED_SequenceError);

        return {};
    }
}

} // namespace iso15118::d20::state
