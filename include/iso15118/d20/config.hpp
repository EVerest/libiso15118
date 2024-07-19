// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cstdint>
#include <optional>
#include <variant>
#include <vector>

#include <iso15118/message/common.hpp>
#include <iso15118/message/dc_charge_parameter_discovery.hpp>

namespace iso15118::d20 {

struct SessionConfig {
    std::string evse_id{""};

    bool cert_install_service{false};
    std::vector<message_20::Authorization> authorization_services{{message_20::Authorization::EIM}};

    std::vector<message_20::ServiceCategory> supported_energy_transfer_services;
    std::vector<message_20::ServiceCategory> supported_vas_services;

    std::vector<message_20::DcParameterList> dc_parameter_list;
    std::vector<message_20::DcBptParameterList> dc_bpt_parameter_list;

    std::vector<message_20::InternetParameterList> internet_parameter_list;
    std::vector<message_20::ParkingParameterList> parking_parameter_list;

    // DC & DC_BPT RationalNumber values
    message_20::RationalNumber max_charge_power;
    message_20::RationalNumber min_charge_power;
    message_20::RationalNumber max_charge_current;
    message_20::RationalNumber min_charge_current;
    message_20::RationalNumber max_voltage;
    message_20::RationalNumber min_voltage;
    std::optional<message_20::RationalNumber> power_ramp_limit;

    std::optional<message_20::RationalNumber> max_discharge_power;
    std::optional<message_20::RationalNumber> min_discharge_power;
    std::optional<message_20::RationalNumber> max_discharge_current;
    std::optional<message_20::RationalNumber> min_discharge_current;

    SessionConfig();
};

} // namespace iso15118::d20
