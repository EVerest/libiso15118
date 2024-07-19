// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

struct CertificateUpdateReq {
    V2GMessageHeader header;
    data_types::CertificateChain contract_signature_cert_chain;
    data_types::emaid_type emaid;
    data_types::ListOfRootCertificateIds list_of_root_certificate_ids;
    std::string id;
};

struct CertificateUpdateRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::CertificateChain sa_provisioning_certificate_chain;
    data_types::CertificateChain contract_signature_cert_chain;
    data_types::ContractSignatureEncryptedPrivateKey contract_signature_encrypted_private_key;
    data_types::DiffieHellmanPublickey dh_publickey;
    data_types::emaid_type emaid;
    std::optional<int16_t> retry_counter;
};

} // namespace iso15118::message_2