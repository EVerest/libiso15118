// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <algorithm>

#include <iso15118/states/d2/authorization.hpp>
#include <iso15118/states/d2/dc_charge_parameter_discovery.hpp>

#include <iso15118/detail/d2/context_helper.hpp>
#include <iso15118/detail/d2/state/authorization.hpp>
#include <iso15118/detail/d2/state/session_stop.hpp>

namespace iso15118::d2::state {

using AuthStatus = message_2::AuthStatus;

static bool find_auth_service_in_offered_services(const message_2::Authorization& req_selected_auth_service,
                                                  const d2::Session& session) {
    auto& offered_auth_services = session.offered_services.auth_services;
    return std::find(offered_auth_services.begin(), offered_auth_services.end(), req_selected_auth_service) !=
           offered_auth_services.end();
}

message_2::AuthorizationResponse handle_request(const message_2::AuthorizationRequest& req, const d2::Session& session,
                                                const message_2::AuthStatus& authorization_status) {

    message_2::AuthorizationResponse res = message_2::AuthorizationResponse();

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_2::ResponseCode::FAILED_UnknownSession);
    }

    // RBL Not part of ISO2?
    //  // [V2G20-2209] Check if authorization service was offered in authorization_setup res
    //  if (not find_auth_service_in_offered_services(req.selected_authorization_service, session)) {
    //      return response_with_code(
    //          res, message_2::ResponseCode::WARNING_AuthorizationSelectionInvalid); // [V2G20-2226] Handling if
    //          warning
    //  }

    message_2::ResponseCode response_code;

    switch (req.selected_authorization_service) {
    case message_2::Authorization::EIM:
        switch (authorization_status) {
        case AuthStatus::Accepted:
            res.evse_processing = message_2::Processing::Finished;
            response_code = message_2::ResponseCode::OK;
            break;
        // RBL Not part of ISO2?
        //  case AuthStatus::Rejected: // Failure [V2G20-2230]
        //      res.evse_processing = message_2::Processing::Finished;
        //      response_code = message_2::ResponseCode::WARNING_EIMAuthorizationFailure;
        //      break;
        case AuthStatus::Pending:
        default:
            res.evse_processing = message_2::Processing::Ongoing;
            response_code = message_2::ResponseCode::OK;
            break;
        }
        break;

    case message_2::Authorization::PnC:
        // todo(SL): Handle PnC
        break;

    default:
        // todo(SL): Fill
        break;
    }

    return response_with_code(res, response_code);
}

void Authorization::enter() {
    ctx.log.enter_state("Authorization");
}

FsmSimpleState::HandleEventReturnType Authorization::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev == FsmEvent::CONTROL_MESSAGE) {
        const auto control_data = ctx.get_control_event<AuthorizationResponse>();
        if (not control_data) {
            // FIXME (aw): error handling
            return sa.HANDLED_INTERNALLY;
        }

        if (*control_data) {
            authorization_status = AuthStatus::Accepted;
        } else {
            authorization_status = AuthStatus::Rejected;
        }

        return sa.HANDLED_INTERNALLY;
    }

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    const auto variant = ctx.get_request();

    if (const auto req = variant->get_if<message_2::AuthorizationRequest>()) {
        const auto res = handle_request(*req, ctx.session, authorization_status);

        if (DoneOnce == false) {
            // RDB iso auth is quite different than ISO20, no authorization_setup to ask for authorization, so do it
            // once here. RDB TODO - figure out the correct way to set up autorization in ISO2
            ctx.feedback.signal(session_2::feedback::Signal::REQUIRE_AUTH_EIM);
            DoneOnce = true;
        }

        ctx.respond(res);

        if (res.response_code >= message_2::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        if (authorization_status == AuthStatus::Accepted) {
            authorization_status = AuthStatus::Pending; // reset
            return sa.create_simple<DC_ChargeParameterDiscovery>(ctx);
        } else {
            return sa.HANDLED_INTERNALLY;
        }
    } else if (const auto req = variant->get_if<message_2::SessionStopRequest>()) {
        const auto res = handle_request(*req, ctx.session);
        ctx.respond(res);

        ctx.session_stopped = true;
        return sa.PASS_ON;
    } else {
        ctx.log("expected AuthorizationReq! But code type id: %d", variant->get_type());

        // Sequence Error
        const message_2::Type req_type = variant->get_type();
        send_sequence_error(req_type, ctx);

        ctx.session_stopped = true;
        return sa.PASS_ON;
    }
}

} // namespace iso15118::d2::state
