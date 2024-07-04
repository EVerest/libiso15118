// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include <cstdint>
#include "../general_types.hpp"
#include "../only_dc_related_types.hpp"

namespace iso15118::message_d2::data_types {

struct evse_status_type {
    uint16_t notification_max_delay;
    evse_notification_type evse_notification;
    virtual ~evse_status_type() = default; // To ensure polymorphic behavior
};

struct ac_evse_status_type : public evse_status_type {
    bool rcd;
};

struct ev_status_type {
    virtual ~ev_status_type() = default; // To ensure polymorphic behavior
};

struct dc_evse_status_type : public evse_status_type {
    std::optional<isolation_level_type> evse_isolation_status; // minOccurs="0"
    dc_evse_status_code_type evse_status_code;
};

struct dc_ev_status_type : public ev_status_type {
    bool ev_ready;
    dc_ev_error_code_type ev_error_code;
    percent_value_type ev_ress_soc;
};

} // namespace iso15118::message_d2::data_types
