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

    if (ev == FsmEvent::CONTROL_MESSAGE) {
        // it works but ugly
        if (ctx.current_control_event.has_value()) {
            if (std::holds_alternative<iso15118::d20::CableCheckFinished>(ctx.current_control_event.value())) {
                const auto& control_event =
                    std::get<iso15118::d20::CableCheckFinished>(ctx.current_control_event.value());
                if (control_event) {
                    cable_check_done = true;
                } else {
                    cable_check_done = false;
                }
            }
        }
        return sa.HANDLED_INTERNALLY;
    }

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    auto variant = ctx.get_request();

    if (variant->get_type() != message_20::Type::DC_CableCheckReq) {
        ctx.log("expected DC_CableCheckReq! But code type id: %d", variant->get_type());
        return sa.PASS_ON;
    }

    if (not cable_check_initiated) {
        ctx.feedback.signal(session::feedback::Signal::START_CABLE_CHECK);
        cable_check_initiated = true;
    }

    const auto& req = variant->get<message_20::DC_CableCheckRequest>();

    auto res = handle_request(req, ctx.session, cable_check_done);

    ctx.respond(res);

    if (cable_check_done) {
        return sa.create_simple<DC_PreCharge>(ctx);
    } else {
        return sa.HANDLED_INTERNALLY;
    }
}

} // namespace iso15118::d20::state
