// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include <cstdint>
#include <string>
#include <array>

namespace iso15118::message_d2::data_types {

using session_id_type = std::string; // hexBinary, max length 8

constexpr auto EVCC_ID_LENGTH = 6;

using evcc_id_type = std::array<uint8_t, EVCC_ID_LENGTH>;    // hexBinary, max length 6

using evse_id_type = std::string;    // string, min length 7 max length 37

using service_id_type = uint16_t;   // unsignedShort
using emaid_type = std::string;      // string, min length 14, max length 15
using meter_id_type = std::string;   // string, max length 32

} // namespace iso15118::message_d2::data_types
