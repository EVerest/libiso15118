// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d2/state/dc_welding_detection.hpp>
#include <iso15118/d2/state/session_stop.hpp>

#include <iso15118/detail/d2/context_helper.hpp>
#include <iso15118/detail/d2/state/dc_welding_detection.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d2::state {

message_2::DC_WeldingDetectionResponse handle_request(const message_2::DC_WeldingDetectionRequest& req,
                                                       const d2::Session& session, const float present_voltage) {
    message_2::DC_WeldingDetectionResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_2::ResponseCode::FAILED_UnknownSession);
    }

    res.present_voltage = message_2::from_float(present_voltage);

    return response_with_code(res, message_2::ResponseCode::OK);
}

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

    const auto variant = ctx.get_request();

    if (const auto req = variant->get_if<message_2::DC_WeldingDetectionRequest>()) {
        const auto res = handle_request(*req, ctx.session, present_voltage);

        ctx.respond(res);

        if (res.response_code >= message_2::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        if (req->processing == message_2::Processing::Ongoing) {
            return sa.HANDLED_INTERNALLY;
        }

        return sa.create_simple<SessionStop>(ctx);
    } else {
        ctx.log("expected DC_WeldingDetection! But code type id: %d", variant->get_type());

        // Sequence Error
        const message_2::Type req_type = variant->get_type();
        send_sequence_error(req_type, ctx);

        ctx.session_stopped = true;
        return sa.PASS_ON;
    }
}

} // namespace iso15118::d2::state
