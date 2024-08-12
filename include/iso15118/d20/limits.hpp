// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>
#include <variant>

#include <iso15118/message/common.hpp>

namespace iso15118::d20 {

struct DcChargeLimits {
    message_20::RationalNumber max_charge_power;
    message_20::RationalNumber min_charge_power;
    message_20::RationalNumber max_charge_current;
    message_20::RationalNumber min_charge_current;
    message_20::RationalNumber max_voltage;
    message_20::RationalNumber min_voltage;
    std::optional<message_20::RationalNumber> power_ramp_limit;
};

struct DcDischargeLimits : DcChargeLimits {
    message_20::RationalNumber max_discharge_power;
    message_20::RationalNumber min_discharge_power;
    message_20::RationalNumber max_discharge_current;
    message_20::RationalNumber min_discharge_current;
};

using DcLimits = std::variant<DcChargeLimits, DcDischargeLimits>;

} // namespace iso15118::d20