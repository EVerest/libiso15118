// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>

#include "common.hpp"
#include "iso15118/message_d2/msg_data_types.hpp"

namespace iso15118::message_2 {

struct ServiceDiscoveryReq {
    V2GMessageHeader header;
    std::optional<data_types::service_scope_type> service_scope;
    std::optional<data_types::ServiceCategory> service_category;
};

struct ServiceDiscoveryRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::PaymentOptionList payment_option_list;
    data_types::ChargeService charge_service;
    std::optional<data_types::ServiceList> service_list;
};

} // namespace iso15118::message_2