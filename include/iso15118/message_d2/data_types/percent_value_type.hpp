// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include "simple_type_template.hpp"
#include <cstdint>
#include <stdexcept>

namespace iso15118::message_d2::data_types {

namespace PercentValue {

using base_type = uint8_t;

static base_type validate_function(const base_type value) {
    if (value < 0 || value > 100) {
        throw std::invalid_argument("Percent value must be between 0 and 100.");
    }
    return value;
}

using Type = SimpleTypeT<base_type, validate_function>;

} // namespace PercentValue

} // namespace iso15118::message_d2::data_types
