// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <catch2/catch_test_macros.hpp>

#include <iso15118/detail/d20/state/service_selection.hpp>

using namespace iso15118;

namespace datatypes = message_20::datatypes;

SCENARIO("Service selection state handling") {
    GIVEN("Bad case - Unknown session") {

        d20::Session session = d20::Session();

        message_20::ServiceSelectionRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.selected_energy_transfer_service.service_id = datatypes::ServiceCategory::DC_BPT;
        req.selected_energy_transfer_service.parameter_set_id = 0;

        session = d20::Session();

        const auto res = d20::state::handle_request(req, session);

        THEN("ResponseCode: FAILED_UnknownSession, mandatory fields should be set") {
            REQUIRE(res.response_code == datatypes::ResponseCode::FAILED_UnknownSession);
        }
    }

    GIVEN("Bad case: selected_energy_transfer_service false parameter set id - FAILED_ServiceSelectionInvalid") {

        d20::Session session = d20::Session();

        session.offered_services.energy_services = {datatypes::ServiceCategory::DC};
        session.offered_services.dc_parameter_list[0] = {
            datatypes::DcConnector::Extended,
            datatypes::ControlMode::Scheduled,
            datatypes::MobilityNeedsMode::ProvidedByEvcc,
            datatypes::Pricing::NoPricing,
        };

        message_20::ServiceSelectionRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.selected_energy_transfer_service.service_id = datatypes::ServiceCategory::DC;
        req.selected_energy_transfer_service.parameter_set_id = 1;

        const auto res = d20::state::handle_request(req, session);

        THEN("ResponseCode: FAILED_ServiceSelectionInvalid, mandatory fields should be set") {
            REQUIRE(res.response_code == datatypes::ResponseCode::FAILED_ServiceSelectionInvalid);
        }
    }

    GIVEN("Bad case: selected_energy_transfer service is not correct - FAILED_NoEnergyTransferServiceSelected") {

        d20::Session session = d20::Session();

        session.offered_services.energy_services = {datatypes::ServiceCategory::DC};
        session.offered_services.dc_parameter_list[0] = {
            datatypes::DcConnector::Extended,
            datatypes::ControlMode::Scheduled,
            datatypes::MobilityNeedsMode::ProvidedByEvcc,
            datatypes::Pricing::NoPricing,
        };

        message_20::ServiceSelectionRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.selected_energy_transfer_service.service_id = datatypes::ServiceCategory::AC;
        req.selected_energy_transfer_service.parameter_set_id = 0;

        const auto res = d20::state::handle_request(req, session);

        THEN("ResponseCode: FAILED_NoEnergyTransferServiceSelected, mandatory fields should be set") {
            REQUIRE(res.response_code == datatypes::ResponseCode::FAILED_NoEnergyTransferServiceSelected);
        }
    }

    GIVEN("Good case") {
        d20::Session session = d20::Session();

        session.offered_services.energy_services = {datatypes::ServiceCategory::DC};
        session.offered_services.dc_parameter_list[0] = {
            datatypes::DcConnector::Extended,
            datatypes::ControlMode::Scheduled,
            datatypes::MobilityNeedsMode::ProvidedByEvcc,
            datatypes::Pricing::NoPricing,
        };

        message_20::ServiceSelectionRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.selected_energy_transfer_service.service_id = datatypes::ServiceCategory::DC;
        req.selected_energy_transfer_service.parameter_set_id = 0;

        const auto res = d20::state::handle_request(req, session);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == datatypes::ResponseCode::OK);
        }
    }

    GIVEN("Good case - Check if session variables is set") {
        d20::Session session = d20::Session();

        session.offered_services.energy_services = {datatypes::ServiceCategory::DC};
        session.offered_services.dc_parameter_list[0] = {
            datatypes::DcConnector::Extended,
            datatypes::ControlMode::Scheduled,
            datatypes::MobilityNeedsMode::ProvidedByEvcc,
            datatypes::Pricing::NoPricing,
        };

        message_20::ServiceSelectionRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.selected_energy_transfer_service.service_id = datatypes::ServiceCategory::DC;
        req.selected_energy_transfer_service.parameter_set_id = 0;

        const auto res = d20::state::handle_request(req, session);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == datatypes::ResponseCode::OK);
            REQUIRE(session.get_selected_energy_service() == datatypes::ServiceCategory::DC);
            REQUIRE(session.get_selected_control_mode() == datatypes::ControlMode::Scheduled);
        }
    }

    GIVEN("Good case - DC_BPT") {
        d20::Session session = d20::Session();

        session.offered_services.energy_services = {datatypes::ServiceCategory::DC_BPT};
        session.offered_services.dc_bpt_parameter_list[0] = {{
                                                                 datatypes::DcConnector::Extended,
                                                                 datatypes::ControlMode::Scheduled,
                                                                 datatypes::MobilityNeedsMode::ProvidedByEvcc,
                                                                 datatypes::Pricing::NoPricing,
                                                             },
                                                             datatypes::BptChannel::Unified,
                                                             datatypes::GeneratorMode::GridFollowing};

        message_20::ServiceSelectionRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.selected_energy_transfer_service.service_id = datatypes::ServiceCategory::DC_BPT;
        req.selected_energy_transfer_service.parameter_set_id = 0;

        const auto res = d20::state::handle_request(req, session);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == datatypes::ResponseCode::OK);
            REQUIRE(session.get_selected_energy_service() == datatypes::ServiceCategory::DC_BPT);
            REQUIRE(session.get_selected_control_mode() == datatypes::ControlMode::Scheduled);
        }
    }

    GIVEN("Bad case: selected_vas_list false service id - FAILED_ServiceSelectionInvalid") {
        d20::Session session = d20::Session();

        session.offered_services.energy_services = {datatypes::ServiceCategory::DC};
        session.offered_services.dc_parameter_list[0] = {
            datatypes::DcConnector::Extended,
            datatypes::ControlMode::Scheduled,
            datatypes::MobilityNeedsMode::ProvidedByEvcc,
            datatypes::Pricing::NoPricing,
        };

        session.offered_services.vas_services = {datatypes::ServiceCategory::Internet};
        session.offered_services.internet_parameter_list[0] = {
            datatypes::Protocol::Http,
            datatypes::Port::Port80,
        };

        message_20::ServiceSelectionRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.selected_energy_transfer_service.service_id = datatypes::ServiceCategory::DC;
        req.selected_energy_transfer_service.parameter_set_id = 0;

        req.selected_vas_list = {{datatypes::ServiceCategory::ParkingStatus, 0}};

        const auto res = d20::state::handle_request(req, session);

        THEN("ResponseCode: FAILED_ServiceSelectionInvalid, mandatory fields should be set") {
            REQUIRE(res.response_code == datatypes::ResponseCode::FAILED_ServiceSelectionInvalid);
        }
    }

    GIVEN("Bad case: selected_vas_list false parameter set id - FAILED_ServiceSelectionInvalid") {
        d20::Session session = d20::Session();

        session.offered_services.energy_services = {datatypes::ServiceCategory::DC};
        session.offered_services.dc_parameter_list[0] = {
            datatypes::DcConnector::Extended,
            datatypes::ControlMode::Scheduled,
            datatypes::MobilityNeedsMode::ProvidedByEvcc,
            datatypes::Pricing::NoPricing,
        };

        session.offered_services.vas_services = {datatypes::ServiceCategory::Internet};
        session.offered_services.internet_parameter_list[0] = {
            datatypes::Protocol::Http,
            datatypes::Port::Port80,
        };

        message_20::ServiceSelectionRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.selected_energy_transfer_service.service_id = datatypes::ServiceCategory::DC;
        req.selected_energy_transfer_service.parameter_set_id = 0;

        req.selected_vas_list = {{datatypes::ServiceCategory::Internet, 1}};

        const auto res = d20::state::handle_request(req, session);

        THEN("ResponseCode: FAILED_ServiceSelectionInvalid, mandatory fields should be set") {
            REQUIRE(res.response_code == datatypes::ResponseCode::FAILED_ServiceSelectionInvalid);
        }
    }

    GIVEN("Good case - DC & Internet & Parking") {
        d20::Session session = d20::Session();

        session.offered_services.energy_services = {datatypes::ServiceCategory::DC};
        session.offered_services.dc_parameter_list[0] = {
            datatypes::DcConnector::Extended,
            datatypes::ControlMode::Scheduled,
            datatypes::MobilityNeedsMode::ProvidedByEvcc,
            datatypes::Pricing::NoPricing,
        };

        session.offered_services.vas_services = {datatypes::ServiceCategory::Internet,
                                                 datatypes::ServiceCategory::ParkingStatus};
        session.offered_services.internet_parameter_list[0] = {
            datatypes::Protocol::Http,
            datatypes::Port::Port80,
        };

        session.offered_services.parking_parameter_list[0] = {
            datatypes::IntendedService::VehicleCheckIn,
            datatypes::ParkingStatus::ManualExternal,
        };

        message_20::ServiceSelectionRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;
        req.selected_energy_transfer_service.service_id = datatypes::ServiceCategory::DC;
        req.selected_energy_transfer_service.parameter_set_id = 0;

        req.selected_vas_list = {{datatypes::ServiceCategory::Internet, 0},
                                 {datatypes::ServiceCategory::ParkingStatus, 0}};

        const auto res = d20::state::handle_request(req, session);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == datatypes::ResponseCode::OK);
        }
    }

    // GIVEN("Bad case - FAILED_NoServiceRenegotiationSupported") {} // todo(sl): pause/resume not supported yet

    // GIVEN("Bad Case - sequence error") {} // todo(sl): not here

    // GIVEN("Bad Case - Performance Timeout") {} // todo(sl): not here

    // GIVEN("Bad Case - Sequence Timeout") {} // todo(sl): not here
}
