// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include "msg_data_types.hpp"
#include <array>
#include <cstdint>
#include <optional>
#include <string>

namespace iso15118::message_2 {

const uint8_t SESSION_ID_LENGTH = 8;

struct V2GMessageHeader {
    std::array<uint8_t, SESSION_ID_LENGTH> session_id{};
    std::optional<data_types::Notification> notification;
    // std::optional<> signature; // Todo(sl)
};

} // namespace iso15118::message_2
