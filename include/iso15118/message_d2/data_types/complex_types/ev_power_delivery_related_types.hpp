// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include <optional>
#include "ev_evse_related_types.hpp"

namespace iso15118::message_d2::data_types {

struct ev_power_delivery_parameter_type {
    virtual ~ev_power_delivery_parameter_type() = default; // To ensure polymorphic behavior
};

struct dc_ev_power_delivery_parameter_type : public ev_power_delivery_parameter_type {
    dc_ev_status_type dc_ev_status;
    std::optional<bool> bulk_charging_complete; // minOccurs="0"
    bool charging_complete;
};


}