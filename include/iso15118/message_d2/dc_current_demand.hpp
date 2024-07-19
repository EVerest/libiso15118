// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include "iso15118/message_d2/message_header.hpp"
#include "iso15118/message_d2/msg_data_types.hpp"

namespace iso15118::message_2 {

struct DC_CurrentDemandReq {
    V2GMessageHeader header;
    data_types::DcEvStatus dc_ev_status;
    data_types::PhysicalValue ev_target_current;
    std::optional<data_types::PhysicalValue> ev_maximum_voltage_limit;
    std::optional<data_types::PhysicalValue> ev_maximum_current_limit;
    std::optional<data_types::PhysicalValue> ev_maximum_power_limit;
    std::optional<bool> bulk_charging_complete;
    bool charging_complete;
    std::optional<data_types::PhysicalValue> remaining_time_to_full_soc;
    std::optional<data_types::PhysicalValue> remaining_time_to_bulk_soc;
    data_types::PhysicalValue ev_target_voltage;
};

struct DC_CurrentDemandRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::DcEvseStatus dc_evse_status;
    data_types::PhysicalValue evse_present_voltage;
    data_types::PhysicalValue evse_present_current;
    bool evse_current_limit_achieved;
    bool evse_voltage_limit_achieved;
    bool evse_power_limit_achieved;
    std::optional<data_types::PhysicalValue> evse_maximum_voltage_limit;
    std::optional<data_types::PhysicalValue> evse_maximum_current_limit;
    std::optional<data_types::PhysicalValue> evse_maximum_power_limit;
    data_types::evse_id_type evse_id;
    data_types::sa_id_type sa_schedule_tuple_id;
    std::optional<data_types::MeterInfo> meter_info;
    std::optional<bool> receipt_required;
};

} // namespace iso15118::message_2
