// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>

#include "common.hpp"
#include "iso15118/message_d2/data_types/complex_types/service_related_types.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"
#include "iso15118/message_d2/data_types/general_types.hpp"
#include "iso15118/message_d2/data_types/tariffs_and_payment_types.hpp"

namespace iso15118::message_2 {

struct ServiceDiscoveryReq {
    V2GMessageHeader header;
    std::optional<iso15118::message_d2::data_types::service_scope_type> service_scope;
    std::optional<iso15118::message_d2::data_types::service_category_type> service_category;
};

struct ServiceDiscoveryRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
    iso15118::message_d2::data_types::payment_option_list_type payment_option_list;
    iso15118::message_d2::data_types::charge_service_type charge_service;
    std::optional<iso15118::message_d2::data_types::service_list_type> service_list;
};

} // namespace iso15118::message_2