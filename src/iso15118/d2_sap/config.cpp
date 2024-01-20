// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d2_sap/config.hpp>

namespace iso15118::d2_sap {

SessionConfig::SessionConfig() {
    evse_id = "everest se";

    supported_energy_transfer_services = {message_2_sap::ServiceCategory::DC, message_2_sap::ServiceCategory::DC_BPT};

    dc_parameter_list.push_back({
        message_2_sap::DcConnector::Extended,
        message_2_sap::ControlMode::Scheduled,
        message_2_sap::MobilityNeedsMode::ProvidedByEvcc,
        message_2_sap::Pricing::NoPricing,
    });

    dc_bpt_parameter_list.push_back({{
                                         message_2_sap::DcConnector::Extended,
                                         message_2_sap::ControlMode::Scheduled,
                                         message_2_sap::MobilityNeedsMode::ProvidedByEvcc,
                                         message_2_sap::Pricing::NoPricing,
                                     },
                                     message_2_sap::BptChannel::Unified,
                                     message_2_sap::GeneratorMode::GridFollowing});

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

} // namespace iso15118::d2_sap
