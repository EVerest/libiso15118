// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/dc_charge_parameter_discovery.hpp>
#include <iso15118/d20/state/schedule_exchange.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/d20/state/dc_charge_parameter_discovery.hpp>
#include <iso15118/detail/d20/state/session_stop.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

using DC_ModeReq = message_20::DC_ChargeParameterDiscoveryRequest::DC_CPDReqEnergyTransferMode;
using BPT_DC_ModeReq = message_20::DC_ChargeParameterDiscoveryRequest::BPT_DC_CPDReqEnergyTransferMode;

using DC_ModeRes = message_20::DC_ChargeParameterDiscoveryResponse::DC_CPDResEnergyTransferMode;
using BPT_DC_ModeRes = message_20::DC_ChargeParameterDiscoveryResponse::BPT_DC_CPDResEnergyTransferMode;

template <typename In> void convert(DC_ModeRes& out, const In& in) {
    out.max_charge_power = in.max_charge_power;
    out.min_charge_power = in.min_charge_power;
    out.max_charge_current = in.max_charge_current;
    out.min_charge_current = in.min_charge_current;
    out.max_voltage = in.max_voltage;
    out.min_voltage = in.min_voltage;
    out.power_ramp_limit = in.power_ramp_limit;
}

template <typename In> void convert(BPT_DC_ModeRes& out, const In& in) {
    out.max_charge_power = in.max_charge_power;
    out.min_charge_power = in.min_charge_power;
    out.max_charge_current = in.max_charge_current;
    out.min_charge_current = in.min_charge_current;
    out.max_voltage = in.max_voltage;
    out.min_voltage = in.min_voltage;
    out.power_ramp_limit = in.power_ramp_limit;

    out.max_discharge_power = in.max_discharge_power;
    out.min_discharge_power = in.min_discharge_power;
    out.max_discharge_current = in.max_discharge_current;
    out.min_discharge_current = in.min_discharge_current;
}

message_20::DC_ChargeParameterDiscoveryResponse
handle_request(const message_20::DC_ChargeParameterDiscoveryRequest& req, const d20::Session& session,
               const d20::DcLimits& dc_limits) {

    message_20::DC_ChargeParameterDiscoveryResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    if (std::holds_alternative<DC_ModeReq>(req.transfer_mode)) {
        if (session.get_selected_energy_service() != message_20::ServiceCategory::DC) {
            return response_with_code(res, message_20::ResponseCode::FAILED_WrongChargeParameter);
        }

        auto& mode = res.transfer_mode.emplace<DC_ModeRes>();

        if (const auto dc_charge_limits = std::get_if<d20::DcChargeLimits>(&dc_limits)) {
            convert(mode, *dc_charge_limits);
        } else if (const auto dc_discharge_limits = std::get_if<d20::DcDischargeLimits>(&dc_limits)) {
            convert(mode, *dc_discharge_limits);
        }

    } else if (std::holds_alternative<BPT_DC_ModeReq>(req.transfer_mode)) {
        if (session.get_selected_energy_service() != message_20::ServiceCategory::DC_BPT) {
            return response_with_code(res, message_20::ResponseCode::FAILED_WrongChargeParameter);
        }

        if (std::holds_alternative<d20::DcChargeLimits>(dc_limits)) {
            logf_error("Transfer mode is BPT, but only dc limits without discharge are provided!");
            return response_with_code(res, message_20::ResponseCode::FAILED);
        } else if (const auto dc_discharge_limits = std::get_if<d20::DcDischargeLimits>(&dc_limits)) {
            auto& mode = res.transfer_mode.emplace<BPT_DC_ModeRes>();
            convert(mode, *dc_discharge_limits);
        }

    } else {
        // Not supported transfer_mode
        return response_with_code(res, message_20::ResponseCode::FAILED_WrongChargeParameter);
    }

    return response_with_code(res, message_20::ResponseCode::OK);
}

void DC_ChargeParameterDiscovery::enter() {
    ctx.log.enter_state("DC_ChargeParameterDiscovery");
}

FsmSimpleState::HandleEventReturnType DC_ChargeParameterDiscovery::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    const auto variant = ctx.pull_request();

    if (const auto req = variant->get_if<message_20::DC_ChargeParameterDiscoveryRequest>()) {
        message_20::RationalNumber max_current;

        if (std::holds_alternative<DC_ModeReq>(req->transfer_mode)) {

            max_current = std::get<0>(req->transfer_mode).max_charge_current;

        } else if (std::holds_alternative<BPT_DC_ModeReq>(req->transfer_mode)) {

            max_current = std::get<1>(req->transfer_mode).max_charge_current;

            const auto& max_discharge_current = std::get<1>(req->transfer_mode).max_discharge_current;

            logf_info("Max discharge current %de%d\n", max_discharge_current.value, max_discharge_current.exponent);
        }

        logf_info("Max charge current %de%d\n", max_current.value, max_current.exponent);

        const auto res = handle_request(*req, ctx.session, ctx.session_config.dc_limits);

        ctx.respond(res);

        if (res.response_code >= message_20::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        return sa.create_simple<ScheduleExchange>(ctx);
    } else if (const auto req = variant->get_if<message_20::SessionStopRequest>()) {
        const auto res = handle_request(*req, ctx.session);

        ctx.respond(res);
        ctx.session_stopped = true;

        return sa.PASS_ON;
    } else {
        ctx.log("expected DC_ChargeParameterDiscovery! But code type id: %d", variant->get_type());
        ctx.session_stopped = true;

        // Sequence Error
        const message_20::Type req_type = variant->get_type();
        send_sequence_error(req_type, ctx);

        return sa.PASS_ON;
    }
}

} // namespace iso15118::d20::state
