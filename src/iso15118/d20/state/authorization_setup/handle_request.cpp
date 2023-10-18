// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/detail/d20/state/authorization_setup.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/helper.hpp>

#include <random>

namespace iso15118::d20::state {

message_20::AuthorizationSetupResponse handle_request(const message_20::AuthorizationSetupRequest& req,
                                                      const d20::Session& session, const d20::Config& config) {

    auto res = message_20::AuthorizationSetupResponse(); // default mandatory values [V2G20-736]

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    res.certificate_installation_service = config.cert_install_service;

    if (config.authorization_services.empty()) {
        log("Warning: authorization_services was not set. Setting EIM as auth_mode");
        res.authorization_services = {message_20::Authorization::EIM};
    } else {
        res.authorization_services = config.authorization_services;
    }

    auto& session_offered_auth_services =
        const_cast<std::vector<message_20::Authorization>&>(session.offered_auth_services);

    for (auto& service : res.authorization_services) {
        session_offered_auth_services.push_back(service);
    }

    if (res.authorization_services.size() == 1 && res.authorization_services[0] == message_20::Authorization::EIM) {
        res.authorization_mode.emplace<message_20::AuthorizationSetupResponse::EIM_ASResAuthorizationMode>();
    } else {
        auto& pnc_auth_mode =
            res.authorization_mode.emplace<message_20::AuthorizationSetupResponse::PnC_ASResAuthorizationMode>();

        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<uint8_t> distribution(0x00, 0xff);

        for (auto& item : pnc_auth_mode.gen_challenge) {
            item = distribution(generator);
        }
    }

    return response_with_code(res, message_20::ResponseCode::OK);
}

} // namespace iso15118::d20::state
