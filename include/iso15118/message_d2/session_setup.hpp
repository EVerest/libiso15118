// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include <array>
#include <optional>
#include <string>

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

namespace data_types {

constexpr auto EVCC_ID_LENGTH = 6;
using evcc_id_type = std::array<uint8_t, EVCC_ID_LENGTH>; // hexBinary, max length 6

} // namespace data_types

struct SessionSetupRequest {
    V2GMessageHeader header;
    data_types::evcc_id_type evccid;
};

struct SessionSetupResponse {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    std::string evseid;
    std::optional<int64_t> timestamp;
};

} // namespace iso15118::message_2
