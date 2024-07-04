// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include "../energy_transfer_type.hpp"
#include "../general_types.hpp"
#include "../identification_number_types.hpp"
#include "physical_value_type.hpp"
#include <cstdint>
#include <vector>

namespace iso15118::message_d2::data_types {

struct service_type {
    service_id_type service_id;
    std::string service_name; // minOccurs="0"
    service_category_type service_category;
    std::string service_scope; // minOccurs="0"
    bool free_service;
};

struct service_list_type {
    std::vector<service_type> service; // maxOccurs="8"
};

struct selected_service_type {
    service_id_type service_id;
    short parameter_set_id; // minOccurs="0"
};

struct selected_service_list_type {
    std::vector<selected_service_type> selected_service; // maxOccurs="16"
};

struct parameter_type {
    std::string name;
    union {
        bool bool_value;
        uint8_t byte_value;
        short short_value;
        int int_value;
        physical_value_type physical_value;
        std::string string_value;
    };
};

struct parameter_set_type {
    short parameter_set_id;
    std::vector<parameter_type> parameter; // maxOccurs="16"
};

struct service_parameter_list_type {
    std::vector<parameter_set_type> parameter_set; // maxOccurs="255"
};

struct supported_energy_transfer_mode_type {
    std::vector<energy_transfer_mode_type> energy_transfer_mode; // maxOccurs="6"
};

struct charge_service_type : public service_type {
    supported_energy_transfer_mode_type supported_energy_transfer_mode;
};

} // namespace iso15118::message_d2::data_types