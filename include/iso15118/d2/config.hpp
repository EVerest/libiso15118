// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cstdint>
#include <variant>
#include <vector>

#include <iso15118/message_d2/common.hpp>
#include <iso15118/message_d2/dc_charge_parameter_discovery.hpp>

namespace iso15118::d2 {

struct SessionConfig {
    std::string evse_id{""};

    bool cert_install_service{false};
    std::vector<message_2::Authorization> authorization_services{{message_2::Authorization::EIM}};

    std::vector<message_2::ServiceCategory> supported_energy_transfer_services;
    std::vector<message_2::ServiceCategory> supported_vas_services;

    std::vector<message_2::DcParameterList> dc_parameter_list;
    std::vector<message_2::DcBptParameterList> dc_bpt_parameter_list;

    std::vector<message_2::InternetParameterList> internet_parameter_list;
    std::vector<message_2::ParkingParameterList> parking_parameter_list;

    using DC_ModeRes = message_2::DC_ChargeParameterDiscoveryResponse::DC_CPDResEnergyTransferMode;
    using BPT_DC_ModeRes = message_2::DC_ChargeParameterDiscoveryResponse::BPT_DC_CPDResEnergyTransferMode;

    DC_ModeRes evse_dc_parameter;
    BPT_DC_ModeRes evse_dc_bpt_parameter;

    SessionConfig();
};

} // namespace iso15118::d2
