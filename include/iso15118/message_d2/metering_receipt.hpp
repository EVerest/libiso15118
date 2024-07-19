// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

struct MeteringReceiptReq {
    V2GMessageHeader header;
    data_types::session_id_type session_id;
    std::optional<data_types::sa_id_type> sa_schedule_tuple_id;
    data_types::MeterInfo meter_info;
    std::string id;
};

struct MeteringReceiptRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::EvseStatus evse_status;
};

} // namespace iso15118::message_2