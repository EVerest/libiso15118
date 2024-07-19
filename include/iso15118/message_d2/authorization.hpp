// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>
#include <string>
#include <vector>

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

struct AuthorizationReq {
    V2GMessageHeader header;
    std::optional<data_types::gen_challenge_type> gen_challenge;
    std::string id;
};

struct AuthorizationRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::EvseProcessing evse_processing;
};

} // namespace iso15118::message_2
