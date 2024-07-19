// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

struct ChargingStatusReq {
    V2GMessageHeader header;
};

struct ChargingStatusRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::evse_id_type evse_id;
    data_types::sa_id_type sa_schedule_tuple_id;
    std::optional<data_types::PhysicalValue> evse_max_current;
    std::optional<data_types::MeterInfo> meter_info;
    std::optional<bool> receipt_required;
    data_types::AcEvseStatus ac_evse_status;
};

} // namespace iso15118::message_2