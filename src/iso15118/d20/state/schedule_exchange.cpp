// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <ctime>

#include <iso15118/d20/state/dc_cable_check.hpp>
#include <iso15118/d20/state/schedule_exchange.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/d20/state/schedule_exchange.hpp>
#include <iso15118/detail/d20/state/session_stop.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

message_20::ScheduleExchangeResponse
handle_request(const message_20::ScheduleExchangeRequest& req, const d20::Session& session,
               const message_20::RationalNumber& max_power, std::optional<std::time_t> new_departure_time,
               std::optional<uint8_t> new_target_soc, std::optional<uint8_t> new_min_soc) {

    message_20::ScheduleExchangeResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    // Todo(SL): Publish data from request?

    if (session.get_selected_control_mode() == message_20::ControlMode::Scheduled &&
        std::holds_alternative<message_20::ScheduleExchangeRequest::Scheduled_SEReqControlMode>(req.control_mode)) {
        auto& control_mode =
            res.control_mode.emplace<message_20::ScheduleExchangeResponse::Scheduled_SEResControlMode>();

        message_20::ScheduleExchangeResponse::ScheduleTuple schedule;
        schedule.schedule_tuple_id = 1;
        schedule.charging_schedule.power_schedule.time_anchor =
            static_cast<uint64_t>(std::time(nullptr)); // PowerSchedule is now active

        message_20::ScheduleExchangeResponse::PowerScheduleEntry power_schedule;
        power_schedule.power = max_power;
        power_schedule.duration = message_20::ScheduleExchangeResponse::SCHEDULED_POWER_DURATION_S;
        schedule.charging_schedule.power_schedule.entries.push_back(power_schedule);

        // Providing no price schedule!
        // NOTE: Agreement on iso15118.elaad.io: [V2G20-2176] is not required and should be ignored.
        control_mode.schedule_tuple.push_back(schedule);

        // TODO(sl): Adding price schedule
        // TODO(sl): Adding discharging schedule

    } else if (session.get_selected_control_mode() == message_20::ControlMode::Dynamic &&
               std::holds_alternative<message_20::ScheduleExchangeRequest::Dynamic_SEReqControlMode>(
                   req.control_mode)) {

        // TODO(sl): Publish req dynamic mode parameters
        auto& mode = res.control_mode.emplace<message_20::ScheduleExchangeResponse::Dynamic_SEResControlMode>();

        if (session.get_selected_mobility_needs_mode() == message_20::MobilityNeedsMode::ProvidedBySecc) {
            if (new_departure_time.has_value()) {
                const auto departure_time = static_cast<uint64_t>(new_departure_time.value());
                if (departure_time > res.header.timestamp) {
                    mode.departure_time = static_cast<uint32_t>(departure_time - res.header.timestamp);
                }
            }
            mode.target_soc = new_target_soc;
            mode.minimum_soc = new_min_soc;
        }

    } else {
        logf_error("The control mode of the req message does not match the previously agreed contol mode.");
        return response_with_code(res, message_20::ResponseCode::FAILED);
    }

    res.processing = message_20::Processing::Finished;

    return response_with_code(res, message_20::ResponseCode::OK);
}

void ScheduleExchange::enter() {
    ctx.log.enter_state("ScheduleExchange");
}

FsmSimpleState::HandleEventReturnType ScheduleExchange::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev == FsmEvent::CONTROL_MESSAGE) {

        if (const auto control_data = ctx.get_control_event<UpdateDynamicModeParameters>()) {
            new_departure_time = *control_data->departure_time;
            new_target_soc = *control_data->target_soc;
            new_min_soc = *control_data->min_soc;
        }

        // Ignore control message
        return sa.HANDLED_INTERNALLY;
    }

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    const auto variant = ctx.pull_request();

    if (const auto req = variant->get_if<message_20::ScheduleExchangeRequest>()) {

        message_20::RationalNumber max_charge_power = {0, 0};

        const auto selected_energy_service = ctx.session.get_selected_energy_service();

        if (selected_energy_service == message_20::ServiceCategory::DC or
            selected_energy_service == message_20::ServiceCategory::DC_BPT) {
            max_charge_power = ctx.session_config.dc_limits.charge_limits.power.max;
        }

        const auto res =
            handle_request(*req, ctx.session, max_charge_power, new_departure_time, new_target_soc, new_min_soc);

        ctx.respond(res);

        if (res.response_code >= message_20::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        if (res.processing == message_20::Processing::Ongoing) {
            return sa.HANDLED_INTERNALLY;
        }

        return sa.create_simple<DC_CableCheck>(ctx);
    } else if (const auto req = variant->get_if<message_20::SessionStopRequest>()) {
        const auto res = handle_request(*req, ctx.session);

        ctx.respond(res);
        ctx.session_stopped = true;

        return sa.PASS_ON;
    } else {
        ctx.log("expected ScheduleExchangeReq! But code type id: %d", variant->get_type());

        // Sequence Error
        const message_20::Type req_type = variant->get_type();
        send_sequence_error(req_type, ctx);

        ctx.session_stopped = true;
        return sa.PASS_ON;
    }
}

} // namespace iso15118::d20::state
