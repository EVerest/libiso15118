// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/authorization_setup.hpp>

#include <iso15118/d20/state/authorization.hpp>

#include <iso15118/message/authorization_setup.hpp>

#include <iso15118/detail/d20/state/authorization_setup.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

void AuthorizationSetup::enter() {
    ctx.log.enter_state("AuthorizationSetup");
}

FsmSimpleState::HandleEventReturnType AuthorizationSetup::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev == FsmEvent::V2GTP_MESSAGE) {
        auto variant = ctx.get_request();
        if (variant->get_type() != message_20::Type::AuthorizationSetupReq) {
            ctx.log("expected AuthorizationSetupReq! But code type id: %d", variant->get_type());
            return sa.PASS_ON;
        }

        const auto& req = variant->get<message_20::AuthorizationSetupRequest>();

        const auto& res = handle_request(req, ctx.session, ctx.config);

        logf("Timestamp: %d\n", req.header.timestamp);

        ctx.respond(res);

        return sa.create_simple<Authorization>(ctx);
    }

    return sa.PASS_ON;
}

} // namespace iso15118::d20::state
