// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <catch2/catch_test_macros.hpp>

#include <iso15118/session/feedback.hpp>

using namespace iso15118::session;

struct FeedbackResults {
    feedback::Signal signal;
    float target_voltage;
    feedback::DcChargeScheduledMode dc_charge_scheduled_mode;
    feedback::DcChargeDynamicMode dc_charge_dynamic_mode;
    feedback::DcMaximumLimits dc_max_limits;
    iso15118::message_20::Type v2g_message;
    std::string evcc_id;
    std::string selected_protocol;
    feedback::DisplayParameters display_parameters;
    float present_voltage;
    bool meter_info_requested;
};

SCENARIO("Feedback Tests") {

    FeedbackResults feedback_results;
    feedback::Callbacks callbacks;

    callbacks.signal = [&feedback_results](feedback::Signal signal_) { feedback_results.signal = signal_; };
    callbacks.dc_pre_charge_target_voltage = [&feedback_results](float target_voltage_) {
        feedback_results.target_voltage = target_voltage_;
    };
    callbacks.dc_charge_scheduled_mode =
        [&feedback_results](const feedback::DcChargeScheduledMode& dc_scheduled_values_) {
            feedback_results.dc_charge_scheduled_mode = dc_scheduled_values_;
        };
    callbacks.dc_charge_dynamic_mode = [&feedback_results](const feedback::DcChargeDynamicMode& dc_dynamic_values_) {
        feedback_results.dc_charge_dynamic_mode = dc_dynamic_values_;
    };
    callbacks.dc_max_limits = [&feedback_results](const feedback::DcMaximumLimits& dc_max_limits_) {
        feedback_results.dc_max_limits = dc_max_limits_;
    };
    callbacks.v2g_message = [&feedback_results](const iso15118::message_20::Type& type) {
        feedback_results.v2g_message = type;
    };
    callbacks.evccid = [&feedback_results](const std::string& evcc_id_) { feedback_results.evcc_id = evcc_id_; };
    callbacks.selected_protocol = [&feedback_results](const std::string& protocol) {
        feedback_results.selected_protocol = protocol;
    };
    callbacks.display_parameters = [&feedback_results](const feedback::DisplayParameters& parameters) {
        feedback_results.display_parameters = parameters;
    };
    callbacks.dc_present_voltage = [&feedback_results](float present_voltage_) {
        feedback_results.present_voltage = present_voltage_;
    };
    callbacks.meter_info_requested = [&feedback_results](bool requested) {
        feedback_results.meter_info_requested = requested;
    };

    const auto feedback = Feedback(callbacks);

    GIVEN("Test signal") {
        const feedback::Signal expected = feedback::Signal::REQUIRE_AUTH_EIM;
        feedback.signal(feedback::Signal::REQUIRE_AUTH_EIM);

        THEN("signal should be like expected") {
            REQUIRE(feedback_results.signal == expected);
        }
    }

    GIVEN("Test dc_pre_charge_target_voltage") {
        float expected{421.4};
        feedback.dc_pre_charge_target_voltage(421.4);

        THEN("dc_pre_charge_target_voltage should be like expected") {
            REQUIRE(feedback_results.target_voltage == expected);
        }
    }

    GIVEN("Test dc_charge_scheduled_mode") {
        const feedback::DcChargeScheduledMode expected{
            440.2f,       30.0f,        std::nullopt, 34.0f,        std::nullopt, std::nullopt, std::nullopt,
            std::nullopt, std::nullopt, std::nullopt, std::nullopt, 22220.0f,     std::nullopt};
        feedback.dc_charge_scheduled_mode({440.2f, 30.0f, std::nullopt, 34.0f, std::nullopt, std::nullopt, std::nullopt,
                                           std::nullopt, std::nullopt, std::nullopt, std::nullopt, 22220.0f,
                                           std::nullopt});

        THEN("dc_charge_scheduled_mode should be like expected") {
            REQUIRE(feedback_results.dc_charge_scheduled_mode.target_voltage == expected.target_voltage);
            REQUIRE(feedback_results.dc_charge_scheduled_mode.target_current == expected.target_current);
            REQUIRE(feedback_results.dc_charge_scheduled_mode.max_energy_request == expected.max_energy_request);
            REQUIRE(feedback_results.dc_charge_scheduled_mode.min_discharge_power == expected.min_discharge_power);
            REQUIRE(feedback_results.dc_charge_scheduled_mode.target_energy_request == expected.target_energy_request);
            REQUIRE(feedback_results.dc_charge_scheduled_mode.min_energy_request == expected.min_energy_request);
            REQUIRE(feedback_results.dc_charge_scheduled_mode.max_charge_power == expected.max_charge_power);
            REQUIRE(feedback_results.dc_charge_scheduled_mode.min_charge_power == expected.min_charge_power);
            REQUIRE(feedback_results.dc_charge_scheduled_mode.max_charge_current == expected.max_charge_current);
            REQUIRE(feedback_results.dc_charge_scheduled_mode.max_voltage == expected.max_voltage);
            REQUIRE(feedback_results.dc_charge_scheduled_mode.min_voltage == expected.min_voltage);
            REQUIRE(feedback_results.dc_charge_scheduled_mode.max_discharge_power == expected.max_discharge_power);
            REQUIRE(feedback_results.dc_charge_scheduled_mode.max_discharge_current == expected.max_discharge_current);
        }
    }

    GIVEN("Test dc_charge_dynamic_mode") {
        const feedback::DcChargeDynamicMode expected{
            std::nullopt, 23440.0f,     22000.0f,     0,           900.0f, 10.0f, 300.0f, 1500.0f, 150.0f, std::nullopt,
            std::nullopt, std::nullopt, std::nullopt, std::nullopt};
        feedback.dc_charge_dynamic_mode({std::nullopt, 23440.0f, 22000.0f, 0, 900.0f, 10.0f, 300.0f, 1500.0f, 150.0f,
                                         std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt});

        THEN("dc_charge_dynamic_mode should be like expected") {
            REQUIRE(feedback_results.dc_charge_dynamic_mode.departure_time == expected.departure_time);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.target_energy_request == expected.target_energy_request);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.max_energy_request == expected.max_energy_request);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.min_energy_request == expected.min_energy_request);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.max_charge_power == expected.max_charge_power);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.min_charge_power == expected.min_charge_power);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.max_charge_current == expected.max_charge_current);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.max_voltage == expected.max_voltage);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.min_voltage == expected.min_voltage);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.max_discharge_power == expected.max_discharge_power);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.min_discharge_power == expected.min_discharge_power);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.max_discharge_current == expected.max_discharge_current);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.max_v2x_energy_request == expected.max_v2x_energy_request);
            REQUIRE(feedback_results.dc_charge_dynamic_mode.min_v2x_energy_request == expected.min_v2x_energy_request);
        }
    }

    GIVEN("Test dc_max_limits") {
        const feedback::DcMaximumLimits expected{803.1, 10.0, 8031};
        feedback.dc_max_limits({803.1, 10.0, 8031});

        THEN("dc_max_limits should be like expected") {
            REQUIRE(feedback_results.dc_max_limits.voltage == expected.voltage);
            REQUIRE(feedback_results.dc_max_limits.current == expected.current);
            REQUIRE(feedback_results.dc_max_limits.power == expected.power);
        }
    }

    GIVEN("Test v2g_message") {
        using Type = iso15118::message_20::Type;
        const Type expected = Type::DC_CableCheckReq;
        feedback.v2g_message(Type::DC_CableCheckReq);

        THEN("v2g_message should be like expected") {
            REQUIRE(feedback_results.v2g_message == expected);
        }
    }

    GIVEN("Test evcc_id") {
        const std::string expected = "54EA7E40B356";
        feedback.evcc_id("54EA7E40B356");

        THEN("evcc_id should be like expected") {
            REQUIRE(feedback_results.evcc_id == expected);
        }
    }

    GIVEN("Test selected_protocol") {
        const std::string expected = "ISO15118-20:DC";
        feedback.selected_protocol("ISO15118-20:DC");

        THEN("selected_protocol should be like expected") {
            REQUIRE(feedback_results.selected_protocol == expected);
        }
    }

    GIVEN("Test display_parameters") {
        const feedback::DisplayParameters expected{40,           std::nullopt, 95,           std::nullopt, std::nullopt,
                                                   std::nullopt, std::nullopt, std::nullopt, std::nullopt};
        feedback.display_parameters(
            {40, std::nullopt, 95, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt, std::nullopt});

        THEN("display_parameters should be like expected") {
            REQUIRE(feedback_results.display_parameters.present_soc.has_value() == true);
            REQUIRE(*feedback_results.display_parameters.present_soc == expected.present_soc.value_or(0));
            REQUIRE(feedback_results.display_parameters.minimum_soc.has_value() == false);
            REQUIRE(feedback_results.display_parameters.target_soc.has_value() == true);
            REQUIRE(*feedback_results.display_parameters.target_soc == expected.target_soc.value_or(0));
        }
    }

    GIVEN("Test dc_present_voltage") {
        float expected{704.4};
        feedback.dc_present_voltage(704.4);

        THEN("dc_present_voltage should be like expected") {
            REQUIRE(feedback_results.present_voltage == expected);
        }
    }

    GIVEN("Test meter_info_requested") {
        bool expected{true};
        feedback.meter_info_requested(true);

        THEN("meter_info_requested should be like expected") {
            REQUIRE(feedback_results.meter_info_requested == expected);
        }
    }
}
