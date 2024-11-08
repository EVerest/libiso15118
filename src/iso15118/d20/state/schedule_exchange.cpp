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

using ScheduledReqControlMode = message_20::ScheduleExchangeRequest::Scheduled_SEReqControlMode;
using ScheduledResControlMode = message_20::ScheduleExchangeResponse::Scheduled_SEResControlMode;

using DynamicReqControlMode = message_20::ScheduleExchangeRequest::Dynamic_SEReqControlMode;
using DynamicResControlMode = message_20::ScheduleExchangeResponse::Dynamic_SEResControlMode;

namespace {
auto create_default_scheduled_control_mode(const message_20::RationalNumber& max_power) {
    message_20::ScheduleExchangeResponse::ScheduleTuple schedule;
    schedule.schedule_tuple_id = 1;
    schedule.charging_schedule.power_schedule.time_anchor =
        static_cast<uint64_t>(std::time(nullptr)); // PowerSchedule is now active

    message_20::ScheduleExchangeResponse::PowerScheduleEntry power_schedule;
    power_schedule.power = max_power;
    power_schedule.duration = message_20::ScheduleExchangeResponse::SCHEDULED_POWER_DURATION_S;
    schedule.charging_schedule.power_schedule.entries.push_back(power_schedule);

    ScheduledResControlMode scheduled_mode{};

    // Providing no price schedule!
    // NOTE: Agreement on iso15118.elaad.io: [V2G20-2176] is not required and should be ignored.
    scheduled_mode.schedule_tuple = {schedule};
    return scheduled_mode;
}

namespace {
void set_dynamic_parameters_in_res(DynamicResControlMode& res_mode, const UpdateDynamicModeParameters& parameters,
                                   uint64_t header_timestamp) {
    if (parameters.departure_time) {
        const auto departure_time = static_cast<uint64_t>(parameters.departure_time.value());
        if (departure_time > header_timestamp) {
            res_mode.departure_time = static_cast<uint32_t>(departure_time - header_timestamp);
        }
    }
    res_mode.target_soc = parameters.target_soc;
    res_mode.minimum_soc = parameters.min_soc;
}
} // namespace
} // namespace

message_20::ScheduleExchangeResponse handle_request(const message_20::ScheduleExchangeRequest& req,
                                                    const d20::Session& session,
                                                    const message_20::RationalNumber& max_power,
                                                    const UpdateDynamicModeParameters& dynamic_parameters) {

    message_20::ScheduleExchangeResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    // Todo(SL): Publish data from request?

    if (session.get_selected_control_mode() == message_20::ControlMode::Scheduled &&
        std::holds_alternative<ScheduledReqControlMode>(req.control_mode)) {

        res.control_mode.emplace<ScheduledResControlMode>(create_default_scheduled_control_mode(max_power));

        // TODO(sl): Adding price schedule
        // TODO(sl): Adding discharging schedule

    } else if (session.get_selected_control_mode() == message_20::ControlMode::Dynamic &&
               std::holds_alternative<DynamicReqControlMode>(req.control_mode)) {

        // TODO(sl): Publish req dynamic mode parameters
        auto& mode = res.control_mode.emplace<DynamicResControlMode>();

        if (session.get_selected_mobility_needs_mode() == message_20::MobilityNeedsMode::ProvidedBySecc) {
            set_dynamic_parameters_in_res(mode, dynamic_parameters, res.header.timestamp);
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

        // TODO(sl): Not sure if the data comes here just in time?
        if (const auto* control_data = ctx.get_control_event<UpdateDynamicModeParameters>()) {
            dynamic_parameters = *control_data;
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

        const auto res = handle_request(*req, ctx.session, max_charge_power, dynamic_parameters);

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
