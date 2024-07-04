// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include "common.hpp"
#include "iso15118/message_d2/data_types/complex_types/physical_value_type.hpp"
#include "iso15118/message_d2/data_types/complex_types/security_related_types.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"

namespace iso15118::message_2 {

struct PaymentDetailsReq {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::emaid_type emaid;
    iso15118::message_d2::data_types::certificate_chain_type contract_signature_cert_chain;
};

struct PaymentDetailsRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
    iso15118::message_d2::data_types::gen_challenge_type gen_challenge;
    int64_t evse_time_stamp;
};

} // namespace iso15118::message_2
