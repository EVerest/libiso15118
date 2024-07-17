// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>

#include "common.hpp"
#include "iso15118/message_d2/msg_data_types.hpp"

namespace iso15118::message_2 {

struct ServiceDetailReq {
    V2GMessageHeader header;
    data_types::service_id_type service_id;
};

struct ServiceDetailRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::service_id_type service_id;
    std::optional<data_types::ServiceParameterList> service_parameter_list;
};

} // namespace iso15118::message_2
