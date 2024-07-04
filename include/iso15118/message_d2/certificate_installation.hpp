// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include "common.hpp"
#include "iso15118/message_d2/data_types/complex_types/security_related_types.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"

namespace iso15118::message_2 {

struct CertificateInstallationReq {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::certificate_type oem_provisioning_cert;
    iso15118::message_d2::data_types::list_of_root_certificate_ids_type list_of_root_certificate_ids;
    std::string id;
};

struct CertificateInstallationRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
    iso15118::message_d2::data_types::certificate_chain_type sa_provisioning_certificate_chain;
    iso15118::message_d2::data_types::certificate_chain_type contract_signature_cert_chain;
    iso15118::message_d2::data_types::contract_signature_encrypted_private_key_type
        contract_signature_encrypted_private_key;
    iso15118::message_d2::data_types::diffie_hellman_publickey_type dh_publickey;
    iso15118::message_d2::data_types::emaid_type emaid;
};

} // namespace iso15118::message_2
