// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>

#include "common.hpp"
#include "iso15118/message_d2/data_types/complex_types/service_related_types.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"
#include "iso15118/message_d2/data_types/identification_number_types.hpp"

namespace iso15118::message_2 {

struct ServiceDetailReq {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::service_id_type service_id;
};

struct ServiceDetailRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
    iso15118::message_d2::data_types::service_id_type service_id;
    std::optional<iso15118::message_d2::data_types::service_parameter_list_type> service_parameter_list;
};

} // namespace iso15118::message_2
