// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include "common.hpp"
#include "iso15118/message_d2/data_types/complex_types/charging_profile_type.hpp"
#include "iso15118/message_d2/data_types/complex_types/ev_power_delivery_related_types.hpp"
#include "iso15118/message_d2/data_types/tariffs_and_payment_types.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"

namespace iso15118::message_2 {

struct PowerDeliveryReq {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::charge_progress_type charge_progress;
    iso15118::message_d2::data_types::sa_id_type sa_schedule_tuple_id;
    std::optional<iso15118::message_d2::data_types::charging_profile_type> charging_profile;
    std::optional<iso15118::message_d2::data_types::ev_power_delivery_parameter_type> ev_power_delivery_parameter;
};

struct PowerDeliveryRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
    iso15118::message_d2::data_types::evse_status_type evse_status;
};

} // namespace iso15118::message_2
