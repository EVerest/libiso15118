// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/authorization.hpp>

#include <iso15118/d20/state/service_discovery.hpp>

#include <iso15118/detail/d20/state/authorization.hpp>

namespace iso15118::d20::state {

void Authorization::enter() {
    ctx.log.enter_state("Authorization");
}

FsmSimpleState::HandleEventReturnType Authorization::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    auto variant = ctx.get_request();

    if (variant->get_type() == message_20::Type::AuthorizationReq) {
        const auto& req = variant->get<message_20::AuthorizationRequest>();

        const auto& res = handle_request(req, ctx.session, ctx.config);

        ctx.respond(res);

        if (ctx.config.authorization_status == d20::Config::AuthStatus::Accepted) {
            return sa.create_simple<ServiceDiscovery>(ctx);
        } else {
            return sa.HANDLED_INTERNALLY;
        }
    } else {
        ctx.log("expected AuthorizationReq! But code type id: %d", variant->get_type());
        return sa.PASS_ON;
    }
}

} // namespace iso15118::d20::state
