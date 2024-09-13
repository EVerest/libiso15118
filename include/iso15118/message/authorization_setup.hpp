// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <array>
#include <optional>
#include <string>
#include <variant>
#include <vector>

#include "msg_data_types.hpp"

namespace iso15118::message_20 {

namespace datatypes {
using supported_providers_list_type = std::vector<name_type>; // [0 - 128]

struct EIM_ASResAuthorizationMode {};
struct PnC_ASResAuthorizationMode {
    gen_challenge_type gen_challenge;
    std::optional<datatypes::supported_providers_list_type> supported_providers;
};

} // namespace datatypes

struct AuthorizationSetupRequest {
    Header header;
};

struct AuthorizationSetupResponse {
    AuthorizationSetupResponse() :
        certificate_installation_service(false),
        authorization_services({datatypes::Authorization::EIM}),
        authorization_mode(std::in_place_type<datatypes::EIM_ASResAuthorizationMode>){};

    Header header;
    datatypes::ResponseCode response_code;

    std::vector<datatypes::Authorization> authorization_services;
    bool certificate_installation_service;
    std::variant<datatypes::EIM_ASResAuthorizationMode, datatypes::PnC_ASResAuthorizationMode> authorization_mode;
};

} // namespace iso15118::message_20
