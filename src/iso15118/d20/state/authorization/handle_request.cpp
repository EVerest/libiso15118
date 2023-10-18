// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/detail/d20/state/authorization.hpp>

#include <iso15118/detail/d20/context_helper.hpp>

#include <algorithm>

namespace iso15118::d20::state {

static bool find_auth_service_in_offered_services(const message_20::Authorization& req_selected_auth_service,
                                                  const d20::Session& session) {
    return std::find(session.offered_auth_services.begin(), session.offered_auth_services.end(),
                     req_selected_auth_service) == session.offered_auth_services.end();
}

message_20::AuthorizationResponse handle_request(const message_20::AuthorizationRequest& req,
                                                 const d20::Session& session, const d20::Config& config) {

    message_20::AuthorizationResponse res = message_20::AuthorizationResponse();

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    // [V2G20-2209] Check if authorization service was offered in authorization_setup res
    if (find_auth_service_in_offered_services(req.selected_authorization_service, session)) {
        return response_with_code(
            res, message_20::ResponseCode::WARNING_AuthorizationSelectionInvalid); // [V2G20-2226] Handling if warning
    }

    message_20::ResponseCode response_code;

    switch (req.selected_authorization_service) {
    case message_20::Authorization::EIM:
        using AuthStatus = d20::Config::AuthStatus;

        switch (config.authorization_status) {
        case AuthStatus::Accepted:
            res.evse_processing = message_20::Processing::Finished;
            response_code = message_20::ResponseCode::OK;
            break;
        case AuthStatus::Rejected: // Failure [V2G20-2230]
            res.evse_processing = message_20::Processing::Finished;
            response_code = message_20::ResponseCode::WARNING_EIMAuthorizationFailure;
            break;
        case AuthStatus::Pending:
        default:
            res.evse_processing = message_20::Processing::Ongoing;
            response_code = message_20::ResponseCode::OK;
            break;
        }
        break;

    case message_20::Authorization::PnC:
        // todo(SL): Handle PnC
        break;

    default:
        // todo(SL): Fill
        break;
    }

    return response_with_code(res, response_code);
}

} // namespace iso15118::d20::state
