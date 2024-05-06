// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <catch2/catch_test_macros.hpp>

#include <iso15118/detail/d20/state/service_detail.hpp>

using namespace iso15118;

namespace dt = message_20::datatypes;

SCENARIO("Service detail state handling") {

    const auto evse_id = std::string("everest se");
    const std::vector<dt::ServiceCategory> supported_energy_services = {dt::ServiceCategory::DC};
    const auto cert_install{false};
    const std::vector<dt::Authorization> auth_services = {dt::Authorization::EIM};
    const d20::DcTransferLimits dc_limits;
    const std::vector<d20::ControlMobilityNeedsModes> control_mobility_modes = {
        {dt::ControlMode::Scheduled, dt::MobilityNeedsMode::ProvidedByEvcc}};

    const d20::EvseSetupConfig evse_setup{evse_id,   supported_energy_services, auth_services, cert_install,
                                          dc_limits, control_mobility_modes};

    GIVEN("Bad Case - Unknown session") {

        d20::Session session = d20::Session();

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.service = dt::ServiceCategory::DC;

        session = d20::Session();
        const auto session_config = d20::SessionConfig(evse_setup);

        const auto res = d20::state::handle_request(req, session, session_config);

        THEN("ResponseCode: FAILED_UnknownSession, mandatory fields should be set") {
            REQUIRE(res.response_code == dt::ResponseCode::FAILED_UnknownSession);
            REQUIRE(res.service == dt::ServiceCategory::DC);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameter = res.service_parameter_list[0];
            REQUIRE(parameter.id == 0);
            REQUIRE(parameter.parameters.size() == 1);
            REQUIRE(parameter.parameters[0].name == "");
            REQUIRE(std::holds_alternative<bool>(parameter.parameters[0].value));

            const auto& connector = std::get<int32_t>(parameter.parameter[0].value);
            REQUIRE(static_cast<dt::DcConnector>(connector) == dt::DcConnector::Core);
        }
    }

    GIVEN("Bad Case - FAILED_ServiceIDInvalid") {

        d20::Session session = d20::Session();
        session.offered_services.energy_services = {dt::ServiceCategory::DC_BPT};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.service = dt::ServiceCategory::AC;

        const auto session_config = d20::SessionConfig(evse_setup);

        const auto res = d20::state::handle_request(req, session, session_config);

        THEN("ResponseCode: FAILED_ServiceIDInvalid, mandatory fields should be set") {
            REQUIRE(res.response_code == dt::ResponseCode::FAILED_ServiceIDInvalid);
            REQUIRE(res.service == dt::ServiceCategory::DC);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameter = res.service_parameter_list[0];
            REQUIRE(parameter.id == 0);
            REQUIRE(parameter.parameters.size() == 1);
            REQUIRE(parameter.parameters[0].name == "");
            REQUIRE(std::holds_alternative<bool>(parameter.parameters[0].value));

            const auto& connector = std::get<int32_t>(parameter.parameter[0].value);
            REQUIRE(static_cast<dt::DcConnector>(connector) == dt::DcConnector::Core);
        }
    }

    GIVEN("Good Case - DC Service") {

        d20::Session session = d20::Session();
        session.offered_services.energy_services = {dt::ServiceCategory::DC};

        const auto session_config = d20::SessionConfig(evse_setup);

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.service = dt::ServiceCategory::DC;

        const auto res = d20::state::handle_request(req, session, session_config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == dt::ResponseCode::OK);
            REQUIRE(res.service == dt::ServiceCategory::DC);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameters = res.service_parameter_list[0];
            REQUIRE(parameters.id == 0);
            REQUIRE(parameters.parameters.size() == 4);

            // Connector == Extended
            REQUIRE(parameters.parameters[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[0].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[0].value) == 2);
            // ControlMode == Scheduled
            REQUIRE(parameters.parameters[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[1].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[1].value) == 1);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters.parameters[2].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[2].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[2].value) == 1);
            // Pricing == No Pricing
            REQUIRE(parameters.parameters[3].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[3].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[3].value) == 0);
        }
    }

    GIVEN("Good Case - DC_BPT Service") {
        d20::Session session = d20::Session();
        session.offered_services.energy_services = {dt::ServiceCategory::DC_BPT};

        const auto session_config = d20::SessionConfig(evse_setup);

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.service = dt::ServiceCategory::DC_BPT;

        const auto res = d20::state::handle_request(req, session, session_config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == dt::ResponseCode::OK);
            REQUIRE(res.service == dt::ServiceCategory::DC_BPT);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameters = res.service_parameter_list[0];
            REQUIRE(parameters.id == 0);
            REQUIRE(parameters.parameters.size() == 6);

            // Connector == Extended
            REQUIRE(parameters.parameters[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[0].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[0].value) == 2);
            // ControlMode == Scheduled
            REQUIRE(parameters.parameters[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[1].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[1].value) == 1);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters.parameters[2].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[2].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[2].value) == 1);
            // Pricing == No Pricing
            REQUIRE(parameters.parameters[3].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[3].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[3].value) == 0);
            // BPTChannel == Unified
            REQUIRE(parameters.parameters[4].name == "BPTChannel");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[4].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[4].value) == 1);
            // GeneratorMode == GridFollowing
            REQUIRE(parameters.parameters[5].name == "GeneratorMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[5].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[5].value) == 1);
        }
    }

    GIVEN("Good Case - 2x DC Services") {

        d20::Session session = d20::Session();
        session.offered_services.energy_services = {dt::ServiceCategory::DC};

        // FIXME(SL): Change evse_setup instead of session_config
        auto session_config = d20::SessionConfig(evse_setup);
        session_config.dc_parameter_list = {{
                                                dt::DcConnector::Extended,
                                                dt::ControlMode::Scheduled,
                                                dt::MobilityNeedsMode::ProvidedByEvcc,
                                                dt::Pricing::NoPricing,
                                            },
                                            {
                                                dt::DcConnector::Extended,
                                                dt::ControlMode::Dynamic,
                                                dt::MobilityNeedsMode::ProvidedBySecc,
                                                dt::Pricing::NoPricing,
                                            }};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.service = dt::ServiceCategory::DC;

        const auto res = d20::state::handle_request(req, session, session_config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == dt::ResponseCode::OK);
            REQUIRE(res.service == dt::ServiceCategory::DC);
            REQUIRE(res.service_parameter_list.size() == 2);
            auto& parameters_0 = res.service_parameter_list[0];
            REQUIRE(parameters_0.id == 0);
            REQUIRE(parameters_0.parameters.size() == 4);

            // Connector == Extended
            REQUIRE(parameters_0.parameters[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameters[0].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameters[0].value) == 2);
            // ControlMode == Scheduled
            REQUIRE(parameters_0.parameters[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameters[1].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameters[1].value) == 1);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters_0.parameters[2].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameters[2].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameters[2].value) == 1);
            // Pricing == No Pricing
            REQUIRE(parameters_0.parameters[3].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameters[3].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameters[3].value) == 0);

            auto& parameters_1 = res.service_parameter_list[1];
            REQUIRE(parameters_1.id == 1);
            REQUIRE(parameters_1.parameters.size() == 4);

            // Connector == Extended
            REQUIRE(parameters_1.parameters[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameters[0].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameters[0].value) == 2);
            // ControlMode == Scheduled
            REQUIRE(parameters_1.parameters[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameters[1].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameters[1].value) == 2);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters_1.parameters[2].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameters[2].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameters[2].value) == 2);
            // Pricing == No Pricing
            REQUIRE(parameters_1.parameters[3].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameters[3].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameters[3].value) == 0);
        }
    }

    GIVEN("Good Case - DC Service: Scheduled Mode: 1, MobilityNeedsMode: 2 change to 1") {

        d20::Session session = d20::Session();
        session.offered_services.energy_services = {dt::ServiceCategory::DC};

        const auto session_config = d20::SessionConfig(evse_setup);

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.service = dt::ServiceCategory::DC;

        const auto res = d20::state::handle_request(req, session, session_config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == dt::ResponseCode::OK);
            REQUIRE(res.service == dt::ServiceCategory::DC);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameters = res.service_parameter_list[0];
            REQUIRE(parameters.id == 0);
            REQUIRE(parameters.parameters.size() == 4);

            // Connector == Extended
            REQUIRE(parameters.parameters[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[0].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[0].value) == 2);
            // ControlMode == Scheduled
            REQUIRE(parameters.parameters[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[1].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[1].value) == 1);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters.parameters[2].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[2].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[2].value) == 1);
            // Pricing == No Pricing
            REQUIRE(parameters.parameters[3].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[3].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[3].value) == 0);
        }
    }

    GIVEN("Good case - Internet service") {
        d20::Session session = d20::Session();
        session.offered_services.energy_services = {dt::ServiceCategory::DC};
        session.offered_services.vas_services = {dt::ServiceCategory::Internet};

        auto session_config = d20::SessionConfig(evse_setup);
        session_config.internet_parameter_list = {{dt::Protocol::Http, dt::Port::Port80}};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.service = dt::ServiceCategory::Internet;

        const auto res = d20::state::handle_request(req, session, session_config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == dt::ResponseCode::OK);
            REQUIRE(res.service == dt::ServiceCategory::Internet);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameters = res.service_parameter_list[0];
            REQUIRE(parameters.id == 3);
            REQUIRE(parameters.parameters.size() == 2);

            // Protocol == HTTP
            REQUIRE(parameters.parameters[0].name == "Protocol");
            REQUIRE(std::holds_alternative<std::string>(parameters.parameters[0].value));
            REQUIRE(std::get<std::string>(parameters.parameters[0].value) == "http");
            // Port == 80
            REQUIRE(parameters.parameters[1].name == "Port");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[1].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[1].value) == 80);
        }
    }

    GIVEN("Good case - Parking status service") {
        d20::Session session = d20::Session();
        session.offered_services.energy_services = {dt::ServiceCategory::DC};
        session.offered_services.vas_services = {dt::ServiceCategory::ParkingStatus};

        auto session_config = d20::SessionConfig(evse_setup);
        session_config.parking_parameter_list = {
            {dt::IntendedService::VehicleCheckIn, dt::ParkingStatus::ManualExternal}};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.service = dt::ServiceCategory::ParkingStatus;

        const auto res = d20::state::handle_request(req, session, session_config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == dt::ResponseCode::OK);
            REQUIRE(res.service == dt::ServiceCategory::ParkingStatus);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameters = res.service_parameter_list[0];
            REQUIRE(parameters.id == 0);
            REQUIRE(parameters.parameters.size() == 2);

            // IntendedService == VehicleCheckIn
            REQUIRE(parameters.parameters[0].name == "IntendedService");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[0].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[0].value) == 1);
            // ParkingStatusType == Manual/External
            REQUIRE(parameters.parameters[1].name == "ParkingStatusType");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[1].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[1].value) == 4);
        }
    }

    GIVEN("Good Case - AC Service") {

        d20::Session session = d20::Session();
        session.offered_services.energy_services = {message_20::ServiceCategory::AC};

        d20::SessionConfig config;
        config.ac_parameter_list = {{
            message_20::AcConnector::ThreePhase,
            message_20::ControlMode::Scheduled,
            message_20::MobilityNeedsMode::ProvidedByEvcc,
            230,
            message_20::Pricing::NoPricing,
        }};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.service = message_20::ServiceCategory::AC;

        const auto res = d20::state::handle_request(req, session, config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);
            REQUIRE(res.service == message_20::ServiceCategory::AC);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameters = res.service_parameter_list[0];
            REQUIRE(parameters.id == 0);
            REQUIRE(parameters.parameters.size() == 5);

            // Connector == ThreePhases
            REQUIRE(parameters.parameters[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[0].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[0].value) == 3);
            // ControlMode == Scheduled
            REQUIRE(parameters.parameters[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[1].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[1].value) == 1);
            // EVSENominalVoltage == 230
            REQUIRE(parameters.parameters[2].name == "EVSENominalVoltage");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[2].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[2].value) == 230);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters.parameters[3].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[3].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[3].value) == 1);
            // Pricing == No Pricing
            REQUIRE(parameters.parameters[4].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[4].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[4].value) == 0);
        }
    }

    GIVEN("Good Case - AC_BPT Service") {
        d20::Session session = d20::Session();
        session.offered_services.energy_services = {message_20::ServiceCategory::AC_BPT};

        d20::SessionConfig config;
        config.ac_bpt_parameter_list = {{
            {
                message_20::AcConnector::ThreePhase,
                message_20::ControlMode::Scheduled,
                message_20::MobilityNeedsMode::ProvidedByEvcc,
                230,
                message_20::Pricing::NoPricing,
            },
            message_20::BptChannel::Unified,
            message_20::GeneratorMode::GridFollowing,
            message_20::GridCodeIslandingDetectionMethode::Passive,
        }};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.service = message_20::ServiceCategory::AC_BPT;

        const auto res = d20::state::handle_request(req, session, config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);
            REQUIRE(res.service == message_20::ServiceCategory::AC_BPT);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameters = res.service_parameter_list[0];
            REQUIRE(parameters.id == 0);
            REQUIRE(parameters.parameters.size() == 8);

            // Connector == ThreePhases
            REQUIRE(parameters.parameters[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[0].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[0].value) == 3);
            // ControlMode == Scheduled
            REQUIRE(parameters.parameters[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[1].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[1].value) == 1);
            // EVSENominalVoltage == 230
            REQUIRE(parameters.parameters[2].name == "EVSENominalVoltage");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[2].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[2].value) == 230);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters.parameters[3].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[3].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[3].value) == 1);
            // Pricing == No Pricing
            REQUIRE(parameters.parameters[4].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[4].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[4].value) == 0);
            // BPTChannel == Unified
            REQUIRE(parameters.parameters[5].name == "BPTChannel");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[5].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[5].value) == 1);
            // GeneratorMode == GridFollowing
            REQUIRE(parameters.parameters[6].name == "GeneratorMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[6].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[6].value) == 1);
            // DetectionMethodGridCodeIslanding == Passive
            REQUIRE(parameters.parameters[7].name == "DetectionMethodGridCodeIslanding");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[7].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[7].value) == 2);
        }
    }

    GIVEN("Good Case - 2x AC Services") {

        d20::Session session = d20::Session();
        session.offered_services.energy_services = {message_20::ServiceCategory::AC};

        d20::SessionConfig config;
        config.ac_parameter_list = {{
                                        message_20::AcConnector::ThreePhase,
                                        message_20::ControlMode::Scheduled,
                                        message_20::MobilityNeedsMode::ProvidedByEvcc,
                                        230,
                                        message_20::Pricing::NoPricing,
                                    },
                                    {
                                        message_20::AcConnector::ThreePhase,
                                        message_20::ControlMode::Dynamic,
                                        message_20::MobilityNeedsMode::ProvidedBySecc,
                                        230,
                                        message_20::Pricing::NoPricing,
                                    }};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.service = message_20::ServiceCategory::AC;

        const auto res = d20::state::handle_request(req, session, config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);
            REQUIRE(res.service == message_20::ServiceCategory::AC);
            REQUIRE(res.service_parameter_list.size() == 2);
            auto& parameters_0 = res.service_parameter_list[0];
            REQUIRE(parameters_0.id == 0);
            REQUIRE(parameters_0.parameters.size() == 5);

            // Connector == ThreePhases
            REQUIRE(parameters_0.parameters[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameters[0].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameters[0].value) == 3);
            // ControlMode == Scheduled
            REQUIRE(parameters_0.parameters[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameters[1].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameters[1].value) == 1);
            // EVSENominalVoltage == 230
            REQUIRE(parameters_0.parameters[2].name == "EVSENominalVoltage");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameters[2].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameters[2].value) == 230);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters_0.parameters[3].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameters[3].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameters[3].value) == 1);
            // Pricing == No Pricing
            REQUIRE(parameters_0.parameters[4].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters_0.parameters[4].value));
            REQUIRE(std::get<int32_t>(parameters_0.parameters[4].value) == 0);

            auto& parameters_1 = res.service_parameter_list[1];
            REQUIRE(parameters_1.id == 1);
            REQUIRE(parameters_1.parameters.size() == 5);

            // Connector == ThreePhases
            REQUIRE(parameters_1.parameters[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameters[0].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameters[0].value) == 3);
            // ControlMode == Dynamic
            REQUIRE(parameters_1.parameters[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameters[1].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameters[1].value) == 2);
            // EVSENominalVoltage == 230
            REQUIRE(parameters_1.parameters[2].name == "EVSENominalVoltage");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameters[2].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameters[2].value) == 230);
            // MobilityNeedsMode == ProvidedbySecc
            REQUIRE(parameters_1.parameters[3].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameters[3].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameters[3].value) == 2);
            // Pricing == No Pricing
            REQUIRE(parameters_1.parameters[4].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters_1.parameters[4].value));
            REQUIRE(std::get<int32_t>(parameters_1.parameters[4].value) == 0);
        }
    }

    GIVEN("Good Case - AC Service: Scheduled Mode: 1, MobilityNeedsMode: 2 change to 1") {

        d20::Session session = d20::Session();
        session.offered_services.energy_services = {message_20::ServiceCategory::AC};

        d20::SessionConfig config;
        config.ac_parameter_list = {{
            message_20::AcConnector::ThreePhase,
            message_20::ControlMode::Scheduled,
            message_20::MobilityNeedsMode::ProvidedBySecc,
            230,
            message_20::Pricing::NoPricing,
        }};

        message_20::ServiceDetailRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.service = message_20::ServiceCategory::AC;

        const auto res = d20::state::handle_request(req, session, config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);
            REQUIRE(res.service == message_20::ServiceCategory::AC);
            REQUIRE(res.service_parameter_list.size() == 1);
            auto& parameters = res.service_parameter_list[0];
            REQUIRE(parameters.id == 0);
            REQUIRE(parameters.parameters.size() == 5);

            // Connector == ThreePhases
            REQUIRE(parameters.parameters[0].name == "Connector");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[0].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[0].value) == 3);
            // ControlMode == Scheduled
            REQUIRE(parameters.parameters[1].name == "ControlMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[1].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[1].value) == 1);
            // EVSENominalVoltage == 230
            REQUIRE(parameters.parameters[2].name == "EVSENominalVoltage");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[2].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[2].value) == 230);
            // MobilityNeedsMode == ProvidedbyEvcc
            REQUIRE(parameters.parameters[3].name == "MobilityNeedsMode");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[3].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[3].value) == 1);
            // Pricing == No Pricing
            REQUIRE(parameters.parameters[4].name == "Pricing");
            REQUIRE(std::holds_alternative<int32_t>(parameters.parameters[4].value));
            REQUIRE(std::get<int32_t>(parameters.parameters[4].value) == 0);
        }
    }

    // GIVEN("Bad Case - sequence error") {} // todo(sl): not here

    // GIVEN("Performance Timeout") {} // todo(sl): not here

    // GIVEN("Sequence Timeout") {} // todo(sl): not here
}
