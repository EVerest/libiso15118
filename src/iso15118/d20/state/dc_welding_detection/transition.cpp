// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/dc_welding_detection.hpp>

#include <iso15118/d20/state/session_stop.hpp>

#include <iso15118/detail/d20/state/dc_welding_detection.hpp>

namespace iso15118::d20::state {

void DC_WeldingDetection::enter() {
    ctx.log.enter_state("DC_WeldingDetection");
}

FsmSimpleState::HandleEventReturnType DC_WeldingDetection::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev == FsmEvent::CONTROL_MESSAGE) {
        const auto control_data = ctx.get_control_event<PresentVoltageCurrent>();
        if (not control_data) {
            // FIXME (aw): error handling
            return sa.HANDLED_INTERNALLY;
        }

        present_voltage = control_data->voltage;

        return sa.HANDLED_INTERNALLY;
    }

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    auto variant = ctx.get_request();
    if (variant->get_type() != message_20::Type::DC_WeldingDetectionReq) {
        ctx.log("expected DC_WeldingDetection! But code type id: %d", variant->get_type());
        return sa.PASS_ON;
    }

    const auto& req = variant->get<message_20::DC_WeldingDetectionRequest>();

    const auto res = handle_request(req, ctx.session, present_voltage);

    ctx.respond(res);

    if (req.processing == message_20::Processing::Ongoing) {
        return sa.HANDLED_INTERNALLY;
    }

    return sa.create_simple<SessionStop>(ctx);
}

} // namespace iso15118::d20::state
