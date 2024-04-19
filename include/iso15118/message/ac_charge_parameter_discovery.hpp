// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>
#include <variant>

#include "common.hpp"

namespace iso15118::message_20 {

struct AC_ChargeParameterDiscoveryRequest {
    Header header;

    struct AC_CPDReqEnergyTransferMode {
        RationalNumber max_charge_power;
        std::optional<RationalNumber> max_charge_power_L2;
        std::optional<RationalNumber> max_charge_power_L3;
        RationalNumber min_charge_power;
        std::optional<RationalNumber> min_charge_power_L2;
        std::optional<RationalNumber> min_charge_power_L3;
    };

    struct BPT_AC_CPDReqEnergyTransferMode : AC_CPDReqEnergyTransferMode {
        RationalNumber max_discharge_power;
        std::optional<RationalNumber> max_discharge_power_L2;
        std::optional<RationalNumber> max_discharge_power_L3;
        RationalNumber min_discharge_power;
        std::optional<RationalNumber> min_discharge_power_L2;
        std::optional<RationalNumber> min_discharge_power_L3;
    };

    std::variant<AC_CPDReqEnergyTransferMode, BPT_AC_CPDReqEnergyTransferMode> transfer_mode;
};

struct AC_ChargeParameterDiscoveryResponse {
    Header header;
    ResponseCode response_code;

    AC_ChargeParameterDiscoveryResponse() : transfer_mode(std::in_place_type<AC_CPDResEnergyTransferMode>){};

    struct AC_CPDResEnergyTransferMode {
        RationalNumber max_charge_power;
        std::optional<RationalNumber> max_charge_power_L2;
        std::optional<RationalNumber> max_charge_power_L3;
        RationalNumber min_charge_power;
        std::optional<RationalNumber> min_charge_power_L2;
        std::optional<RationalNumber> min_charge_power_L3;
        RationalNumber nominal_frequency;
        std::optional<RationalNumber> max_power_asymmetry;
        std::optional<RationalNumber> power_ramp_limitation;
        std::optional<RationalNumber> present_active_power;
        std::optional<RationalNumber> present_active_power_L2;
        std::optional<RationalNumber> present_active_power_L3;
    };

    struct BPT_AC_CPDResEnergyTransferMode : AC_CPDResEnergyTransferMode {
        RationalNumber max_discharge_power;
        std::optional<RationalNumber> max_discharge_power_L2;
        std::optional<RationalNumber> max_discharge_power_L3;
        RationalNumber min_discharge_power;
        std::optional<RationalNumber> min_discharge_power_L2;
        std::optional<RationalNumber> min_discharge_power_L3;
    };

    std::variant<AC_CPDResEnergyTransferMode, BPT_AC_CPDResEnergyTransferMode> transfer_mode;
};

} // namespace iso15118::message_20
