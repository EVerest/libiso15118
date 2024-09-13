// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>
#include <string>

#include "msg_data_types.hpp"

namespace iso15118::message_20 {

struct SessionStopRequest {
    Header header;
    datatypes::ChargingSession charging_session;
    std::optional<datatypes::name_type> ev_termination_code;
    std::optional<datatypes::description_type> ev_termination_explanation;
};

struct SessionStopResponse {
    Header header;
    datatypes::ResponseCode response_code;
};

} // namespace iso15118::message_20