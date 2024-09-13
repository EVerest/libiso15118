// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include "msg_data_types.hpp"
#include <array>
#include <cstdint>
#include <optional>
#include <string>

namespace iso15118::message_2 {

namespace data_types {

using fault_msg_type = std::string; // max length 64

enum class FaultCode {
    ParsingError,
    NoTLSRootCertificatAvailable,
    UnknownError
};

struct Notification {
    FaultCode fault_code;
    std::optional<fault_msg_type> fault_msg;
};

} // namespace data_types

const uint8_t SESSION_ID_LENGTH = 8;

struct V2GMessageHeader {
    std::array<uint8_t, SESSION_ID_LENGTH> session_id{};
    std::optional<data_types::Notification> notification;
    // std::optional<> signature; // Todo(sl)
};

} // namespace iso15118::message_2
