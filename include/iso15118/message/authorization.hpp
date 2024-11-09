// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <string>
#include <variant>
#include <vector>

#include "common.hpp"

namespace iso15118::message_20 {

enum class AuthStatus {
    Accepted = 0,
    Pending = 1,
    Rejected = 2,
};

struct AuthorizationRequest {

    // Todo(sl): Refactor in common
    struct ContractCertificateChain {
        std::vector<uint8_t> certificate;
        std::vector<std::vector<uint8_t>> sub_certificates;
    };

    struct EIM_ASReqAuthorizationMode {};
    struct PnC_ASReqAuthorizationMode {
        std::string id;
        std::vector<uint8_t> gen_challenge;
        ContractCertificateChain contract_certificate_chain;
    };

    Header header;
    Authorization selected_authorization_service;
    std::variant<EIM_ASReqAuthorizationMode, PnC_ASReqAuthorizationMode> authorization_mode;
};

struct AuthorizationResponse {

    AuthorizationResponse() : evse_processing(Processing::Finished){};

    Header header;
    ResponseCode response_code;
    Processing evse_processing;
};

} // namespace iso15118::message_20
