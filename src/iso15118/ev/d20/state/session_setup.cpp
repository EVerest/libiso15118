// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#include <iso15118/ev/d20/state/session_setup.hpp>

#include <optional>

#include <iso15118/ev/d20/state/authorization_setup.hpp>
#include <iso15118/message/session_setup.hpp>
#include <iso15118/message/supported_app_protocol.hpp>

#include <iso15118/detail/helper.hpp>
#include <iso15118/ev/detail/d20/context_helper.hpp>

namespace iso15118::ev::d20::state {

namespace {
using ResponseCode = message_20::SupportedAppProtocolResponse::ResponseCode;
bool check_response_code(ResponseCode response_code) {
    switch (response_code) {
    case ResponseCode::OK_SuccessfulNegotiation:
        return true;
    case ResponseCode::OK_SuccessfulNegotiationWithMinorDeviation:
        logf_error("Evse has sent SupportedAppProtocolResponse with a ResponseCode: "
                   "OK_SuccessfulNegotiationWithMinorDeviation. In 15118-20 this is not allowed!");
        return false;
    case ResponseCode::Failed_NoNegotiation:
        logf_error("Evse has sent SupportedAppProtocolResponse with a ResponseCode: "
                   "Failed_NoNegotiation");
        [[fallthrough]];
    default:
        return false;
    }
}
} // namespace

void SessionSetup::enter() {
    // TODO(SL): Adding logging
}

Result SessionSetup::feed(Event ev) {
    if (ev != Event::V2GTP_MESSAGE) {
        return {};
    }

    const auto variant = m_ctx.pull_response();

    if (const auto res = variant->get_if<message_20::SupportedAppProtocolResponse>()) {

        if (not check_response_code(res->response_code)) {
            m_ctx.stop_session(true); // Tell stack to close the tcp/tls connection
            return {};
        }

        if (not res->schema_id.has_value()) {
            logf_error(
                "SupportedAppProtocolRes should have a SchemaId. This is here not the case! Abort the session.");
            m_ctx.stop_session(true); // Tell stack to close the tcp/tls connection
            return {};
        }

        // TODO(SL): Check schema id and select the correct schema

        // 2. Create SessionSetupReq
        message_20::SessionSetupRequest req;

        setup_header(req.header, m_ctx.get_session());
        req.evccid = m_ctx.get_evcc_id();

        m_ctx.respond(req);

        return {m_ctx.create_state<AuthorizationSetup>()};
    } else {
        logf_error("expected SupportedAppProtocol! But code type id: %d", variant->get_type());
        m_ctx.stop_session(true); // Tell stack to close the tcp/tls connection
        return {};
    }
}

} // namespace iso15118::ev::d20::state
