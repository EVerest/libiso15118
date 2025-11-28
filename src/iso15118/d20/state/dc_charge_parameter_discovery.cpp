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

bool handle_compatibility_check(const d20::DcTransferLimits& evse_dc_limits, const session::feedback::DcMaximumLimits ev_max_limits) {
    // In IEC 61851-23-3 a compatibility check is required
    // There are voltage, current and power values indexed with CPD and RATED.
    // The CPD is the communicated value in DC_ChargeParameterDiscoveryRes and RATED the value coming from
    // the EVerest environment (power supply, grid), here we assume that both are the same

    bool compatiblity_flag = true;
    const auto ev_max_limits_cpd = ev_max_limits;
    const float evse_voltage_max_cpd = dt::from_RationalNumber(evse_dc_limits.voltage.max);
    const float evse_voltage_min_cpd = dt::from_RationalNumber(evse_dc_limits.voltage.min);
    const float evse_current_max_cpd = dt::from_RationalNumber(evse_dc_limits.charge_limits.current.max);
    const float evse_current_min_cpd = dt::from_RationalNumber(evse_dc_limits.charge_limits.current.min);
    const float evse_power_max_cpd = dt::from_RationalNumber(evse_dc_limits.charge_limits.power.max);
    const float evse_power_min_cpd = dt::from_RationalNumber(evse_dc_limits.charge_limits.power.min);
    const float evse_voltage_max_rated = evse_voltage_max_cpd;
    const float evse_current_max_rated = evse_current_max_cpd;
    const float evse_power_max_rated = evse_power_max_cpd;

    // CC.5.6 2.d-f
    const float evse_voltage_min_rated = evse_voltage_min_cpd;
    const float evse_current_min_rated = evse_current_min_cpd;
    const float evse_power_min_rated = evse_power_min_cpd;


    // CC.5.6 2.a
    if (ev_max_limits_cpd.voltage <= 500.f) {
        if (evse_voltage_max_cpd > std::min({ev_max_limits_cpd.voltage + 50.f, evse_voltage_max_rated, 500.f})) {
            if (evse_voltage_max_cpd > 500.f) {
                logf_error("EVSE max voltage %.1f V > 500V, but EV max voltage is <= 500 V", evse_voltage_max_cpd);
            } else {
                logf_error("EVSE max voltage %.1f V > EV max voltage + 50V: %.1f V", evse_voltage_max_cpd, ev_max_limits_cpd.voltage + 50);
            }
            compatiblity_flag = false;
        }
    }
    if (ev_max_limits_cpd.voltage > 500.f) {
        if (evse_voltage_max_cpd > std::min(ev_max_limits_cpd.voltage * 1.1f, evse_voltage_max_rated)) {
            logf_error("EVSE max voltage %.1f V > EV max voltage (> 500 V) multiplied by 1,1: %.1f V", evse_voltage_max_cpd, ev_max_limits_cpd.voltage * 1.1f);
            compatiblity_flag = false;
        }
    }

    // CC.5.6 2.b
    if (evse_current_max_cpd > std::min(ev_max_limits_cpd.current, evse_current_max_rated)) {
        logf_error("EVSE max current %.1f A > EV max current %.1f A", evse_current_max_cpd, ev_max_limits_cpd.current);
        compatiblity_flag = false;
    }

    // CC.5.6 2.c
    float ev_max_power = ev_max_limits_cpd.power;
    if (ev_max_power == 0) {
        ev_max_power = std::max(evse_voltage_max_cpd * evse_current_max_cpd, 200000.f);
    }
    if (ev_max_power > std::min(ev_max_power, evse_power_max_rated)) {
            logf_error("EVSE max power %.1f W > EV max power %.1f W", evse_power_max_cpd, ev_max_power);
            compatiblity_flag = false;
    }

    // CC.5.6 2.g
    if (evse_power_min_rated >= ev_max_power) {
        logf_error("EVSE min power %.1f W >= EV max power %.1f W!", evse_power_min_rated, ev_max_power);
        compatiblity_flag = false;
    }
    if (evse_voltage_min_rated >= ev_max_limits_cpd.voltage) {
        logf_error("EVSE min voltage %.1f V >= EV max voltage %.1f V!", evse_voltage_min_rated, ev_max_limits_cpd.voltage);
        compatiblity_flag = false;
    }
    if (evse_current_min_rated >= ev_max_limits_cpd.current) {
        logf_error("EVSE min current %.1f A >= EV max current %.1f A!", evse_current_min_rated, ev_max_limits_cpd.current);
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

        auto res = handle_request(*req, m_ctx.session, m_ctx.session_config.powersupply_limits);

        // Do compatibility check IEC61851-23 CC.5.6
        if (not handle_compatibility_check(m_ctx.session_config.dc_limits, dc_max_limits)) {
            response_with_code(res, dt::ResponseCode::FAILED_WrongChargeParameter);
        }

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
