// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <catch2/catch_test_macros.hpp>

#include <iso15118/detail/d20/state/session_stop.hpp>

using namespace iso15118;

namespace dt = message_20::datatypes;

SCENARIO("Session Stop state handling") {

    GIVEN("Bad case - Unknown session") {

        auto session = d20::Session();

        message_20::SessionStopRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.charging_session = dt::ChargingSession::Terminate;

        const auto res = d20::state::handle_request(req, d20::Session());

        THEN("ResponseCode: FAILED_UnknownSession, mandatory fields should be set") {
            REQUIRE(res.response_code == dt::ResponseCode::FAILED_UnknownSession);
        }
    }

    GIVEN("Good Case") {

        auto session = d20::Session();

        message_20::SessionStopRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.charging_session = dt::ChargingSession::Terminate;

        const auto res = d20::state::handle_request(req, session);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == dt::ResponseCode::OK);
        }
    }

    GIVEN("Bad case - FAILED_NoServiceRenegotiationSupported") {
        auto session = d20::Session();

        session.service_renegotiation_supported = false;

        message_20::SessionStopRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.charging_session = dt::ChargingSession::ServiceRenegotiation;

        const auto res = d20::state::handle_request(req, session);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == dt::ResponseCode::FAILED_NoServiceRenegotiationSupported);
        }
    }

    // GIVEN("Bad case - Dynamic mode, FAILED_PauseNotAllowed") {} // TODO(sl): EVCC requests Pause, but Secc didnt
    // initiated

    // GIVEN("Bad case - Scheduled mode , FAILED_PauseNotAllowed") {} // TODO(sl): Check current EVPowerProfileEntry for
    // 0kW

    // GIVEN("Bad case - State B was not measuered -> FAILED") {} // TODO(sl): check evse_manager?

    // GIVEN("Bad Case - sequence error") {} // TODO(sl): not here

    // GIVEN("Bad Case - Performance Timeout") {} // TODO(sl): not here

    // GIVEN("Bad Case - Sequence Timeout") {} // TODO(sl): not here
}