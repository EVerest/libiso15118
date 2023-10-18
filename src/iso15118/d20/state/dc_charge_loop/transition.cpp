// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/dc_charge_loop.hpp>

#include <iso15118/detail/d20/state/dc_charge_loop.hpp>

namespace iso15118::d20::state {

void DC_ChargeLoop::enter() {
    ctx.log.enter_state("DC_ChargeLoop");
}

FsmSimpleState::HandleEventReturnType DC_ChargeLoop::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev == FsmEvent::NEW_V2GTP_MESSAGE) {
        auto variant = ctx.get_request();
        if (variant->get_type() != message_20::Type::DC_ChargeLoopReq) {
            ctx.log("expected DC_ChargeLoopReq! But code type id: %d", variant->get_type());
            return sa.PASS_ON;
        }

        const auto& req = variant->get<message_20::DC_ChargeLoopRequest>();

        const auto& res = handle_request(req, ctx.session);

        ctx.respond(res);

        // return sa.create_simple<ScheduleExchange>(ctx);
    }

    return sa.PASS_ON;
}

} // namespace iso15118::d20::state
