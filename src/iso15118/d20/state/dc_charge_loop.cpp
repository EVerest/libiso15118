// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/dc_charge_loop.hpp>
#include <iso15118/d20/state/dc_welding_detection.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/d20/state/dc_charge_loop.hpp>
#include <iso15118/detail/d20/state/power_delivery.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

using Scheduled_DC_Req = message_20::DC_ChargeLoopRequest::Scheduled_DC_CLReqControlMode;
using Scheduled_BPT_DC_Req = message_20::DC_ChargeLoopRequest::BPT_Scheduled_DC_CLReqControlMode;
using Dynamic_DC_Req = message_20::DC_ChargeLoopRequest::Dynamic_DC_CLReqControlMode;
using Dynamic_BPT_DC_Req = message_20::DC_ChargeLoopRequest::BPT_Dynamic_DC_CLReqControlMode;

using Scheduled_DC_Res = message_20::DC_ChargeLoopResponse::Scheduled_DC_CLResControlMode;
using Scheduled_BPT_DC_Res = message_20::DC_ChargeLoopResponse::BPT_Scheduled_DC_CLResControlMode;
using Dynamic_DC_Res = message_20::DC_ChargeLoopResponse::Dynamic_DC_CLResControlMode;
using Dynamic_BPT_DC_Res = message_20::DC_ChargeLoopResponse::BPT_Dynamic_DC_CLResControlMode;

template <typename In, typename Out> void convert(Out& out, const In& in);

template <> void convert(Scheduled_DC_Res& out, const d20::DcTransferLimits& in) {
    out.max_charge_power = in.charge_limits.power.max;
    out.min_charge_power = in.charge_limits.power.min;
    out.max_charge_current = in.charge_limits.current.max;
    out.max_voltage = in.voltage.max;
}

template <> void convert(Scheduled_BPT_DC_Res& out, const d20::DcTransferLimits& in) {
    out.max_charge_power = in.charge_limits.power.max;
    out.min_charge_power = in.charge_limits.power.min;
    out.max_charge_current = in.charge_limits.current.max;
    out.max_voltage = in.voltage.max;
    out.min_voltage = in.voltage.min;

    if (in.discharge_limits.has_value()) {
        auto& discharge_limits = in.discharge_limits.value();
        out.max_discharge_power = discharge_limits.power.max;
        out.min_discharge_power = discharge_limits.power.min;
        out.max_discharge_current = discharge_limits.current.max;
    }
}

template <> void convert(Dynamic_DC_Res& out, const d20::DcTransferLimits& in) {
    out.max_charge_power = in.charge_limits.power.max;
    out.min_charge_power = in.charge_limits.power.min;
    out.max_charge_current = in.charge_limits.current.max;
    out.max_voltage = in.voltage.max;

    // TODO(sl): Check departure_time, minimum_soc, target_soc, ack_max_delay
}

template <> void convert(Dynamic_BPT_DC_Res& out, const d20::DcTransferLimits& in) {
    out.max_charge_power = in.charge_limits.power.max;
    out.min_charge_power = in.charge_limits.power.min;
    out.max_charge_current = in.charge_limits.current.max;
    out.max_voltage = in.voltage.max;
    out.min_voltage = in.voltage.min;

    // TODO(sl): Check departure_time, minimum_soc, target_soc, ack_max_delay

    if (in.discharge_limits.has_value()) {
        auto& discharge_limits = in.discharge_limits.value();
        out.max_discharge_power = discharge_limits.power.max;
        out.min_discharge_power = discharge_limits.power.min;
        out.max_discharge_current = discharge_limits.current.max;
    }
}

// TODO(sl): Maybe refactoring if other files needs this define
#define RATIONAL_NUMBER_TO_FLOAT_IF_USED(out, in)                                                                      \
    if (in) {                                                                                                          \
        out = message_20::from_RationalNumber(in.value());                                                             \
    }

