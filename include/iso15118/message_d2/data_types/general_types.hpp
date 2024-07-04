// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include <cstdint>
#include <string>

namespace iso15118::message_d2::data_types {

using percent_value_type = uint8_t; // range 0-100

using fault_msg_type = std::string; // max length 64

enum class evse_processing_type {
    Finished,
    Ongoing,
    Ongoing_WaitingForCustomerInteraction
};

enum class evse_notification_type {
    None,
    StopCharging,
    ReNegotiation
};

enum class charge_progress_type {
    Start,
    Stop,
    Renegotiate
};

enum class charging_session_type {
    Terminate,
    Pause
};

using service_name_type = std::string; // max length 32

enum class service_category_type {
    EVCharging,
    Internet,
    ContractCertificate,
    OtherCustom
};

using service_scope_type = std::string; // max length 64

using max_num_phases_type = uint8_t; // range 1-3

enum class value_type {
    Bool,
    Byte,
    Short,
    Int,
    PhysicalValue,
    String
};

using meter_status_type = int16_t;

} // namespace iso15118::message_d2::data_types
