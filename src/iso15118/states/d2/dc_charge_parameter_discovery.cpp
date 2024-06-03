// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d2/state/dc_charge_parameter_discovery.hpp>
#include <iso15118/d2/state/dc_cable_check.hpp>

#include <iso15118/detail/d2/context_helper.hpp>
#include <iso15118/detail/d2/state/dc_charge_parameter_discovery.hpp>
#include <iso15118/detail/d2/state/session_stop.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d2::state {

using DC_ModeReq = message_2::DC_ChargeParameterDiscoveryRequest::DC_CPDReqEnergyTransferMode;
using BPT_DC_ModeReq = message_2::DC_ChargeParameterDiscoveryRequest::BPT_DC_CPDReqEnergyTransferMode;

using DC_ModeRes = message_2::DC_ChargeParameterDiscoveryResponse::DC_CPDResEnergyTransferMode;
using BPT_DC_ModeRes = message_2::DC_ChargeParameterDiscoveryResponse::BPT_DC_CPDResEnergyTransferMode;

message_2::DC_ChargeParameterDiscoveryResponse
handle_request(const message_2::DC_ChargeParameterDiscoveryRequest& req, const d2::Session& session,
               const d2::SessionConfig& config) {

    message_2::DC_ChargeParameterDiscoveryResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_2::ResponseCode::FAILED_UnknownSession);
    }

    if (std::holds_alternative<DC_ModeReq>(req.transfer_mode)) {
        if (session.get_selected_energy_service() != message_2::ServiceCategory::DC) {
            return response_with_code(res, message_2::ResponseCode::FAILED_WrongChargeParameter);
        }

        auto& mode = res.transfer_mode.emplace<DC_ModeRes>();
        mode = config.evse_dc_parameter;

    } else if (std::holds_alternative<BPT_DC_ModeReq>(req.transfer_mode)) {
        if (session.get_selected_energy_service() != message_2::ServiceCategory::DC_BPT) {
            return response_with_code(res, message_2::ResponseCode::FAILED_WrongChargeParameter);
        }

        auto& mode = res.transfer_mode.emplace<BPT_DC_ModeRes>();
        mode = config.evse_dc_bpt_parameter;

    } else {
        // Not supported transfer_mode
        return response_with_code(res, message_2::ResponseCode::FAILED_WrongChargeParameter);
    }

    return response_with_code(res, message_2::ResponseCode::OK);
}

void DC_ChargeParameterDiscovery::enter() {
    ctx.log.enter_state("DC_ChargeParameterDiscovery");
}

FsmSimpleState::HandleEventReturnType DC_ChargeParameterDiscovery::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    const auto variant = ctx.get_request();

    if (const auto req = variant->get_if<message_2::DC_ChargeParameterDiscoveryRequest>()) {
        message_2::RationalNumber max_current;

        if (std::holds_alternative<DC_ModeReq>(req->transfer_mode)) {

            max_current = std::get<0>(req->transfer_mode).max_charge_current;

        } else if (std::holds_alternative<BPT_DC_ModeReq>(req->transfer_mode)) {

            max_current = std::get<1>(req->transfer_mode).max_charge_current;

            const auto& max_discharge_current = std::get<1>(req->transfer_mode).max_discharge_current;

            logf("Max discharge current %de%d\n", max_discharge_current.value, max_discharge_current.exponent);
        }

        logf("Max charge current %de%d\n", max_current.value, max_current.exponent);

        const auto res = handle_request(*req, ctx.session, ctx.config);

        ctx.respond(res);

        if (res.response_code >= message_2::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        //RDB Go on to CableCheck next
        return sa.create_simple<DC_CableCheck>(ctx);

    } else if (const auto req = variant->get_if<message_2::SessionStopRequest>()) {
        const auto res = handle_request(*req, ctx.session);

        ctx.respond(res);
        ctx.session_stopped = true;

        return sa.PASS_ON;
    } else {
        ctx.log("expected DC_ChargeParameterDiscovery! But code type id: %d", variant->get_type());
        ctx.session_stopped = true;

        // Sequence Error
        const message_2::Type req_type = variant->get_type();
        send_sequence_error(req_type, ctx);

        return sa.PASS_ON;
    }
}

} // namespace iso15118::d2::state
