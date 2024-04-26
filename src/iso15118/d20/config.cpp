// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/config.hpp>

namespace iso15118::d20 {

SessionConfig::SessionConfig() {
    evse_id = "everest se";

    supported_energy_transfer_services = {message_20::ServiceCategory::DC, message_20::ServiceCategory::DC_BPT};

    ac_parameter_list.push_back({
        message_20::AcConnector::SinglePhase,
        message_20::ControlMode::Scheduled,
        message_20::MobilityNeedsMode::ProvidedByEvcc,
        16,
        message_20::Pricing::NoPricing,
    });

    ac_bpt_parameter_list.push_back({
        {
            message_20::AcConnector::SinglePhase,
            message_20::ControlMode::Scheduled,
            message_20::MobilityNeedsMode::ProvidedByEvcc,
            16,
            message_20::Pricing::NoPricing,
        },
        message_20::BptChannel::Unified,
        message_20::GeneratorMode::GridFollowing,
        message_20::GridCodeIslandingDetectionMethode::Passive,
    });

    dc_parameter_list.push_back({
        message_20::DcConnector::Extended,
        message_20::ControlMode::Scheduled,
        message_20::MobilityNeedsMode::ProvidedByEvcc,
        message_20::Pricing::NoPricing,
    });

    dc_bpt_parameter_list.push_back({{
                                         message_20::DcConnector::Extended,
                                         message_20::ControlMode::Scheduled,
                                         message_20::MobilityNeedsMode::ProvidedByEvcc,
                                         message_20::Pricing::NoPricing,
                                     },
                                     message_20::BptChannel::Unified,
                                     message_20::GeneratorMode::GridFollowing});

    evse_ac_parameter = {
        {11, 3},                          // max_charge_power
        message_20::RationalNumber{0, 0}, // max_charge_power_L2
        message_20::RationalNumber{0, 0}, // max_charge_power_L3
        {23, 2},                          // min_charge_power
        message_20::RationalNumber{0, 0}, // min_charge_power_L2
        message_20::RationalNumber{0, 0}, // min_charge_power_L3
        {50, 0},                          // nominal_frequency
    };

    evse_ac_bpt_parameter = {
        {
            {11, 3},                          // max_charge_power
            message_20::RationalNumber{0, 0}, // max_charge_power_L2
            message_20::RationalNumber{0, 0}, // max_charge_power_L3
            {23, 2},                          // min_charge_power
            message_20::RationalNumber{0, 0}, // min_charge_power_L2
            message_20::RationalNumber{0, 0}, // min_charge_power_L3
            {50, 0},                          // nominal_frequency
        },
        {11, 3},                           // max_discharge_power
        message_20::RationalNumber{0, 0}, // max_discharge_power_L2
        message_20::RationalNumber{0, 0}, // max_discharge_power_L3
        {23, 2},                            // min_charge_power
        message_20::RationalNumber{0, 0},  // min_discharge_power_L2
        message_20::RationalNumber{0, 0},  // min_discharge_power_L3
    };

    evse_dc_parameter = {
        {22, 3},  // max_charge_power
        {0, 0},   // min_charge_power
        {25, 0},  // max_charge_current
        {0, 0},   // min_charge_current
        {900, 0}, // max_voltage
        {0, 0},   // min_voltage
    };

    evse_dc_bpt_parameter = {
        {
            {22, 3},  // max_charge_power
            {0, 0},   // min_charge_power
            {25, 0},  // max_charge_current
            {0, 0},   // min_charge_current
            {900, 0}, // max_voltage
            {0, 0},   // min_voltage
        },
        {11, 3}, // max_discharge_power
        {0, 0},  // min_discharge_power
        {25, 0}, // max_discharge_current
        {0, 0},  // min_discharge_current
    };
}

} // namespace iso15118::d20
