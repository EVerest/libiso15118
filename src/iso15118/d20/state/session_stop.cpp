// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/session_stop.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/d20/state/session_stop.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

message_20::SessionStopResponse handle_request(const message_20::SessionStopRequest& req, const d20::Session& session) {

    message_20::SessionStopResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    // Todo(sl): Check req.charging_session, ev_termination_code & ev_termination_explanation

    return response_with_code(res, message_20::ResponseCode::OK);
}

void SessionStop::enter() {
    ctx.log.enter_state("SessionStop");
}

FsmSimpleState::HandleEventReturnType SessionStop::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    const auto variant = ctx.get_request();

    if (const auto req = variant->get_if<message_20::SessionStopRequest>()) {
        const auto res = handle_request(*req, ctx.session);

        ctx.respond(res);

        return sa.PASS_ON; // Todo(sl): Stop TCP/TLS
    } else {
        ctx.log("expected DC_WeldingDetection! But code type id: %d", variant->get_type());
        return sa.PASS_ON;
    }
}

} // namespace iso15118::d20::state
