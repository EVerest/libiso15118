// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/config.hpp>

#include <algorithm>

#include <iso15118/detail/helper.hpp>

namespace iso15118::d20 {

SessionConfig::SessionConfig(const EvseSetupConfig& config) :
    evse_id(config.evse_id),
    supported_energy_transfer_services(config.supported_energy_services),
    cert_install_service(config.enable_certificate_install_service),
    authorization_services(config.authorization_services),
    dc_limits(config.dc_limits) {

    const auto dc_bpt_found =
        std::find(supported_energy_transfer_services.begin(), supported_energy_transfer_services.end(),
                  message_20::ServiceCategory::DC_BPT) != supported_energy_transfer_services.end();
    if (dc_bpt_found and std::holds_alternative<d20::DcChargeLimits>(dc_limits)) {
        logf_warning("The supported energy services contain DC_BPT, but dc limits does not contain BPT "
                     "limits. This can lead to session shutdowns.");
    }

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
}

} // namespace iso15118::d20
