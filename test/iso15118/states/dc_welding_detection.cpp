// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <catch2/catch_test_macros.hpp>

#include <iso15118/detail/d20/state/dc_welding_detection.hpp>

using namespace iso15118;

SCENARIO("DC Welding Detection state handling") {

    GIVEN("Bad case - Unknown session") {

        auto session = d20::Session();

        message_20::DC_WeldingDetectionRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.processing = message_20::Processing::Ongoing;

        const float present_voltage = 0.1;

        const auto res = d20::state::handle_request(req, d20::Session(), present_voltage);

        THEN("ResponseCode: FAILED_UnknownSession, mandatory fields should be set") {
            REQUIRE(res.response_code == message_20::ResponseCode::FAILED_UnknownSession);
            REQUIRE(res.present_voltage.value == 0);
            REQUIRE(res.present_voltage.exponent == 0);
        }
    }

    GIVEN("Good Case") {
        
        auto session = d20::Session();

        message_20::DC_WeldingDetectionRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.processing = message_20::Processing::Ongoing;

        const float present_voltage = 200;

        const auto res = d20::state::handle_request(req, session, present_voltage);

        THEN("ResponseCode: OK, present_voltage should be 200V") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);
            REQUIRE(res.present_voltage.value == 200);
            REQUIRE(res.present_voltage.exponent == 0);
        }
    }

    // GIVEN("Bad case - State B was not measuered -> FAILED") {} // todo(sl): check evse_manager?

    // GIVEN("Bad Case - sequence error") {} // todo(sl): not here

    // GIVEN("Bad Case - Performance Timeout") {} // todo(sl): not here

    // GIVEN("Bad Case - Sequence Timeout") {} // todo(sl): not here
}