// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/ac_charge_parameter_discovery.hpp>
#include <iso15118/d20/state/schedule_exchange.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/d20/state/ac_charge_parameter_discovery.hpp>
#include <iso15118/detail/d20/state/session_stop.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

using AC_ModeReq = message_20::AC_ChargeParameterDiscoveryRequest::AC_CPDReqEnergyTransferMode;
using BPT_AC_ModeReq = message_20::AC_ChargeParameterDiscoveryRequest::BPT_AC_CPDReqEnergyTransferMode;

using AC_ModeRes = message_20::AC_ChargeParameterDiscoveryResponse::AC_CPDResEnergyTransferMode;
using BPT_AC_ModeRes = message_20::AC_ChargeParameterDiscoveryResponse::BPT_AC_CPDResEnergyTransferMode;

message_20::AC_ChargeParameterDiscoveryResponse
handle_request(const message_20::AC_ChargeParameterDiscoveryRequest& req, const d20::Session& session,
               const d20::SessionConfig& config) {

    message_20::AC_ChargeParameterDiscoveryResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    if (std::holds_alternative<AC_ModeReq>(req.transfer_mode)) {
        if (session.get_selected_energy_service() != message_20::ServiceCategory::AC) {
            return response_with_code(res, message_20::ResponseCode::FAILED_WrongChargeParameter);
        }

        auto& mode = res.transfer_mode.emplace<AC_ModeRes>();
        mode = config.evse_ac_parameter;

    } else if (std::holds_alternative<BPT_AC_ModeReq>(req.transfer_mode)) {
        if (session.get_selected_energy_service() != message_20::ServiceCategory::AC_BPT) {
            return response_with_code(res, message_20::ResponseCode::FAILED_WrongChargeParameter);
        }

        auto& mode = res.transfer_mode.emplace<BPT_AC_ModeRes>();
        mode = config.evse_ac_bpt_parameter;

    } else {
        return response_with_code(res, message_20::ResponseCode::FAILED_WrongChargeParameter);
    }

    return response_with_code(res, message_20::ResponseCode::OK);
}

void AC_ChargeParameterDiscovery::enter() {
    ctx.log.enter_state("AC_ChargeParameterDiscovery");
}

FsmSimpleState::HandleEventReturnType AC_ChargeParameterDiscovery::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    const auto variant = ctx.get_request();

    if (const auto req = variant->get_if<message_20::AC_ChargeParameterDiscoveryRequest>()) {

        const auto res = handle_request(*req, ctx.session, ctx.config);

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
        ctx.log("expected AC_ChargeParameterDiscovery! But code type id: %d", variant->get_type());
        ctx.session_stopped = true;

        // Sequence Error
        const message_20::Type req_type = variant->get_type();
        send_sequence_error(req_type, ctx);

        return sa.PASS_ON;
    }
}

} // namespace iso15118::d20::state
