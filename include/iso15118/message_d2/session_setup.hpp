// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include <string>
#include <optional>

#include "common.hpp"

namespace iso15118::message_2 {

struct SessionSetupRequest {
    Header header;
    std::string evccid;
};

struct SessionSetupResponse {
    Header header;
    ResponseCode response_code;
    std::string evseid;
    std::optional<uint64_t> timestamp;
};

} // namespace iso15118::message_2
