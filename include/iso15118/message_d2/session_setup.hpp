// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include <array>
#include <optional>
#include <string>

#include "common.hpp"
#include "iso15118/message_d2/msg_data_types.hpp"

namespace iso15118::message_2 {

struct SessionSetupRequest {
    V2GMessageHeader header;
    data_types::evcc_id_type evccid;
};

struct SessionSetupResponse {
    V2GMessageHeader header;
    ResponseCode response_code;
    std::string evseid;
    std::optional<int64_t> timestamp;
};

} // namespace iso15118::message_2
