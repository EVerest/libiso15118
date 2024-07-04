// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include "simple_type_template.hpp"

namespace iso15118::message_d2::data_types {

namespace SessionId {

using base_type = std::array<uint8_t, 4>;

static base_type validate_function(base_type value) {
    return value;
}

using Type = SimpleTypeT<base_type, validate_function>;

} // namespace SessionId

} // namespace iso15118::message_d2::data_types