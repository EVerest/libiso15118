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

template <typename Out> void convert(Out& out, const d20::DcTransferLimits& in) {
    out.max_charge_power = in.charge_limits.power.max;
    out.min_charge_power = in.charge_limits.power.min;
    out.max_charge_current = in.charge_limits.current.max;
    out.max_voltage = in.voltage.max;

    if constexpr (std::is_same_v<Out, Scheduled_BPT_DC_Res> || std::is_same_v<Out, Dynamic_BPT_DC_Res>) {
        out.min_voltage = in.voltage.min;

        if (not in.discharge_limits) {
            return;
        }
        auto& discharge_limits = in.discharge_limits.value();
        out.max_discharge_power = discharge_limits.power.max;
        out.min_discharge_power = discharge_limits.power.min;
        out.max_discharge_current = discharge_limits.current.max;
    }
}

namespace {
template <typename T>
void set_dynamic_parameters_in_res(T& res_mode, const UpdateDynamicModeParameters& parameters,
                                   uint64_t header_timestamp) {
    if (parameters.departure_time) {
        const auto departure_time = static_cast<uint64_t>(parameters.departure_time.value());
        if (departure_time > header_timestamp) {
            res_mode.departure_time = static_cast<uint32_t>(departure_time - header_timestamp);
        }
    }
    res_mode.target_soc = parameters.target_soc;
    res_mode.minimum_soc = parameters.min_soc;
    res_mode.ack_max_delay = 30; // TODO(sl) what to send here and define 30 seconds as const
}
} // namespace

message_20::DC_ChargeLoopResponse handle_request(const message_20::DC_ChargeLoopRequest& req,
                                                 const d20::Session& session, const float present_voltage,
                                                 const float present_current, const bool stop,
                                                 const DcTransferLimits& dc_limits,
                                                 const UpdateDynamicModeParameters& dynamic_parameters) {

    message_20::DC_ChargeLoopResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    const auto selected_services = session.get_selected_services();
    const auto selected_control_mode = selected_services.selected_control_mode;
    const auto selected_energy_service = selected_services.selected_energy_service;
    const auto selected_mobility_needs_mode = selected_services.selected_mobility_needs_mode;

    if (std::holds_alternative<Scheduled_DC_Req>(req.control_mode)) {

        // If the ev sends a false control mode or a false energy service other than the previous selected ones, then
        // the charger should terminate the session
        if (selected_control_mode != message_20::ControlMode::Scheduled or
            selected_energy_service != message_20::ServiceCategory::DC) {
            return response_with_code(res, message_20::ResponseCode::FAILED);
        }

        auto& res_mode = res.control_mode.emplace<Scheduled_DC_Res>();
        convert(res_mode, dc_limits);

    } else if (std::holds_alternative<Scheduled_BPT_DC_Req>(req.control_mode)) {

        // If the ev sends a false control mode or a false energy service other than the previous selected ones, then
        // the charger should terminate the session
        if (selected_control_mode != message_20::ControlMode::Scheduled or
            selected_energy_service != message_20::ServiceCategory::DC_BPT) {
            return response_with_code(res, message_20::ResponseCode::FAILED);
        }

        if (not dc_limits.discharge_limits.has_value()) {
            logf_error("Transfer mode is BPT, but only dc limits without discharge limits are provided!");
            return response_with_code(res, message_20::ResponseCode::FAILED);
        }

        auto& res_mode = res.control_mode.emplace<Scheduled_BPT_DC_Res>();
        convert(res_mode, dc_limits);

    } else if (std::holds_alternative<Dynamic_DC_Req>(req.control_mode)) {

        // If the ev sends a false control mode or a false energy service other than the previous selected ones, then
        // the charger should terminate the session
        if (selected_control_mode != message_20::ControlMode::Dynamic or
            selected_energy_service != message_20::ServiceCategory::DC) {
            return response_with_code(res, message_20::ResponseCode::FAILED);
        }

        auto& res_mode = res.control_mode.emplace<Dynamic_DC_Res>();
        convert(res_mode, dc_limits);

        if (selected_mobility_needs_mode == message_20::MobilityNeedsMode::ProvidedBySecc) {
            set_dynamic_parameters_in_res(res_mode, dynamic_parameters, res.header.timestamp);
        }

    } else if (std::holds_alternative<Dynamic_BPT_DC_Req>(req.control_mode)) {

        // If the ev sends a false control mode or a false energy service other than the previous selected ones, then
        // the charger should terminate the session
        if (selected_control_mode != message_20::ControlMode::Dynamic or
            selected_energy_service != message_20::ServiceCategory::DC_BPT) {
            return response_with_code(res, message_20::ResponseCode::FAILED);
        }

        if (not dc_limits.discharge_limits.has_value()) {
            logf_error("Transfer mode is BPT, but only dc limits without discharge limits are provided!");
            return response_with_code(res, message_20::ResponseCode::FAILED);
        }

        auto& res_mode = res.control_mode.emplace<Dynamic_BPT_DC_Res>();
        convert(res_mode, dc_limits);

        if (selected_mobility_needs_mode == message_20::MobilityNeedsMode::ProvidedBySecc) {
            set_dynamic_parameters_in_res(res_mode, dynamic_parameters, res.header.timestamp);
        }
    }

    res.present_voltage = iso15118::message_20::from_float(present_voltage);
    res.present_current = iso15118::message_20::from_float(present_current);

    // TODO(sl): Setting EvseStatus, MeterInfo, Receipt, *_limit_achieved

    if (stop) {
        res.status = {0, iso15118::message_20::EvseNotification::Terminate};
    }

    return response_with_code(res, message_20::ResponseCode::OK);
}

void DC_ChargeLoop::enter() {
    ctx.log.enter_state("DC_ChargeLoop");
}

FsmSimpleState::HandleEventReturnType DC_ChargeLoop::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev == FsmEvent::CONTROL_MESSAGE) {

        if (const auto* control_data = ctx.get_control_event<PresentVoltageCurrent>()) {
            present_voltage = control_data->voltage;
            present_current = control_data->current;
        } else if (const auto* control_data = ctx.get_control_event<StopCharging>()) {
            stop = *control_data;
        } else if (const auto* control_data = ctx.get_control_event<UpdateDynamicModeParameters>()) {
            dynamic_parameters = *control_data;
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

        const auto res = handle_request(*req, ctx.session, present_voltage, present_current, stop,
                                        ctx.session_config.dc_limits, dynamic_parameters);

        ctx.respond(res);

        if (res.response_code >= message_20::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        ctx.feedback.dc_charge_loop_req(req->control_mode);
        ctx.feedback.dc_charge_loop_req(req->present_voltage);
        ctx.feedback.dc_charge_loop_req(req->meter_info_requested);
        if (req->display_parameters) {
            ctx.feedback.dc_charge_loop_req(*req->display_parameters);
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
