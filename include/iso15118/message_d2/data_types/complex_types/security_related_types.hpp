// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include "../security_types.hpp"
#include <cstdint>
#include <vector>

namespace iso15118::message_d2::data_types {

using id_type = std::string;
using emaid_type = id_type;

struct x509_issuer_serial_type {
    std::string x509_issuer_name;
    int64_t x509_serial_number;
};

struct contract_signature_encrypted_private_key_type {
    private_key_type value;
    id_type id;
};

struct diffie_hellman_publickey_type {
    dh_publickey_type value;
    id_type id;
};

struct emaid_type_extended {
    emaid_type value;
    id_type id;
};

struct certificate_chain_type {
    certificate_type certificate;
    std::vector<certificate_type> sub_certificates; // minOccurs="0"
    id_type id;
};

struct sub_certificates_type {
    std::vector<certificate_type> certificate; // maxOccurs="4"
};

struct list_of_root_certificate_ids_type {
    std::vector<x509_issuer_serial_type> root_certificate_id; // maxOccurs="20"
};

} // namespace iso15118::message_d2::data_types
