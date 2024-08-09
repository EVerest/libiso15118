// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/config.hpp>

namespace iso15118::d20 {

SessionConfig::SessionConfig(const std::string& evse_id_,
                             const std::vector<message_20::ServiceCategory>& supported_energy_services_,
                             bool cert_install_service_,
                             std::vector<message_20::Authorization> authorization_services_) :
    evse_id(evse_id_),
    supported_energy_transfer_services(supported_energy_services_),
    cert_install_service(cert_install_service_),
    authorization_services(authorization_services_) {

    dc_parameter_list = {{
        message_20::DcConnector::Extended,
        message_20::ControlMode::Scheduled,
        message_20::MobilityNeedsMode::ProvidedByEvcc,
        message_20::Pricing::NoPricing,
    }};

    dc_bpt_parameter_list = {{{
                                  message_20::DcConnector::Extended,
                                  message_20::ControlMode::Scheduled,
                                  message_20::MobilityNeedsMode::ProvidedByEvcc,
                                  message_20::Pricing::NoPricing,
                              },
                              message_20::BptChannel::Unified,
                              message_20::GeneratorMode::GridFollowing}};

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
