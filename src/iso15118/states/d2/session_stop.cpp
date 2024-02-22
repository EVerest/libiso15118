// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d2/state/session_stop.hpp>

#include <iso15118/detail/d2/context_helper.hpp>
#include <iso15118/detail/d2/state/session_stop.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d2::state {

message_2::SessionStopResponse handle_request(const message_2::SessionStopRequest& req, const d2::Session& session) {

    if (req.ev_termination_code.has_value()) {
        logf("EV termination code: %s\n", req.ev_termination_code.value().c_str());
    }
    if (req.ev_termination_explanation.has_value()) {
        logf("EV Termination explanation: %s\n", req.ev_termination_explanation.value().c_str());
    }

    message_2::SessionStopResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_2::ResponseCode::FAILED_UnknownSession);
    }

    //RBL Not part of ISO2?
    // if (req.charging_session == message_2::ChargingSession::ServiceRenegotiation &&
    //     session.service_renegotiation_supported == false) {
    //     return response_with_code(res, message_2::ResponseCode::FAILED_NoServiceRenegotiationSupported);
    // }

    // Todo(sl): Check req.charging_session

    return response_with_code(res, message_2::ResponseCode::OK);
}

void SessionStop::enter() {
    ctx.log.enter_state("SessionStop");
}

FsmSimpleState::HandleEventReturnType SessionStop::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    const auto variant = ctx.get_request();

    if (const auto req = variant->get_if<message_2::SessionStopRequest>()) {
        const auto res = handle_request(*req, ctx.session);

        ctx.respond(res);

        // Todo(sl): Tell the reason why the charger is stopping. Shutdown, Error, etc.
        ctx.session_stopped = true;

        return sa.PASS_ON;
    } else {
        ctx.log("expected SessionStop! But code type id: %d", variant->get_type());

        // Sequence Error
        const message_2::Type req_type = variant->get_type();
        send_sequence_error(req_type, ctx);

        ctx.session_stopped = true;
        return sa.PASS_ON;
    }
}

} // namespace iso15118::d2::state