template <> void convert(session::feedback::DcChargeScheduledMode& out, const Scheduled_DC_Req& in) {
    out.target_current = message_20::from_RationalNumber(in.target_current);
    out.target_voltage = message_20::from_RationalNumber(in.target_voltage);

    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.target_energy_request, in.target_energy_request);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.max_energy_request, in.max_energy_request);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.min_energy_request, in.min_energy_request);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.max_charge_power, in.max_charge_power);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.min_charge_power, in.min_charge_power);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.max_charge_current, in.max_charge_current);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.max_voltage, in.max_voltage);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.min_voltage, in.min_voltage);
}

template <> void convert(session::feedback::DcChargeScheduledMode& out, const Scheduled_BPT_DC_Req& in) {
    out.target_current = message_20::from_RationalNumber(in.target_current);
    out.target_voltage = message_20::from_RationalNumber(in.target_voltage);

    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.target_energy_request, in.target_energy_request);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.max_energy_request, in.max_energy_request);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.min_energy_request, in.min_energy_request);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.max_charge_power, in.max_charge_power);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.min_charge_power, in.min_charge_power);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.max_charge_current, in.max_charge_current);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.max_voltage, in.max_voltage);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.min_voltage, in.min_voltage);

    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.max_discharge_power, in.max_discharge_power);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.min_discharge_power, in.min_discharge_power);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.max_discharge_current, in.max_discharge_current);
}

template <> void convert(session::feedback::DcChargeDynamicMode& out, const Dynamic_DC_Req& in) {
    out.departure_time = in.departure_time;
    out.target_energy_request = message_20::from_RationalNumber(in.target_energy_request);
    out.max_energy_request = message_20::from_RationalNumber(in.max_energy_request);
    out.min_energy_request = message_20::from_RationalNumber(in.min_energy_request);
    out.max_charge_power = message_20::from_RationalNumber(in.max_charge_power);
    out.min_charge_power = message_20::from_RationalNumber(in.min_charge_power);
    out.max_charge_current = message_20::from_RationalNumber(in.max_charge_current);
    out.max_voltage = message_20::from_RationalNumber(in.max_voltage);
    out.min_voltage = message_20::from_RationalNumber(in.min_voltage);
}

template <> void convert(session::feedback::DcChargeDynamicMode& out, const Dynamic_BPT_DC_Req& in) {
    out.departure_time = in.departure_time;
    out.target_energy_request = message_20::from_RationalNumber(in.target_energy_request);
    out.max_energy_request = message_20::from_RationalNumber(in.max_energy_request);
    out.min_energy_request = message_20::from_RationalNumber(in.min_energy_request);
    out.max_charge_power = message_20::from_RationalNumber(in.max_charge_power);
    out.min_charge_power = message_20::from_RationalNumber(in.min_charge_power);
    out.max_charge_current = message_20::from_RationalNumber(in.max_charge_current);
    out.max_voltage = message_20::from_RationalNumber(in.max_voltage);
    out.min_voltage = message_20::from_RationalNumber(in.min_voltage);

    out.max_discharge_power = message_20::from_RationalNumber(in.max_discharge_power);
    out.min_discharge_power = message_20::from_RationalNumber(in.min_discharge_power);
    out.max_discharge_current = message_20::from_RationalNumber(in.max_discharge_current);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.max_v2x_energy_request, in.min_v2x_energy_request);
    RATIONAL_NUMBER_TO_FLOAT_IF_USED(out.min_v2x_energy_request, in.min_v2x_energy_request);
}

static auto fill_parameters(const message_20::DisplayParameters& req_parameters) {
    auto parameters = session::feedback::DisplayParameters{};

    parameters.present_soc = req_parameters.present_soc;
    parameters.minimum_soc = req_parameters.min_soc;
    parameters.target_soc = req_parameters.target_soc;
    parameters.maximum_soc = req_parameters.max_soc;
    parameters.remaining_time_to_minimum_soc = req_parameters.remaining_time_to_min_soc;
    parameters.remaining_time_to_target_soc = req_parameters.remaining_time_to_target_soc;
    parameters.remaining_time_to_maximum_soc = req_parameters.remaining_time_to_max_soc;
    if (req_parameters.battery_energy_capacity) {
        parameters.battery_energy_capacity = message_20::from_RationalNumber(*req_parameters.battery_energy_capacity);
    }
    parameters.inlet_hot = req_parameters.inlet_hot;

    return parameters;
}

