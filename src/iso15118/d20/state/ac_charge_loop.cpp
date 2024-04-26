// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/ac_charge_loop.hpp>

#include <iso15118/message/ac_charge_loop.hpp>

#include <iso15118/d20/state/power_delivery.hpp>
#include <iso15118/d20/state/session_stop.hpp>
#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/d20/state/power_delivery.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

namespace dt = message_20::datatypes;

using Scheduled_AC_Req = dt::Scheduled_AC_CLReqControlMode;
using Scheduled_BPT_AC_Req = dt::BPT_Scheduled_AC_CLReqControlMode;
using Dynamic_AC_Req = dt::Dynamic_AC_CLReqControlMode;
using Dynamic_BPT_AC_Req = dt::BPT_Dynamic_AC_CLReqControlMode;

using Scheduled_AC_Res = dt::Scheduled_AC_CLResControlMode;
using Scheduled_BPT_AC_Res = dt::BPT_Scheduled_AC_CLResControlMode;
using Dynamic_AC_Res = dt::Dynamic_AC_CLResControlMode;
using Dynamic_BPT_AC_Res = dt::BPT_Dynamic_AC_CLResControlMode;

template <typename In, typename Out> void convert(Out& out, const In& in);

template <> void convert(Scheduled_AC_Res& out, const d20::AcTransferLimits& in) {
    // TODO(ioan, sl): see what to place here
    // out.target_active_power = ;
    // out.target_active_power_L2 = ;
    // out.target_active_power_L3 = ;
    // out.target_reactive_power = ;
    // out.target_reactive_power_L2 = ;
    // out.target_reactive_power_L3 = ;
    out.present_active_power = in.present_active_power;
    out.present_active_power_L2 = in.present_active_power_L2;
    out.present_active_power_L3 = in.present_active_power_L3;
}

template <> void convert(Scheduled_BPT_AC_Res& out, const d20::AcTransferLimits& in) {
    convert(static_cast<Scheduled_AC_Res&>(out), in);
}

template <> void convert(Dynamic_AC_Res& out, const d20::AcTransferLimits& in) {
    // TODO(ioan, sl): see what to place here
    // out.target_active_power = ;
    // out.target_active_power_L2 = ;
    // out.target_active_power_L3 = ;
    // out.target_reactive_power = ;
    // out.target_reactive_power_L2 = ;
    // out.target_reactive_power_L3 = ;
    out.present_active_power = in.present_active_power;
    out.present_active_power_L2 = in.present_active_power_L2;
    out.present_active_power_L3 = in.present_active_power_L3;
}

template <> void convert(Dynamic_BPT_AC_Res& out, const d20::AcTransferLimits& in) {
    convert(static_cast<Dynamic_AC_Res&>(out), in);
}

message_20::AC_ChargeLoopResponse handle_request(const message_20::AC_ChargeLoopRequest& req,
                                                 const d20::Session& session, const AcTransferLimits& ac_limits,
                                                 bool stop, float target_frequency) {

    message_20::AC_ChargeLoopResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, dt::ResponseCode::FAILED_UnknownSession);
    }

    const auto& selected_services = session.get_selected_services();
    const auto selected_control_mode = selected_services.selected_control_mode;
    const auto selected_energy_service = selected_services.selected_energy_service;

    if (std::holds_alternative<Scheduled_AC_Req>(req.control_mode)) {

        // If the ev sends a false control mode or a false energy service other than the previous selected ones, then
        // the charger should terminate the session
        if (selected_control_mode != dt::ControlMode::Scheduled or selected_energy_service != dt::ServiceCategory::AC) {
            return response_with_code(res, dt::ResponseCode::FAILED);
        }

        auto& res_mode = res.control_mode.emplace<Scheduled_AC_Res>();
        convert(res_mode, ac_limits);

    } else if (std::holds_alternative<Scheduled_BPT_AC_Req>(req.control_mode)) {

        // If the ev sends a false control mode or a false energy service other than the previous selected ones, then
        // the charger should terminate the session
        if (selected_control_mode != dt::ControlMode::Scheduled or
            selected_energy_service != dt::ServiceCategory::AC_BPT) {
            return response_with_code(res, dt::ResponseCode::FAILED);
        }

        auto& res_mode = res.control_mode.emplace<Scheduled_BPT_AC_Res>();
        convert(res_mode, ac_limits);

    } else if (std::holds_alternative<Dynamic_AC_Req>(req.control_mode)) {

        // If the ev sends a false control mode or a false energy service other than the previous selected ones, then
        // the charger should terminate the session
        if (selected_control_mode != dt::ControlMode::Dynamic or selected_energy_service != dt::ServiceCategory::AC) {
            return response_with_code(res, dt::ResponseCode::FAILED);
        }

        auto& res_mode = res.control_mode.emplace<Dynamic_AC_Res>();
        convert(res_mode, ac_limits);

    } else if (std::holds_alternative<Dynamic_BPT_AC_Req>(req.control_mode)) {

        // If the ev sends a false control mode or a false energy service other than the previous selected ones, then
        // the charger should terminate the session
        if (selected_control_mode != dt::ControlMode::Dynamic or
            selected_energy_service != dt::ServiceCategory::AC_BPT) {
            return response_with_code(res, dt::ResponseCode::FAILED);
        }

        auto& res_mode = res.control_mode.emplace<Dynamic_BPT_AC_Res>();
        convert(res_mode, ac_limits);
    }

    res.target_frequency = dt::from_float(target_frequency);

    // TODO(sl): Setting EvseStatus, MeterInfo, Receipt, *_limit_achieved

    if (stop) {
        res.status = {0, dt::EvseNotification::Terminate};
    }

    return response_with_code(res, dt::ResponseCode::OK);
}

