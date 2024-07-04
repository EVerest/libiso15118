// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include "iso15118/message_d2/common.hpp"
#include "iso15118/message_d2/data_types/complex_types/ev_evse_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/metering_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/physical_value_type.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"
#include "iso15118/message_d2/data_types/identification_number_types.hpp"
#include "iso15118/message_d2/data_types/tariffs_and_payment_types.hpp"

namespace iso15118::message_2 {

struct DC_CurrentDemandReq {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::dc_ev_status_type dc_ev_status;
    iso15118::message_d2::data_types::physical_value_type ev_target_current;
    std::optional<iso15118::message_d2::data_types::physical_value_type> ev_maximum_voltage_limit;
    std::optional<iso15118::message_d2::data_types::physical_value_type> ev_maximum_current_limit;
    std::optional<iso15118::message_d2::data_types::physical_value_type> ev_maximum_power_limit;
    std::optional<bool> bulk_charging_complete;
    bool charging_complete;
    std::optional<iso15118::message_d2::data_types::physical_value_type> remaining_time_to_full_soc;
    std::optional<iso15118::message_d2::data_types::physical_value_type> remaining_time_to_bulk_soc;
    iso15118::message_d2::data_types::physical_value_type ev_target_voltage;
};

struct DC_CurrentDemandRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
    iso15118::message_d2::data_types::dc_evse_status_type dc_evse_status;
    iso15118::message_d2::data_types::physical_value_type evse_present_voltage;
    iso15118::message_d2::data_types::physical_value_type evse_present_current;
    bool evse_current_limit_achieved;
    bool evse_voltage_limit_achieved;
    bool evse_power_limit_achieved;
    std::optional<iso15118::message_d2::data_types::physical_value_type> evse_maximum_voltage_limit;
    std::optional<iso15118::message_d2::data_types::physical_value_type> evse_maximum_current_limit;
    std::optional<iso15118::message_d2::data_types::physical_value_type> evse_maximum_power_limit;
    iso15118::message_d2::data_types::evse_id_type evse_id;
    iso15118::message_d2::data_types::sa_id_type sa_schedule_tuple_id;
    std::optional<iso15118::message_d2::data_types::meter_info_type> meter_info;
    std::optional<bool> receipt_required;
};

} // namespace iso15118::message_2
