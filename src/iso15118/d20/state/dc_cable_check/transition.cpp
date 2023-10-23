// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/dc_cable_check.hpp>

#include <iso15118/d20/state/dc_pre_charge.hpp>

#include <iso15118/detail/d20/state/dc_cable_check.hpp>

#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

void DC_CableCheck::enter() {
    ctx.log.enter_state("DC_CableCheck");
}

FsmSimpleState::HandleEventReturnType DC_CableCheck::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    // TODO(SL): ugly
    static bool first_entry_in_cable_check = true;

    auto variant = ctx.get_request();

    if (variant->get_type() != message_20::Type::DC_CableCheckReq) {
        ctx.log("expected DC_CableCheckReq! But code type id: %d", variant->get_type());
        return sa.PASS_ON;
    }

    if (first_entry_in_cable_check) {
        signal_start_cable_check();
        first_entry_in_cable_check = false;
    }

    const auto& req = variant->get<message_20::DC_CableCheckRequest>();

    const auto& res = handle_request(req, ctx.session);

    ctx.respond(res);

    if (res.processing == message_20::Processing::Finished) {
        first_entry_in_cable_check = true; // Reset
        return sa.create_simple<DC_PreCharge>(ctx);
    } else {
        return sa.HANDLED_INTERNALLY;
    }
}

} // namespace iso15118::d20::state
