// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/session_setup.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/helper.hpp>

#include <iso15118/d20/state/authorization_setup.hpp>

#include <iso15118/message/session_setup.hpp>

#include <algorithm>

static bool session_is_zero(const iso15118::message_20::Header& header) {
    return std::all_of(header.session_id.begin(), header.session_id.end(), [](int i) { return i == 0; });
}

namespace iso15118::d20::state {

void SessionSetup::enter() {
    ctx.log.enter_state("SessionSetup");
}

FsmSimpleState::HandleEventReturnType SessionSetup::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev == FsmEvent::V2GTP_MESSAGE) {
        auto variant = ctx.get_request();
        if (variant->get_type() != message_20::Type::SessionSetupReq) {
            ctx.log("expected SessionSetupReq! But code type id: %d", variant->get_type());
            return sa.PASS_ON;
        }

        const auto& req = variant->get<message_20::SessionSetupRequest>();

        logf("Received session setup with evccid: %s\n", req.evccid.c_str());

        message_20::SessionSetupResponse response{};

        ctx.config = Config(); // todo(sl): config is initialized here temporarily, needs refactoring

        if (session_is_zero(req.header)) {
            ctx.session = Session();
            response.response_code = message_20::ResponseCode::OK_NewSessionEstablished;
        } else if (req.header.session_id == ctx.session.get_id()) {
            response.response_code = message_20::ResponseCode::OK_OldSessionJoined;
        } else {
            ctx.session = Session();
            response.response_code = message_20::ResponseCode::OK_NewSessionEstablished;
        }

        setup_header(response.header, ctx.session);

        response.evseid = "everest se";

        ctx.respond(response);

        return sa.create_simple<AuthorizationSetup>(ctx);
    }

    return sa.PASS_ON;
}

} // namespace iso15118::d20::state
