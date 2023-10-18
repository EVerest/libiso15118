// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/dc_pre_charge.hpp>

#include <iso15118/d20/state/power_delivery.hpp>

#include <iso15118/detail/d20/state/dc_pre_charge.hpp>

namespace iso15118::d20::state {

void DC_PreCharge::enter() {
    ctx.log.enter_state("DC_PreCharge");
}

FsmSimpleState::HandleEventReturnType DC_PreCharge::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev == FsmEvent::NEW_V2GTP_MESSAGE) {
        auto variant = ctx.get_request();
        if (variant->get_type() != message_20::Type::DC_PreChargeReq) {
            ctx.log("expected DC_PreChargeReq! But code type id: %d", variant->get_type());
            return sa.PASS_ON;
        }

        const auto& req = variant->get<message_20::DC_PreChargeRequest>();

        const auto& res = handle_request(req, ctx.session);

        ctx.respond(res);

        return sa.create_simple<PowerDelivery>(ctx);
    }

    return sa.PASS_ON;
}

} // namespace iso15118::d20::state
