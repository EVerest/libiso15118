// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>
#include <string>
#include <array>

#include "common.hpp"

namespace iso15118::message_2 {

constexpr auto EVCC_ID_LENGTH = 6;

struct SessionSetupRequest {
    Header header;
    std::array<uint8_t, EVCC_ID_LENGTH> evccid{};
};

struct SessionSetupResponse {
    Header header;
    ResponseCode response_code;
    std::string evseid;
    std::optional<int64_t> timestamp;
};

} // namespace iso15118::message_2
