// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include "common.hpp"
#include "iso15118/message_d2/data_types/complex_types/ev_evse_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/metering_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/physical_value_type.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"
#include "iso15118/message_d2/data_types/identification_number_types.hpp"
#include "iso15118/message_d2/data_types/tariffs_and_payment_types.hpp"

namespace iso15118::message_2 {

struct ChargingStatusReq {
    V2GMessageHeader header;
};

struct ChargingStatusRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
    iso15118::message_d2::data_types::evse_id_type evse_id;
    iso15118::message_d2::data_types::sa_id_type sa_schedule_tuple_id;
    std::optional<iso15118::message_d2::data_types::physical_value_type> evse_max_current;
    std::optional<iso15118::message_d2::data_types::meter_info_type> meter_info;
    std::optional<bool> receipt_required;
    iso15118::message_d2::data_types::ac_evse_status_type ac_evse_status;
};

} // namespace iso15118::message_2