std::tuple<message_20::DC_ChargeLoopResponse, EvFeedbackControlMode>
handle_request(const message_20::DC_ChargeLoopRequest& req, const d20::Session& session, const float present_voltage,
               const float present_current, const bool stop, const DcTransferLimits& dc_limits) {

    message_20::DC_ChargeLoopResponse res;
    EvFeedbackControlMode ev_feedback_control_mode{};

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return {response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession), ev_feedback_control_mode};
    }

    if (std::holds_alternative<Scheduled_DC_Req>(req.control_mode)) {

        if (session.get_selected_energy_service() != message_20::ServiceCategory::DC) {
            return {response_with_code(res, message_20::ResponseCode::FAILED), ev_feedback_control_mode};
        }

        auto& mode = res.control_mode.emplace<Scheduled_DC_Res>();
        convert(mode, dc_limits);

        const auto& req_mode = std::get<Scheduled_DC_Req>(req.control_mode);

        auto& scheduled_values = ev_feedback_control_mode.emplace<session::feedback::DcChargeScheduledMode>();
        convert(scheduled_values, req_mode);

    } else if (std::holds_alternative<Scheduled_BPT_DC_Req>(req.control_mode)) {

        if (session.get_selected_energy_service() != message_20::ServiceCategory::DC_BPT) {
            return {response_with_code(res, message_20::ResponseCode::FAILED), ev_feedback_control_mode};
        }

        if (not dc_limits.discharge_limits.has_value()) {
            logf_error("Transfer mode is BPT, but only dc limits without discharge limits are provided!");
            return {response_with_code(res, message_20::ResponseCode::FAILED), ev_feedback_control_mode};
        }

        auto& mode = res.control_mode.emplace<Scheduled_BPT_DC_Res>();
        convert(mode, dc_limits);

        const auto& req_mode = std::get<Scheduled_BPT_DC_Req>(req.control_mode);
        auto& scheduled_values = ev_feedback_control_mode.emplace<session::feedback::DcChargeScheduledMode>();
        convert(scheduled_values, req_mode);

    } else if (std::holds_alternative<Dynamic_DC_Req>(req.control_mode)) {
        if (session.get_selected_energy_service() != message_20::ServiceCategory::DC) {
            return {response_with_code(res, message_20::ResponseCode::FAILED), ev_feedback_control_mode};
        }

        auto& mode = res.control_mode.emplace<Dynamic_DC_Res>();
        convert(mode, dc_limits);

        const auto& req_mode = std::get<Dynamic_DC_Req>(req.control_mode);
        auto& dynamic_values = ev_feedback_control_mode.emplace<session::feedback::DcChargeDynamicMode>();
        convert(dynamic_values, req_mode);

    } else if (std::holds_alternative<Dynamic_BPT_DC_Req>(req.control_mode)) {

        if (session.get_selected_energy_service() != message_20::ServiceCategory::DC_BPT) {
            return {response_with_code(res, message_20::ResponseCode::FAILED), ev_feedback_control_mode};
        }

        if (not dc_limits.discharge_limits.has_value()) {
            logf_error("Transfer mode is BPT, but only dc limits without discharge limits are provided!");
            return {response_with_code(res, message_20::ResponseCode::FAILED), ev_feedback_control_mode};
        }

        auto& mode = res.control_mode.emplace<Dynamic_BPT_DC_Res>();
        convert(mode, dc_limits);

        const auto& req_mode = std::get<Dynamic_DC_Req>(req.control_mode);
        auto& dynamic_values = ev_feedback_control_mode.emplace<session::feedback::DcChargeDynamicMode>();
        convert(dynamic_values, req_mode);
    }

    res.present_voltage = iso15118::message_20::from_float(present_voltage);
    res.present_current = iso15118::message_20::from_float(present_current);

    // TODO(sl): Setting EvseStatus, MeterInfo, Receipt, *_limit_achieved

    if (stop) {
        res.status = {0, iso15118::message_20::EvseNotification::Terminate};
    }

    return {response_with_code(res, message_20::ResponseCode::OK), ev_feedback_control_mode};
}

