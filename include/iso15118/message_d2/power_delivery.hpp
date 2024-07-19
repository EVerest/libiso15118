// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

enum class ChargeProgress {
    Start,
    Stop,
    Renegotiate
};

struct PowerDeliveryReq {
    V2GMessageHeader header;
    ChargeProgress charge_progress;
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
