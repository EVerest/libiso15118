// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

namespace data_types {

using max_num_phases_type = uint8_t; // range 1-3

struct ProfileEntry {
    uint64_t charging_profile_entry_start;
    PhysicalValue charging_profile_entry_max_power;
    std::optional<max_num_phases_type> charging_profile_entry_max_number_of_phases_in_use; // minOccurs="0"
};

struct ChargingProfile {
    std::vector<ProfileEntry> profile_entry; // maxOccurs="24"
};

enum class ChargeProgress {
    Start,
    Stop,
    Renegotiate
};

struct EvPowerDeliveryParameter {
    virtual ~EvPowerDeliveryParameter() = default; // To ensure polymorphic behavior
};

} // namespace data_types

struct PowerDeliveryReq {
    V2GMessageHeader header;
    data_types::ChargeProgress charge_progress;
    data_types::sa_id_type sa_schedule_tuple_id;
    std::optional<data_types::ChargingProfile> charging_profile;
    std::optional<data_types::EvPowerDeliveryParameter> ev_power_delivery_parameter;
};

struct PowerDeliveryRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::EvseStatus evse_status;
};

} // namespace iso15118::message_2
