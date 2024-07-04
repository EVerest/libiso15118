// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include "common.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"
#include "iso15118/message_d2/data_types/general_types.hpp"

namespace iso15118::message_2 {

struct SessionStopReq {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::charging_session_type charging_session;
};

struct SessionStopRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
};

} // namespace iso15118::message_2