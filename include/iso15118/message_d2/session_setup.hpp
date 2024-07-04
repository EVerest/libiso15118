// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include "iso15118/message_d2/data_types/identification_number_types.hpp"
#include <array>
#include <optional>
#include <string>

#include "common.hpp"

namespace iso15118::message_2 {

struct SessionSetupRequest {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::evcc_id_type evccid;
};

struct SessionSetupResponse {
    V2GMessageHeader header;
    ResponseCode response_code;
    std::string evseid;
    std::optional<int64_t> timestamp;
};

} // namespace iso15118::message_2