void AC_ChargeLoop::enter() {
    m_ctx.log.enter_state("AC_ChargeLoop");
}

Result AC_ChargeLoop::feed(Event ev) {

    // TODO(ioan, sl): see if this is required
    if (ev == Event::CONTROL_MESSAGE) {
        if (const auto* control_data = m_ctx.get_control_event<StopCharging>()) {
            stop = *control_data;
        }

        /*
        if (const auto* control_data = m_ctx.get_control_event<PresentVoltageCurrent>()) {
        } else if (const auto* control_data = m_ctx.get_control_event<StopCharging>()) {
        } else if (const auto* control_data = m_ctx.get_control_event<UpdateDynamicModeParameters>()) {
        }
        */

        // Ignore control message
        return {};
    }

    if (ev != Event::V2GTP_MESSAGE) {
        return {};
    }

    const auto variant = m_ctx.pull_request();

    if (const auto req = variant->get_if<message_20::PowerDeliveryRequest>()) {
        const auto res = handle_request(*req, m_ctx.session);

        m_ctx.respond(res);

        if (res.response_code >= dt::ResponseCode::FAILED) {
            m_ctx.session_stopped = true;
            return {};
        }

        // V2G20-1623 -> state machine direct transition (skipped PowerDelivery)
        if (req->charge_progress == dt::Progress::Stop) {
            m_ctx.feedback.signal(session::feedback::Signal::CHARGE_LOOP_FINISHED);
            m_ctx.feedback.signal(session::feedback::Signal::AC_OPEN_CONTACTOR);
            return m_ctx.create_state<SessionStop>();
        }

        return {};
    } else if (const auto req = variant->get_if<message_20::AC_ChargeLoopRequest>()) {
        if (first_entry_in_charge_loop) {
            m_ctx.feedback.signal(session::feedback::Signal::CHARGE_LOOP_STARTED);
            first_entry_in_charge_loop = false;
        }

        // TODO(ioan, sl): see what is required here
        const auto res = handle_request(*req, m_ctx.session, m_ctx.session_config.ac_limits, stop, target_frequency);

        m_ctx.respond(res);

        if (res.response_code >= dt::ResponseCode::FAILED) {
            m_ctx.session_stopped = true;
            return {};
        }

        m_ctx.feedback.ac_charge_loop_req(req->control_mode);
        m_ctx.feedback.ac_charge_loop_req(req->meter_info_requested);
        if (req->display_parameters) {
            m_ctx.feedback.ac_charge_loop_req(*req->display_parameters);
        }

        return {};
    } else {
        m_ctx.log("Expected PowerDeliveryReq or AC_ChargeLoopRequest! But code type id: %d", variant->get_type());

        // Sequence Error
        const message_20::Type req_type = variant->get_type();
        send_sequence_error(req_type, m_ctx);

        m_ctx.session_stopped = true;
        return {};
    }
}

} // namespace iso15118::d20::state
