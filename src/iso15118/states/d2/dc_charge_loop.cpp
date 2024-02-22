// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d2/state/dc_charge_loop.hpp>
#include <iso15118/d2/state/dc_welding_detection.hpp>

#include <iso15118/detail/d2/context_helper.hpp>
#include <iso15118/detail/d2/state/dc_charge_loop.hpp>
#include <iso15118/detail/d2/state/power_delivery.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d2::state {

using Scheduled_DC_Req = message_2::DC_ChargeLoopRequest::Scheduled_DC_CLReqControlMode;
using Scheduled_BPT_DC_Req = message_2::DC_ChargeLoopRequest::BPT_Scheduled_DC_CLReqControlMode;
using Dynamic_DC_Req = message_2::DC_ChargeLoopRequest::Dynamic_DC_CLReqControlMode;
using Dynamic_BPT_DC_Req = message_2::DC_ChargeLoopRequest::BPT_Dynamic_DC_CLReqControlMode;

using Scheduled_DC_Res = message_2::DC_ChargeLoopResponse::Scheduled_DC_CLResControlMode;
using Scheduled_BPT_DC_Res = message_2::DC_ChargeLoopResponse::BPT_Scheduled_DC_CLResControlMode;

std::tuple<message_2::DC_ChargeLoopResponse, std::optional<session_2::feedback::DcChargeTarget>>
handle_request(const message_2::DC_ChargeLoopRequest& req, const d2::Session& session, const float present_voltage,
               const float present_current) {

    message_2::DC_ChargeLoopResponse res;
    std::optional<session_2::feedback::DcChargeTarget> charge_target{std::nullopt};

    if (std::holds_alternative<Scheduled_DC_Req>(req.control_mode)) {

        if (session.get_selected_energy_service() != message_2::ServiceCategory::DC) {
            return {response_with_code(res, message_2::ResponseCode::FAILED), charge_target};
        }

        const auto& req_mode = std::get<Scheduled_DC_Req>(req.control_mode);

        charge_target = {
            message_2::from_RationalNumber(req_mode.target_voltage),
            message_2::from_RationalNumber(req_mode.target_current),
        };

        auto& mode = res.control_mode.emplace<Scheduled_DC_Res>();

    } else if (std::holds_alternative<Scheduled_BPT_DC_Req>(req.control_mode)) {

        if (session.get_selected_energy_service() != message_2::ServiceCategory::DC_BPT) {
            return {response_with_code(res, message_2::ResponseCode::FAILED), charge_target};
        }

        const auto& req_mode = std::get<Scheduled_BPT_DC_Req>(req.control_mode);

        charge_target = {
            message_2::from_RationalNumber(req_mode.target_voltage),
            message_2::from_RationalNumber(req_mode.target_current),
        };

        auto& mode = res.control_mode.emplace<Scheduled_BPT_DC_Res>();
    }

    res.present_voltage = iso15118::message_2::from_float(present_voltage);
    res.present_current = iso15118::message_2::from_float(present_current);

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return {response_with_code(res, message_2::ResponseCode::FAILED_UnknownSession), charge_target};
    }

    return {response_with_code(res, message_2::ResponseCode::OK), charge_target};
}

void DC_ChargeLoop::enter() {
    ctx.log.enter_state("DC_ChargeLoop");
}

FsmSimpleState::HandleEventReturnType DC_ChargeLoop::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev == FsmEvent::CONTROL_MESSAGE) {
        const auto control_data = ctx.get_control_event<PresentVoltageCurrent>();
        if (not control_data) {
            // FIXME (aw): error handling
            return sa.HANDLED_INTERNALLY;
        }

        present_voltage = control_data->voltage;
        present_current = control_data->current;

        return sa.HANDLED_INTERNALLY;
    }

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    const auto variant = ctx.get_request();

    if (const auto req = variant->get_if<message_2::PowerDeliveryRequest>()) {
        const auto res = handle_request(*req, ctx.session);

        ctx.respond(res);

        if (res.response_code >= message_2::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        // Reset
        first_entry_in_charge_loop = true;

        // Todo(sl): React properly to Start, Stop, Standby and ScheduleRenegotiation
        if (req->charge_progress == message_2::PowerDeliveryRequest::Progress::Stop) {
            ctx.feedback.signal(session_2::feedback::Signal::CHARGE_LOOP_FINISHED);
            ctx.feedback.signal(session_2::feedback::Signal::DC_OPEN_CONTACTOR);
            return sa.create_simple<DC_WeldingDetection>(ctx);
        }

        return sa.HANDLED_INTERNALLY;
    } else if (const auto req = variant->get_if<message_2::DC_ChargeLoopRequest>()) {
        if (first_entry_in_charge_loop) {
            ctx.feedback.signal(session_2::feedback::Signal::CHARGE_LOOP_STARTED);
            first_entry_in_charge_loop = false;
        }

        const auto [res, charge_target] = handle_request(*req, ctx.session, present_voltage, present_current);

        if (charge_target) {
            ctx.feedback.dc_charge_target(charge_target.value());
        }

        ctx.respond(res);

        if (res.response_code >= message_2::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        return sa.HANDLED_INTERNALLY;
    } else {
        ctx.log("Expected PowerDeliveryReq or DC_ChargeLoopReq! But code type id: %d", variant->get_type());

        // Sequence Error
        const message_2::Type req_type = variant->get_type();
        send_sequence_error(req_type, ctx);

        ctx.session_stopped = true;
        return sa.PASS_ON;
    }
}

} // namespace iso15118::d2::state