void DC_ChargeLoop::enter() {
    ctx.log.enter_state("DC_ChargeLoop");
}

FsmSimpleState::HandleEventReturnType DC_ChargeLoop::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev == FsmEvent::CONTROL_MESSAGE) {

        if (const auto control_data = ctx.get_control_event<PresentVoltageCurrent>()) {
            present_voltage = control_data->voltage;
            present_current = control_data->current;
        } else if (const auto control_data = ctx.get_control_event<StopCharging>()) {
            stop = *control_data;
        }

        // Ignore control message
        return sa.HANDLED_INTERNALLY;
    }

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    const auto variant = ctx.pull_request();

    if (const auto req = variant->get_if<message_20::PowerDeliveryRequest>()) {
        const auto res = handle_request(*req, ctx.session);

        ctx.respond(res);

        if (res.response_code >= message_20::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        // Reset
        first_entry_in_charge_loop = true;

        // Todo(sl): React properly to Start, Stop, Standby and ScheduleRenegotiation
        if (req->charge_progress == message_20::PowerDeliveryRequest::Progress::Stop) {
            ctx.feedback.signal(session::feedback::Signal::CHARGE_LOOP_FINISHED);
            ctx.feedback.signal(session::feedback::Signal::DC_OPEN_CONTACTOR);
            return sa.create_simple<DC_WeldingDetection>(ctx);
        }

        return sa.HANDLED_INTERNALLY;
    } else if (const auto req = variant->get_if<message_20::DC_ChargeLoopRequest>()) {
        if (first_entry_in_charge_loop) {
            ctx.feedback.signal(session::feedback::Signal::CHARGE_LOOP_STARTED);
            first_entry_in_charge_loop = false;
        }

        const auto [res, ev_feedback_control_mode] =
            handle_request(*req, ctx.session, present_voltage, present_current, stop, ctx.session_config.dc_limits);

        ctx.respond(res);

        if (std::holds_alternative<session::feedback::DcChargeScheduledMode>(ev_feedback_control_mode)) {
            const auto& scheduled_values = std::get<session::feedback::DcChargeScheduledMode>(ev_feedback_control_mode);
            ctx.feedback.dc_charge_scheduled_mode(scheduled_values);
        } else if (std::holds_alternative<session::feedback::DcChargeDynamicMode>(ev_feedback_control_mode)) {
            const auto& dynamic_values = std::get<session::feedback::DcChargeDynamicMode>(ev_feedback_control_mode);
            ctx.feedback.dc_charge_dynamic_mode(dynamic_values);
        }

        if (req->display_parameters.has_value()) {
            const auto feedback_parameters = fill_parameters(*req->display_parameters);
            ctx.feedback.display_parameters(feedback_parameters);
        }

        // TODO(sl): Publish present_voltage, meter_info_requested,
        // const auto present_voltage = message_20::from_RationalNumber(req.present_voltage);

        if (res.response_code >= message_20::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        return sa.HANDLED_INTERNALLY;
    } else {
        ctx.log("Expected PowerDeliveryReq or DC_ChargeLoopReq! But code type id: %d", variant->get_type());

        // Sequence Error
        const message_20::Type req_type = variant->get_type();
        send_sequence_error(req_type, ctx);

        ctx.session_stopped = true;
        return sa.PASS_ON;
    }
}

} // namespace iso15118::d20::state
