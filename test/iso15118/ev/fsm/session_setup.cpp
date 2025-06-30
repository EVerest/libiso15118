// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#include <catch2/catch_test_macros.hpp>

#include "helper.hpp"

#include <iso15118/ev/d20/state/session_setup.hpp>
#include <iso15118/message/session_setup.hpp>
#include <iso15118/message/supported_app_protocol.hpp>
#include <iso15118/message/type.hpp>

using namespace iso15118;

SCENARIO("ISO15118-20 EV session setup state transitions") {

    auto state_helper = FsmStateHelper();
    auto ctx = state_helper.get_context();

    GIVEN("Good case - new session") {
        fsm::v2::FSM<ev::d20::StateBase> fsm{ctx.create_state<ev::d20::state::SessionSetup>()};

        const auto res = message_20::SupportedAppProtocolResponse{
            message_20::SupportedAppProtocolResponse::ResponseCode::OK_SuccessfulNegotiation, 0};

        state_helper.handle_response(res);
        const auto result = fsm.feed(ev::d20::Event::V2GTP_MESSAGE);

        THEN("Check if session setup is sent") {
            REQUIRE(result.transitioned() == true);
            REQUIRE(fsm.get_current_state_id() == ev::d20::StateID::AuthorizationSetup);

            const auto response_message = ctx.get_request<message_20::SessionSetupRequest>();
            REQUIRE(response_message.has_value());

            const auto& session_setup_req = response_message.value();
            REQUIRE(session_setup_req.header.session_id == std::array<uint8_t, 8>{0, 0, 0, 0, 0, 0, 0, 0});
            // TODO(SL): Missing check for evcc_id
        }
    }

    // GIVEN("Good case - new session: DC Schema is selected") {
    //     THEN("Check if dc state machine is selected") {
    //     }
    // }
    // GIVEN("Good case - new session: AC Schema is selected") {
    //     THEN("Check if ac state machine is selected") {
    //     }
    // }
    // GIVEN("Bad case - Other message then SupportedAppProtocolRes") {
    // }
    // GIVEN("Bad case - ResponseCode Failed") {
    // }
    // GIVEN("Bad case - ResponseCode Ok but no SchemaID") {
    // }
    // GIVEN("Good case - Resume old session") {
    // }
}
