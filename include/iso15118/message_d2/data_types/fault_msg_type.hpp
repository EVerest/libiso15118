// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include "simple_type_template.hpp"
#include <stdexcept>
#include <string>

namespace iso15118::message_d2::data_types {

namespace FaultMsg {

using base_type = std::string;

static base_type validate_function(const base_type& value) {
    if (value.size() > 65) {
        throw std::invalid_argument("Fault message must be at most 64 characters long.");
    }
    return value;
}

using Type = SimpleTypeT<base_type, validate_function>;

} // namespace FaultMsg

} // namespace iso15118::message_d2::data_types
