// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include "common.hpp"
#include "iso15118/message_d2/data_types/complex_types/metering_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/ev_evse_related_types.hpp"
#include "iso15118/message_d2/data_types/tariffs_and_payment_types.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"

namespace iso15118::message_2 {

struct MeteringReceiptReq {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::session_id_type session_id;
    std::optional<iso15118::message_d2::data_types::sa_id_type> sa_schedule_tuple_id;
    iso15118::message_d2::data_types::meter_info_type meter_info;
    std::string id;
};

struct MeteringReceiptRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
    iso15118::message_d2::data_types::evse_status_type evse_status;
};

} // namespace iso15118::message_2