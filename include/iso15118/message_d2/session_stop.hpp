// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

enum class ChargingSession {
    Terminate,
    Pause
};

struct SessionStopReq {
    V2GMessageHeader header;
    ChargingSession charging_session;
};

struct SessionStopRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
};

} // namespace iso15118::message_2