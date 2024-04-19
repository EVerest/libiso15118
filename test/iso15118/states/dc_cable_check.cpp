// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <catch2/catch_test_macros.hpp>

#include <iso15118/detail/d20/state/dc_cable_check.hpp>

using namespace iso15118;

SCENARIO("DC cable check state handling") {
    GIVEN("Bad case - Unknown session") {

        d20::Session session = d20::Session();

        message_20::DC_CableCheckRequest req;

        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;

        const auto res = d20::state::handle_request(req, d20::Session(), false);

        THEN("ResponseCode: FAILED_UnknownSession, mandatory fields should be set") {
            REQUIRE(res.response_code == message_20::ResponseCode::FAILED_UnknownSession);
            REQUIRE(res.processing == message_20::Processing::Ongoing);
        }
    }

    GIVEN("Good case - ongoing ") {
        d20::Session session = d20::Session();

        message_20::DC_CableCheckRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;

        const auto res = d20::state::handle_request(req, session, false);

        THEN("ResponseCode: OK, processing: Ongoing") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);
            REQUIRE(res.processing == message_20::Processing::Ongoing);
        }
    }

    GIVEN("Good case - finished ") {
        d20::Session session = d20::Session();

        message_20::DC_CableCheckRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;

        const auto res = d20::state::handle_request(req, session, true);

        THEN("ResponseCode: OK, processing: Finished") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);
            REQUIRE(res.processing == message_20::Processing::Finished);
        }
    }

    // GIVEN("Bad Case - sequence error") {} // todo(sl): not here

    // GIVEN("Bad Case - Performance Timeout") {} // todo(sl): not here

    // GIVEN("Bad Case - Sequence Timeout") {} // todo(sl): not here
}