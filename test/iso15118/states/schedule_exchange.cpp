// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <catch2/catch_test_macros.hpp>

#include <iso15118/detail/d20/state/schedule_exchange.hpp>

using namespace iso15118;

SCENARIO("Schedule Exchange state handling") {

    using Scheduled_ModeReq = message_20::ScheduleExchangeRequest::Scheduled_SEReqControlMode;
    using Scheduled_ModeRes = message_20::ScheduleExchangeResponse::Scheduled_SEResControlMode;

    GIVEN("Bad case - Unknown session") {

        d20::Session session = d20::Session();

        message_20::ScheduleExchangeRequest req;
        req.header.session_id = session.id;
        req.header.timestamp = 1691411798;

        // Todo
        auto& req_out = req.control_mode.emplace<Scheduled_ModeReq>();

        const auto res = d20::state::handle_request(req, d20::Session());

        THEN("ResponseCode: FAILED_UnknownSession, mandatory fields should be set") {
            REQUIRE(res.response_code == message_20::ResponseCode::FAILED_UnknownSession);

            REQUIRE(res.processing == message_20::Processing::Finished);

            REQUIRE(std::holds_alternative<Scheduled_ModeRes>(res.control_mode) == true);
            const auto& res_control_mode = std::get<Scheduled_ModeRes>(res.control_mode);
            REQUIRE(res_control_mode.schedule_tuple.size() == 1);

            const auto& schedule_tuple = res_control_mode.schedule_tuple[0];
            REQUIRE(schedule_tuple.schedule_tuple_id == 0);
            REQUIRE(schedule_tuple.discharging_schedule.has_value() == false);
        }
    }

    GIVEN("Good case - Scheduled Mode") {
    }

    // GIVEN("Bad Case - sequence error") {} // todo(sl): not here

    // GIVEN("Performance Timeout") {} // todo(sl): not here

    // GIVEN("Sequence Timeout") {} // todo(sl): not here
}
