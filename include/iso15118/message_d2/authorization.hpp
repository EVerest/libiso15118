// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>
#include <string>
#include <vector>

#include "common.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"
#include "iso15118/message_d2/data_types/general_types.hpp"
#include "iso15118/message_d2/data_types/security_types.hpp"

namespace iso15118::message_2 {

struct AuthorizationReq {
    V2GMessageHeader header;
    std::optional<iso15118::message_d2::data_types::gen_challenge_type> gen_challenge;
    std::string id;
};

struct AuthorizationRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
    iso15118::message_d2::data_types::evse_processing_type evse_processing;
};

} // namespace iso15118::message_2
