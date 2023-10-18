// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <catch2/catch_test_macros.hpp>

#include <iso15118/detail/d20/state/service_detail.hpp>

using namespace iso15118;

SCENARIO("Service detail state handling") {

    GIVEN("Bad Case - Unknown session") {

        d20::Session session = d20::Session();

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.id;
        req.header.timestamp = 1691411798;
        req.service = message_20::ServiceCategory::DC;

        const auto& res = d20::state::handle_request(req, d20::Session(), d20::Config());

        THEN("ResponseCode: FAILED_UnknownSession, mandatory fields should be set") {
            REQUIRE(res.response_code == message_20::ResponseCode::FAILED_UnknownSession);
            REQUIRE(res.service == message_20::ServiceCategory::DC);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameter = res.service_parameter_list[0];
            REQUIRE(parameter.id == 0);
            REQUIRE(parameter.parameter.size() == 4);
            REQUIRE(parameter.parameter[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameter.parameter[0].value));

            const auto& connector = std::get<int32_t>(parameter.parameter[0].value);
            REQUIRE(static_cast<message_20::DcConnector>(connector) == message_20::DcConnector::Core);
        }
    }

    GIVEN("Bad Case - FAILED_ServiceIDInvalid") {

        d20::Session session = d20::Session();
        d20::Config config;
        config.supported_energy_transfer_services = {{message_20::ServiceCategory::DC_BPT, false}};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.id;
        req.header.timestamp = 1691411798;
        req.service = message_20::ServiceCategory::AC;

        const auto& res = d20::state::handle_request(req, session, config);

        THEN("ResponseCode: FAILED_ServiceIDInvalid, mandatory fields should be set") {
            REQUIRE(res.response_code == message_20::ResponseCode::FAILED_ServiceIDInvalid);
            REQUIRE(res.service == message_20::ServiceCategory::DC);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameter = res.service_parameter_list[0];
            REQUIRE(parameter.id == 0);
            REQUIRE(parameter.parameter.size() == 4);
            REQUIRE(parameter.parameter[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameter.parameter[0].value));

            const auto& connector = std::get<int32_t>(parameter.parameter[0].value);
            REQUIRE(static_cast<message_20::DcConnector>(connector) == message_20::DcConnector::Core);
        }
    }

    GIVEN("Good Case - DC Service") {
        d20::Session session = d20::Session();
        d20::Config config;
        config.supported_energy_transfer_services = {{message_20::ServiceCategory::DC, false}};

        config.dc_parameter_list = {{
            message_20::DcConnector::Extended,
            message_20::ControlMode::Scheduled,
            message_20::MobilityNeedsMode::ProvidedByEvcc,
            message_20::Pricing::NoPricing,
        }};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.id;
        req.header.timestamp = 1691411798;
        req.service = message_20::ServiceCategory::DC;

        const auto& res = d20::state::handle_request(req, session, config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);
            REQUIRE(res.service == message_20::ServiceCategory::DC);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameters = res.service_parameter_list[0];
            REQUIRE(parameters.id == 0);
            REQUIRE(parameters.parameter.size() == 4);

            // Connector == Extended
            REQUIRE(parameters.parameter[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[0].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[0].value) == 2);
            // ControlMode == Scheduled
            REQUIRE(parameters.parameter[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[1].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[1].value) == 1);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters.parameter[2].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[2].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[2].value) == 1);
            // Pricing == No Pricing
            REQUIRE(parameters.parameter[3].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[3].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[3].value) == 0);
        }
    }

    GIVEN("Good Case - DC_BPT Service") {
        d20::Session session = d20::Session();
        d20::Config config;
        config.supported_energy_transfer_services = {{message_20::ServiceCategory::DC_BPT, false}};

        config.dc_bpt_parameter_list = {{
            {
                message_20::DcConnector::Extended,
                message_20::ControlMode::Scheduled,
                message_20::MobilityNeedsMode::ProvidedByEvcc,
                message_20::Pricing::NoPricing,
            },
            message_20::BptChannel::Unified,
            message_20::GeneratorMode::GridFollowing,
        }};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.id;
        req.header.timestamp = 1691411798;
        req.service = message_20::ServiceCategory::DC_BPT;

        const auto& res = d20::state::handle_request(req, session, config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);
            REQUIRE(res.service == message_20::ServiceCategory::DC_BPT);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameters = res.service_parameter_list[0];
            REQUIRE(parameters.id == 0);
            REQUIRE(parameters.parameter.size() == 6);

            // Connector == Extended
            REQUIRE(parameters.parameter[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[0].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[0].value) == 2);
            // ControlMode == Scheduled
            REQUIRE(parameters.parameter[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[1].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[1].value) == 1);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters.parameter[2].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[2].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[2].value) == 1);
            // Pricing == No Pricing
            REQUIRE(parameters.parameter[3].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[3].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[3].value) == 0);
            // BPTChannel == Unified
            REQUIRE(parameters.parameter[4].name == "BPTChannel");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[4].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[4].value) == 1);
            // GeneratorMode == GridFollowing
            REQUIRE(parameters.parameter[5].name == "GeneratorMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[5].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[5].value) == 1);
        }
    }

    GIVEN("Good Case - 2x DC Services") {

        d20::Session session = d20::Session();
        d20::Config config;
        config.supported_energy_transfer_services = {{message_20::ServiceCategory::DC, false}};

        config.dc_parameter_list = {{
                                        message_20::DcConnector::Extended,
                                        message_20::ControlMode::Scheduled,
                                        message_20::MobilityNeedsMode::ProvidedByEvcc,
                                        message_20::Pricing::NoPricing,
                                    },
                                    {
                                        message_20::DcConnector::Extended,
                                        message_20::ControlMode::Dynamic,
                                        message_20::MobilityNeedsMode::ProvidedBySecc,
                                        message_20::Pricing::NoPricing,
                                    }};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.id;
        req.header.timestamp = 1691411798;
        req.service = message_20::ServiceCategory::DC;

        const auto& res = d20::state::handle_request(req, session, config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);
            REQUIRE(res.service == message_20::ServiceCategory::DC);
            REQUIRE(res.service_parameter_list.size() == 2);
            auto& parameters_0 = res.service_parameter_list[0];
            REQUIRE(parameters_0.id == 0);
            REQUIRE(parameters_0.parameter.size() == 4);

            // Connector == Extended
            REQUIRE(parameters_0.parameter[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameter[0].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameter[0].value) == 2);
            // ControlMode == Scheduled
            REQUIRE(parameters_0.parameter[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameter[1].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameter[1].value) == 1);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters_0.parameter[2].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameter[2].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameter[2].value) == 1);
            // Pricing == No Pricing
            REQUIRE(parameters_0.parameter[3].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameter[3].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameter[3].value) == 0);

            auto& parameters_1 = res.service_parameter_list[1];
            REQUIRE(parameters_1.id == 1);
            REQUIRE(parameters_1.parameter.size() == 4);

            // Connector == Extended
            REQUIRE(parameters_1.parameter[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameter[0].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameter[0].value) == 2);
            // ControlMode == Scheduled
            REQUIRE(parameters_1.parameter[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameter[1].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameter[1].value) == 2);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters_1.parameter[2].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameter[2].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameter[2].value) == 2);
            // Pricing == No Pricing
            REQUIRE(parameters_1.parameter[3].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameter[3].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameter[3].value) == 0);
        }
    }

    GIVEN("Bad Case - DC Service: Scheduled Mode: 1, MobilityNeedsMode: 2 change to 1") {

        d20::Session session = d20::Session();
        d20::Config config;
        config.supported_energy_transfer_services = {{message_20::ServiceCategory::DC, false}};

        config.dc_parameter_list = {{
            message_20::DcConnector::Extended,
            message_20::ControlMode::Scheduled,
            message_20::MobilityNeedsMode::ProvidedBySecc,
            message_20::Pricing::NoPricing,
        }};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.id;
        req.header.timestamp = 1691411798;
        req.service = message_20::ServiceCategory::DC;

        const auto& res = d20::state::handle_request(req, session, config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);
            REQUIRE(res.service == message_20::ServiceCategory::DC);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameters = res.service_parameter_list[0];
            REQUIRE(parameters.id == 0);
            REQUIRE(parameters.parameter.size() == 4);

            // Connector == Extended
            REQUIRE(parameters.parameter[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[0].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[0].value) == 2);
            // ControlMode == Scheduled
            REQUIRE(parameters.parameter[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[1].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[1].value) == 1);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters.parameter[2].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[2].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[2].value) == 1);
            // Pricing == No Pricing
            REQUIRE(parameters.parameter[3].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameter[3].value));
            REQUIRE(std::get<int32_t>(parameters.parameter[3].value) == 0);
        }
    }

    GIVEN("Good Case - AC Service") {
    } // todo(sl): later

    GIVEN("Good Case - AC_WPT Service") {
    } // todo(sl): later

    // GIVEN("Bad Case - sequence error") {} // todo(sl): not here

    // GIVEN("Performance Timeout") {} // todo(sl): not here

    // GIVEN("Sequence Timeout") {} // todo(sl): not here
}
