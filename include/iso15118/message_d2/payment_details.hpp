// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

struct PaymentDetailsReq {
    V2GMessageHeader header;
    data_types::emaid_type emaid;
    data_types::CertificateChain contract_signature_cert_chain;
};

struct PaymentDetailsRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::gen_challenge_type gen_challenge;
    int64_t evse_time_stamp;
};

} // namespace iso15118::message_2
