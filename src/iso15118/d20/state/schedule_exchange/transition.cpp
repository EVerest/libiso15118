// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/schedule_exchange.hpp>

#include <iso15118/d20/state/dc_cable_check.hpp>

#include <iso15118/detail/d20/state/schedule_exchange.hpp>

namespace iso15118::d20::state {

void ScheduleExchange::enter() {
    ctx.log.enter_state("ScheduleExchange");
}

FsmSimpleState::HandleEventReturnType ScheduleExchange::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev == FsmEvent::V2GTP_MESSAGE) {
        auto variant = ctx.get_request();
        if (variant->get_type() != message_20::Type::ScheduleExchangeReq) {
            ctx.log("expected ScheduleExchangeReq! But code type id: %d", variant->get_type());
            return sa.PASS_ON;
        }

        const auto& req = variant->get<message_20::ScheduleExchangeRequest>();

        const auto res = handle_request(req, ctx.session);

        ctx.respond(res);

        return sa.create_simple<DC_CableCheck>(ctx);
    }

    return sa.PASS_ON;
}

} // namespace iso15118::d20::state
