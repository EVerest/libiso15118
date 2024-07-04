// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include <optional>
#include <cstdint>
#include "physical_value_type.hpp"
#include "ev_evse_related_types.hpp"

namespace iso15118::message_d2::data_types {

struct ev_charge_parameter_type {
    std::optional<uint64_t> departure_time; // minOccurs="0"
    virtual ~ev_charge_parameter_type() = default; // To ensure polymorphic behavior
};

struct ac_ev_charge_parameter_type : public ev_charge_parameter_type {
    physical_value_type e_amount;
    physical_value_type ev_max_voltage;
    physical_value_type ev_max_current;
    physical_value_type ev_min_current;
};

struct dc_ev_charge_parameter_type : public ev_charge_parameter_type {
    dc_ev_status_type dc_ev_status;
    physical_value_type ev_maximum_current_limit;
    std::optional<physical_value_type> ev_maximum_power_limit; // minOccurs="0"
    physical_value_type ev_maximum_voltage_limit;
    std::optional<physical_value_type> ev_energy_capacity; // minOccurs="0"
    std::optional<physical_value_type> ev_energy_request; // minOccurs="0"
    std::optional<percent_value_type> full_soc; // minOccurs="0"
    std::optional<percent_value_type> bulk_soc; // minOccurs="0"
};

struct evse_charge_parameter_type {
    virtual ~evse_charge_parameter_type() = default; // To ensure polymorphic behavior
};

struct ac_evse_charge_parameter_type : public evse_charge_parameter_type {
    ac_evse_status_type ac_evse_status;
    physical_value_type evse_nominal_voltage;
    physical_value_type evse_max_current;
};

struct dc_evse_charge_parameter_type : public evse_charge_parameter_type {
    dc_evse_status_type dc_evse_status;
    physical_value_type evse_maximum_current_limit;
    physical_value_type evse_maximum_power_limit;
    physical_value_type evse_maximum_voltage_limit;
    physical_value_type evse_minimum_current_limit;
    physical_value_type evse_minimum_voltage_limit;
    std::optional<physical_value_type> evse_current_regulation_tolerance; // minOccurs="0"
    physical_value_type evse_peak_current_ripple;
    std::optional<physical_value_type> evse_energy_to_be_delivered; // minOccurs="0"
};

}
