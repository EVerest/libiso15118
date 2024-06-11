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

message_20::DC_ChargeParameterDiscoveryResponse
handle_request(const message_20::DC_ChargeParameterDiscoveryRequest& req, const d20::Session& session,
               const TransferMode& transfer_mode) {

    message_20::DC_ChargeParameterDiscoveryResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    if (std::holds_alternative<DC_ModeReq>(req.transfer_mode)) {
        if (session.get_selected_energy_service() != message_20::ServiceCategory::DC) {
            return response_with_code(res, message_20::ResponseCode::FAILED_WrongChargeParameter);
        }

        const DC_ModeRes config_mode = {transfer_mode.max_charge_power,   transfer_mode.min_charge_power,
                                        transfer_mode.max_charge_current, transfer_mode.min_charge_current,
                                        transfer_mode.max_voltage,        transfer_mode.min_voltage,
                                        transfer_mode.power_ramp_limit};

        res.transfer_mode.emplace<DC_ModeRes>(config_mode);
    } else if (std::holds_alternative<BPT_DC_ModeReq>(req.transfer_mode)) {
        if (session.get_selected_energy_service() != message_20::ServiceCategory::DC_BPT) {
            return response_with_code(res, message_20::ResponseCode::FAILED_WrongChargeParameter);
        }

        res.transfer_mode.emplace<BPT_DC_ModeRes>(transfer_mode);

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

    const auto variant = ctx.get_request();

    const auto v2g_message_type = convert_request_type(variant->get_type());
    ctx.feedback.v2g_message(v2g_message_type);

    if (const auto req = variant->get_if<message_20::DC_ChargeParameterDiscoveryRequest>()) {
        message_20::RationalNumber max_current;

        if (std::holds_alternative<DC_ModeReq>(req->transfer_mode)) {

            max_current = std::get<0>(req->transfer_mode).max_charge_current;

        } else if (std::holds_alternative<BPT_DC_ModeReq>(req->transfer_mode)) {

            max_current = std::get<1>(req->transfer_mode).max_charge_current;

            const auto& max_discharge_current = std::get<1>(req->transfer_mode).max_discharge_current;

            logf("Max discharge current %de%d\n", max_discharge_current.value, max_discharge_current.exponent);

            // Check if config discharge options are set
            if (not ctx.config.max_discharge_power.has_value() || not ctx.config.min_discharge_power.has_value() ||
                not ctx.config.max_discharge_current.has_value() || not ctx.config.min_discharge_current.has_value()) {
                logf("Some session config discharge options are not set. Set them to zero watts and amps!");
            }
        }

        logf("Max charge current %de%d\n", max_current.value, max_current.exponent);

        const TransferMode transfer_mode = {ctx.config.max_charge_power,
                                            ctx.config.min_charge_power,
                                            ctx.config.max_charge_current,
                                            ctx.config.min_charge_current,
                                            ctx.config.max_voltage,
                                            ctx.config.min_voltage,
                                            ctx.config.power_ramp_limit,
                                            ctx.config.max_discharge_power.value_or(message_20::RationalNumber()),
                                            ctx.config.min_discharge_power.value_or(message_20::RationalNumber()),
                                            ctx.config.max_discharge_current.value_or(message_20::RationalNumber()),
                                            ctx.config.min_discharge_current.value_or(message_20::RationalNumber())};

        const auto res = handle_request(*req, ctx.session, transfer_mode);

        ctx.respond(res);

        ctx.feedback.v2g_message(session::feedback::V2gMessageId::DcChargeParameterDiscoveryRes);

        if (res.response_code >= message_20::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        return sa.create_simple<ScheduleExchange>(ctx);
    } else if (const auto req = variant->get_if<message_20::SessionStopRequest>()) {
        const auto res = handle_request(*req, ctx.session);

        ctx.respond(res);
        ctx.session_stopped = true;

        ctx.feedback.v2g_message(session::feedback::V2gMessageId::SessionStopRes);

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
