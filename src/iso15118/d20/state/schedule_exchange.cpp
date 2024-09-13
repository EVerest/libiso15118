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

message_20::ScheduleExchangeResponse handle_request(const message_20::ScheduleExchangeRequest& req,
                                                    const d20::Session& session,
                                                    const datatypes::RationalNumber& max_power) {

    message_20::ScheduleExchangeResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, datatypes::ResponseCode::FAILED_UnknownSession);
    }

    // Todo(SL): Publish data from request?

    if (session.get_selected_control_mode() == datatypes::ControlMode::Scheduled &&
        std::holds_alternative<datatypes::Scheduled_SEReqControlMode>(req.control_mode)) {

        auto& control_mode = res.control_mode.emplace<datatypes::Scheduled_SEResControlMode>();

        // Define one minimal default schedule
        // No price schedule, no discharging power schedule
        // Todo(sl): Adding price schedule
        // Todo(sl): Adding discharging schedule
        datatypes::ScheduleTuple schedule;
        schedule.schedule_tuple_id = 1;
        schedule.charging_schedule.power_schedule.time_anchor =
            static_cast<uint64_t>(std::time(nullptr)); // PowerSchedule is now active

        datatypes::PowerScheduleEntry power_schedule;
        power_schedule.power = max_power;
        power_schedule.duration = datatypes::SCHEDULED_POWER_DURATION_S;

        schedule.charging_schedule.power_schedule.entries.push_back(power_schedule);

        control_mode.schedule_tuple.push_back(schedule);

    } else if (session.get_selected_control_mode() == datatypes::ControlMode::Dynamic &&
               std::holds_alternative<datatypes::Dynamic_SEReqControlMode>(req.control_mode)) {

        auto& control_mode = res.control_mode.emplace<datatypes::Dynamic_SEResControlMode>();

    } else {
        logf_error("The control mode of the req message does not match the previously agreed contol mode.");
        return response_with_code(res, datatypes::ResponseCode::FAILED);
    }

    res.processing = datatypes::Processing::Finished;

    return response_with_code(res, datatypes::ResponseCode::OK);
}

void ScheduleExchange::enter() {
    ctx.log.enter_state("ScheduleExchange");
}

FsmSimpleState::HandleEventReturnType ScheduleExchange::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    const auto variant = ctx.pull_request();

    if (const auto req = variant->get_if<message_20::ScheduleExchangeRequest>()) {

        datatypes::RationalNumber max_charge_power = {0, 0};

        const auto selected_energy_service = ctx.session.get_selected_energy_service();

        if (selected_energy_service == datatypes::ServiceCategory::DC or
            selected_energy_service == datatypes::ServiceCategory::DC_BPT) {
            max_charge_power = ctx.session_config.dc_limits.charge_limits.power.max;
        }

        const auto res = handle_request(*req, ctx.session, max_charge_power);

        ctx.respond(res);

        if (res.response_code >= datatypes::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        if (res.processing == datatypes::Processing::Ongoing) {
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
