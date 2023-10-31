// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/session_stop.hpp>

#include <iso15118/detail/d20/state/session_stop.hpp>

namespace iso15118::d20::state {

void SessionStop::enter() {
    ctx.log.enter_state("SessionStop");
}

FsmSimpleState::HandleEventReturnType SessionStop::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    auto variant = ctx.get_request();
    if (variant->get_type() != message_20::Type::SessionStopReq) {
        ctx.log("expected DC_WeldingDetection! But code type id: %d", variant->get_type());
        return sa.PASS_ON;
    }

    const auto& req = variant->get<message_20::SessionStopRequest>();

    const auto res = handle_request(req, ctx.session);

    ctx.respond(res);

    return sa.PASS_ON; // Todo(sl): Stop TCP/TLS
}

} // namespace iso15118::d20::state
