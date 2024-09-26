// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/config.hpp>

#include <algorithm>

#include <iso15118/detail/helper.hpp>

namespace iso15118::d20 {

static auto get_default_dc_parameter_list(const std::vector<ControlMobilityNeedsModes>& control_mobility_modes) {

    std::vector<message_20::DcParameterList> param_list;
    // TODO(sl): Add check if a control mode is more than one in that vector

    for (auto& mode : control_mobility_modes) {
        auto mobility_needs_mode = mode.mobility_mode;

        if (mode.control_mode == message_20::ControlMode::Scheduled) {
            mobility_needs_mode = message_20::MobilityNeedsMode::ProvidedByEvcc;
        }

        param_list.push_back({
            message_20::DcConnector::Extended,
            mode.control_mode,
            mobility_needs_mode,
            message_20::Pricing::NoPricing,
        });
    }

    return param_list;
}

static auto get_default_dc_bpt_parameter_list(const std::vector<ControlMobilityNeedsModes>& control_mobility_modes) {

    std::vector<message_20::DcBptParameterList> param_list;
    // TODO(sl): Add check if a control mode is more than one in that vector

    for (auto& mode : control_mobility_modes) {

        auto mobility_needs_mode = mode.mobility_mode;

        if (mode.control_mode == message_20::ControlMode::Scheduled) {
            // Scheduled mode supports only ProvidedByEvcc
            mobility_needs_mode = message_20::MobilityNeedsMode::ProvidedByEvcc;
        }

        param_list.push_back({{
                                  message_20::DcConnector::Extended,
                                  mode.control_mode,
                                  mobility_needs_mode,
                                  message_20::Pricing::NoPricing,
                              },
                              message_20::BptChannel::Unified,
                              message_20::GeneratorMode::GridFollowing});
    }

    return param_list;
}

SessionConfig::SessionConfig(EvseSetupConfig config) :
    evse_id(std::move(config.evse_id)),
    cert_install_service(config.enable_certificate_install_service),
    authorization_services(std::move(config.authorization_services)),
    supported_energy_transfer_services(std::move(config.supported_energy_services)),
    dc_limits(std::move(config.dc_limits)),
    supported_control_mobility_modes(std::move(config.control_mobility_modes)) {

    const auto is_bpt_service = [](message_20::ServiceCategory service) {
        return service == message_20::ServiceCategory::DC_BPT;
    };
    const auto dc_bpt_found = std::any_of(supported_energy_transfer_services.begin(),
                                          supported_energy_transfer_services.end(), is_bpt_service);

    if (dc_bpt_found and not dc_limits.discharge_limits.has_value()) {
        logf_warning("The supported energy services contain DC_BPT, but dc limits does not contain BPT "
                     "limits. This can lead to session shutdowns.");
    }

    if (supported_control_mobility_modes.empty()) {
        logf_warning("No control modes were provided, set to scheduled mode");
        supported_control_mobility_modes = {
            {message_20::ControlMode::Scheduled, message_20::MobilityNeedsMode::ProvidedByEvcc}};
    }

    dc_parameter_list = get_default_dc_parameter_list(supported_control_mobility_modes);
    dc_bpt_parameter_list = get_default_dc_bpt_parameter_list(supported_control_mobility_modes);
}

} // namespace iso15118::d20
