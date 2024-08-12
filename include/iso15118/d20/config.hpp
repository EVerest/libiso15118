// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cstdint>
#include <variant>
#include <vector>

#include <iso15118/message/common.hpp>
#include <iso15118/message/dc_charge_parameter_discovery.hpp>
#include <iso15118/d20/limits.hpp>

namespace iso15118::d20 {

struct EvseSetupConfig {
    std::string evse_id;
    std::vector<message_20::ServiceCategory> supported_energy_services;
    std::vector<message_20::Authorization> authorization_services;
    bool enable_certificate_install_service;
    d20::DcLimits dc_limits;
};

struct SessionConfig {
    explicit SessionConfig(const EvseSetupConfig&);

    std::string evse_id;

    bool cert_install_service;
    std::vector<message_20::Authorization> authorization_services;

    std::vector<message_20::ServiceCategory> supported_energy_transfer_services;
    std::vector<message_20::ServiceCategory> supported_vas_services;

    std::vector<message_20::DcParameterList> dc_parameter_list;
    std::vector<message_20::DcBptParameterList> dc_bpt_parameter_list;

    std::vector<message_20::InternetParameterList> internet_parameter_list;
    std::vector<message_20::ParkingParameterList> parking_parameter_list;

    DcLimits dc_limits;

    using DC_ModeRes = message_20::DC_ChargeParameterDiscoveryResponse::DC_CPDResEnergyTransferMode;
    using BPT_DC_ModeRes = message_20::DC_ChargeParameterDiscoveryResponse::BPT_DC_CPDResEnergyTransferMode;

    DC_ModeRes evse_dc_parameter;
    BPT_DC_ModeRes evse_dc_bpt_parameter;
};

} // namespace iso15118::d20
