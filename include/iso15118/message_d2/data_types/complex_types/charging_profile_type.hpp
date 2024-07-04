// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include <cstdint>
#include "physical_value_type.hpp"
#include "../general_types.hpp"
#include <optional>
#include <vector>

namespace iso15118::message_d2::data_types {

struct profile_entry_type {
    uint64_t charging_profile_entry_start;
    physical_value_type charging_profile_entry_max_power;
    std::optional<max_num_phases_type> charging_profile_entry_max_number_of_phases_in_use; // minOccurs="0"
};

struct charging_profile_type {
    std::vector<profile_entry_type> profile_entry; // maxOccurs="24"
};

}
