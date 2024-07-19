// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

namespace data_types {
enum class ChargingSession {
    Terminate,
    Pause
};

} // namespace data_types

struct SessionStopReq {
    V2GMessageHeader header;
    data_types::ChargingSession charging_session;
};

struct SessionStopRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
};

} // namespace iso15118::message_2