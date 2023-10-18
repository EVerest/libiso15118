// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/dc_cable_check.hpp>

#include <iso15118/d20/state/dc_pre_charge.hpp>

#include <iso15118/detail/d20/state/dc_cable_check.hpp>

namespace iso15118::d20::state {

void DC_CableCheck::enter() {
    ctx.log.enter_state("DC_CableCheck");
}

FsmSimpleState::HandleEventReturnType DC_CableCheck::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev == FsmEvent::NEW_V2GTP_MESSAGE) {
        auto variant = ctx.get_request();
        if (variant->get_type() != message_20::Type::DC_CableCheckReq) {
            ctx.log("expected DC_CableCheckReq! But code type id: %d", variant->get_type());
            return sa.PASS_ON;
        }

        const auto& req = variant->get<message_20::DC_CableCheckRequest>();

        const auto& res = handle_request(req, ctx.session);

        ctx.respond(res);

        return sa.create_simple<DC_PreCharge>(ctx);
    }

    return sa.PASS_ON;
}

} // namespace iso15118::d20::state
