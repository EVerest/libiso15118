// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once
#include "iso15118/message_d2/msg_data_types.hpp"

namespace iso15118::message_2 {

namespace data_types {

struct SelectedService {
    data_types::service_id_type service_id;
    short parameter_set_id; // minOccurs="0"
};

struct SelectedServiceList {
    std::vector<SelectedService> selected_service; // maxOccurs="16"
};

} // namespace data_types

struct PaymentServiceSelectionReq {
    V2GMessageHeader header;
    data_types::PaymentOption selected_payment_option;
    data_types::SelectedServiceList selected_service_list;
};

struct PaymentServiceSelectionRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
};

} // namespace iso15118::message_2