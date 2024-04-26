// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <catch2/catch_test_macros.hpp>

#include <iso15118/detail/d20/state/ac_charge_parameter_discovery.hpp>

using namespace iso15118;

using AC_ModeReq = message_20::AC_ChargeParameterDiscoveryRequest::AC_CPDReqEnergyTransferMode;
using BPT_AC_ModeReq = message_20::AC_ChargeParameterDiscoveryRequest::BPT_AC_CPDReqEnergyTransferMode;

using AC_ModeRes = message_20::AC_ChargeParameterDiscoveryResponse::AC_CPDResEnergyTransferMode;
using BPT_AC_ModeRes = message_20::AC_ChargeParameterDiscoveryResponse::BPT_AC_CPDResEnergyTransferMode;

SCENARIO("AC charge parameter discovery state handling") {
    GIVEN("Bad Case - Unknown session") {

        auto session = d20::Session();

        message_20::AC_ChargeParameterDiscoveryRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;

        auto& req_out = req.transfer_mode.emplace<AC_ModeReq>();
        req_out.max_charge_power = {11, 3};
        req_out.min_charge_power = {23, 2};

        const auto res = d20::state::handle_request(req, d20::Session(), d20::SessionConfig());

        THEN("ResponseCode: FAILED_UnknownSession, mandatory fields should be set") {
            REQUIRE(res.response_code == message_20::ResponseCode::FAILED_UnknownSession);

            REQUIRE(std::holds_alternative<AC_ModeRes>(res.transfer_mode));
            const auto& transfer_mode = std::get<AC_ModeRes>(res.transfer_mode);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.max_charge_power) == 0.0f);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.min_charge_power) == 0.0f);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.nominal_frequency) == 0.0f);
        }
    }

    GIVEN("Bad Case: e.g. ac transfer mod instead of ac_bpt transfer mod - FAILED_WrongChargeParameter") {

        const auto service_parameters = d20::AcBptSelectedServiceParameters(
            message_20::ServiceCategory::AC_BPT, message_20::ControlMode::Scheduled,
            message_20::AcConnector::ThreePhase, 230, message_20::MobilityNeedsMode::ProvidedByEvcc,
            message_20::Pricing::NoPricing, message_20::BptChannel::Unified, message_20::GeneratorMode::GridFollowing,
            message_20::GridCodeIslandingDetectionMethode::Passive);

        auto session = d20::Session(service_parameters);

        message_20::AC_ChargeParameterDiscoveryRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;

        auto& req_out = req.transfer_mode.emplace<AC_ModeReq>();
        req_out.max_charge_power = {11, 3};
        req_out.min_charge_power = {23, 2};

        const auto res = d20::state::handle_request(req, session, d20::SessionConfig());

        THEN("ResponseCode: FAILED_WrongChargeParameter, mandatory fields should be set") {
            REQUIRE(res.response_code == message_20::ResponseCode::FAILED_WrongChargeParameter);

            REQUIRE(std::holds_alternative<AC_ModeRes>(res.transfer_mode));
            const auto& transfer_mode = std::get<AC_ModeRes>(res.transfer_mode);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.max_charge_power) == 0.0f);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.min_charge_power) == 0.0f);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.nominal_frequency) == 0.0f);
        }
    }

    GIVEN("Bad Case: e.g. AC_BPT transfer mod instead of ac transfer mod - FAILED_WrongChargeParameter") {

        const auto service_parameters = d20::AcSelectedServiceParameters(
            message_20::ServiceCategory::AC, message_20::ControlMode::Scheduled, message_20::AcConnector::ThreePhase,
            230, message_20::MobilityNeedsMode::ProvidedByEvcc, message_20::Pricing::NoPricing);

        auto session = d20::Session(service_parameters);

        message_20::AC_ChargeParameterDiscoveryRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;

        auto& req_out = req.transfer_mode.emplace<BPT_AC_ModeReq>();
        req_out.max_charge_power = {11, 3};
        req_out.min_charge_power = {23, 2};
        req_out.max_discharge_power = {11, 3};
        req_out.min_discharge_power = {23, 2};

        const auto res = d20::state::handle_request(req, session, d20::SessionConfig());

        THEN("ResponseCode: FAILED_WrongChargeParameter, mandatory fields should be set") {
            REQUIRE(res.response_code == message_20::ResponseCode::FAILED_WrongChargeParameter);

            REQUIRE(std::holds_alternative<AC_ModeRes>(res.transfer_mode));
            const auto& transfer_mode = std::get<AC_ModeRes>(res.transfer_mode);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.max_charge_power) == 0.0f);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.min_charge_power) == 0.0f);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.nominal_frequency) == 0.0f);
        }
    }

    GIVEN("Good Case: AC") {

        const auto service_parameters = d20::AcSelectedServiceParameters(
            message_20::ServiceCategory::AC, message_20::ControlMode::Scheduled, message_20::AcConnector::ThreePhase,
            230, message_20::MobilityNeedsMode::ProvidedByEvcc, message_20::Pricing::NoPricing);

        auto session = d20::Session(service_parameters);
        auto config = d20::SessionConfig();

        float max_charge_power = 11000.0f;
        float min_charge_power = 11000.0f;
        float nominal_frequency = 50.0f;
        float power_ramp_limitation = 2.0f;

        config.evse_ac_parameter.max_charge_power = message_20::from_float(max_charge_power);
        config.evse_ac_parameter.min_charge_power = message_20::from_float(min_charge_power);
        config.evse_ac_parameter.nominal_frequency = message_20::from_float(nominal_frequency);
        config.evse_ac_parameter.power_ramp_limitation = message_20::from_float(power_ramp_limitation);

        message_20::AC_ChargeParameterDiscoveryRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;

        auto& req_out = req.transfer_mode.emplace<AC_ModeReq>();
        req_out.max_charge_power = {11, 3};
        req_out.min_charge_power = {23, 2};

        const auto res = d20::state::handle_request(req, session, config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);

            REQUIRE(std::holds_alternative<AC_ModeRes>(res.transfer_mode));
            const auto& transfer_mode = std::get<AC_ModeRes>(res.transfer_mode);

            REQUIRE(message_20::from_RationalNumber(transfer_mode.max_charge_power) == max_charge_power);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.min_charge_power) == min_charge_power);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.nominal_frequency) == nominal_frequency);
            REQUIRE(transfer_mode.power_ramp_limitation.has_value() == true);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.power_ramp_limitation.value()) ==
                    power_ramp_limitation);
        }
    }

    GIVEN("Good Case: AC_BPT") {

        const auto service_parameters = d20::AcBptSelectedServiceParameters(
            message_20::ServiceCategory::AC_BPT, message_20::ControlMode::Scheduled,
            message_20::AcConnector::ThreePhase, 230, message_20::MobilityNeedsMode::ProvidedByEvcc,
            message_20::Pricing::NoPricing, message_20::BptChannel::Unified, message_20::GeneratorMode::GridFollowing,
            message_20::GridCodeIslandingDetectionMethode::Passive);

        auto session = d20::Session(service_parameters);
        auto config = d20::SessionConfig();

        float max_charge_power = 11000.0f;
        float min_charge_power = 11000.0f;
        float nominal_frequency = 50.0f;
        float power_ramp_limitation = 2.0f;
        float max_discharge_power = 6000.0f;
        float min_discharge_power = 3000.0f;

        config.evse_ac_bpt_parameter.max_charge_power = message_20::from_float(max_charge_power);
        config.evse_ac_bpt_parameter.min_charge_power = message_20::from_float(min_charge_power);
        config.evse_ac_bpt_parameter.nominal_frequency = message_20::from_float(nominal_frequency);
        config.evse_ac_bpt_parameter.power_ramp_limitation = message_20::from_float(power_ramp_limitation);
        config.evse_ac_bpt_parameter.max_discharge_power = message_20::from_float(max_discharge_power);
        config.evse_ac_bpt_parameter.min_discharge_power = message_20::from_float(min_discharge_power);

        message_20::AC_ChargeParameterDiscoveryRequest req;
        req.header.session_id = session.get_id();
        req.header.timestamp = 1691411798;

        auto& req_out = req.transfer_mode.emplace<BPT_AC_ModeReq>();
        req_out.max_charge_power = {11, 3};
        req_out.min_charge_power = {23, 2};
        req_out.max_discharge_power = {11, 3};
        req_out.min_discharge_power = {23, 2};

        const auto res = d20::state::handle_request(req, session, config);

        THEN("ResponseCode: OK") {
            REQUIRE(res.response_code == message_20::ResponseCode::OK);

            REQUIRE(std::holds_alternative<BPT_AC_ModeRes>(res.transfer_mode));
            const auto& transfer_mode = std::get<BPT_AC_ModeRes>(res.transfer_mode);

            REQUIRE(message_20::from_RationalNumber(transfer_mode.max_charge_power) == max_charge_power);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.min_charge_power) == min_charge_power);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.nominal_frequency) == nominal_frequency);
            REQUIRE(transfer_mode.power_ramp_limitation.has_value() == true);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.power_ramp_limitation.value()) ==
                    power_ramp_limitation);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.max_discharge_power) == max_discharge_power);
            REQUIRE(message_20::from_RationalNumber(transfer_mode.min_discharge_power) == min_discharge_power);
        }
    }

    GIVEN("Bad Case: EV Parameter does not fit in evse parameters - FAILED_WrongChargeParameter") {
    }

    // GIVEN("Bad Case - sequence error") {} // todo(sl): not here

    // GIVEN("Bad Case - Performance Timeout") {} // todo(sl): not here

    // GIVEN("Bad Case - Sequence Timeout") {} // todo(sl): not here
}
