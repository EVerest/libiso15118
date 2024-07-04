// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include <cstdint>
#include "../tariffs_and_payment_types.hpp"
#include "service_related_types.hpp"
#include "security_related_types.hpp"
#include "../multiplier_and_unit_types.hpp"
#include "physical_value_type.hpp"

namespace iso15118::message_d2::data_types {

struct entry_type {
    virtual ~entry_type() = default; // To ensure polymorphic behavior
};

struct sa_schedules_type {
    virtual ~sa_schedules_type() = default; // To ensure polymorphic behavior
};

struct cost_type {
    cost_kind_type cost_kind;
    uint64_t amount;
    std::optional<unit_multiplier_type> amount_multiplier; // minOccurs="0"
};

struct consumption_cost_type {
    physical_value_type start_value;
    std::vector<cost_type> cost; // maxOccurs="3"
};

struct sales_tariff_entry_type : public entry_type {
    std::optional<uint8_t> e_price_level;     // minOccurs="0"
    std::vector<consumption_cost_type> consumption_cost; // minOccurs="0", maxOccurs="3"
};

struct pmax_schedule_entry_type : public entry_type {
    physical_value_type pmax;
};

struct pmax_schedule_type {
    std::vector<pmax_schedule_entry_type> pmax_schedule_entry; // maxOccurs="1024"
};

struct sales_tariff_type {
    sa_id_type sales_tariff_id;
    std::optional<tariff_description_type> sales_tariff_description; // minOccurs="0"
    std::optional<uint8_t> num_e_price_levels;            // minOccurs="0"
    std::vector<sales_tariff_entry_type> sales_tariff_entry;         // maxOccurs="1024"
    id_type id;
};

struct sa_schedule_tuple_type {
    sa_id_type sa_schedule_tuple_id;
    pmax_schedule_type pmax_schedule;
    std::optional<sales_tariff_type> sales_tariff; // minOccurs="0"
};

struct sa_schedule_list_type : public sa_schedules_type {
    std::vector<sa_schedule_tuple_type> sa_schedule_tuple; // maxOccurs="3"
};


struct interval_type {
    virtual ~interval_type() = default; // To ensure polymorphic behavior
};

struct relative_time_interval_type : public interval_type {
    uint64_t start;
    std::optional<uint64_t> duration; // minOccurs="0"
};


} // namespace iso15118::message_d2::data_types
