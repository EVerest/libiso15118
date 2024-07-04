// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include "../general_types.hpp"
#include "../fault_and_response_code_types.hpp"

namespace iso15118::message_d2::data_types {

struct notification_type {
    fault_code_type fault_code;
    std::optional<fault_msg_type> fault_msg;
};

} // namespace iso15118::message_d2::data_types