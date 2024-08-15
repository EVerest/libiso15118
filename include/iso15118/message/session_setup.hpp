// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <string>

#include "msg_data_types.hpp"

namespace iso15118::message_20 {

struct SessionSetupRequest {
    Header header;
    datatypes::identifier_type evccid;
};

struct SessionSetupResponse {
    Header header;
    datatypes::ResponseCode response_code;
    datatypes::identifier_type evseid;
};

} // namespace iso15118::message_20
