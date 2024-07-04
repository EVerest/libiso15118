// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

namespace iso15118::message_2 {

struct PaymentServiceSelectionReq {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::payment_option_type selected_payment_option;
    iso15118::message_d2::data_types::selected_service_list_type selected_service_list;
};

struct PaymentServiceSelectionRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
};

} // namespace iso15118::message_2