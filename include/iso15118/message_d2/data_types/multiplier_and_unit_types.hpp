// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include <cstdint>

namespace iso15118::message_d2::data_types {

using unit_multiplier_type = int8_t; // byte, range -3 to 3

enum class unit_symbol_type {
    h, // Time in hours
    m, // Time in minutes
    s, // Time in seconds
    A, // Current in Ampere
    V, // Voltage in Volt
    W, // Active power in Watt
    Wh // Real energy in Watt hours
};

} // namespace iso15118::message_d2::data_types