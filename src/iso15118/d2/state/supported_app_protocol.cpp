// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d2/state/supported_app_protocol.hpp>

#include <iso15118/d2/state/session_setup.hpp>

#include <iso15118/message_d2/supported_app_protocol.hpp>

#include <iso15118/detail/d2/context_helper.hpp>

namespace iso15118::d2::state {

static auto handle_request(const message_2::SupportedAppProtocolRequest& req) {
    message_2::SupportedAppProtocolResponse res;

    for (const auto& protocol : req.app_protocol) {
        if (protocol.protocol_namespace.compare("urn:iso:std:iso:15118:-20:DC") == 0) {
            res.schema_id = protocol.schema_id;
            return response_with_code(res,
                                      message_2::SupportedAppProtocolResponse::ResponseCode::OK_SuccessfulNegotiation);
        }
    }

    return response_with_code(res, message_2::SupportedAppProtocolResponse::ResponseCode::Failed_NoNegotiation);
}

void SupportedAppProtocol::enter() {
    ctx.log.enter_state("SupportedAppProtocol");
}

FsmSimpleState::HandleEventReturnType SupportedAppProtocol::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev == FsmEvent::V2GTP_MESSAGE) {
        auto variant = ctx.get_request();
        if (variant->get_type() != message_2::Type::SupportedAppProtocolReq) {
            ctx.log("expected SupportedAppProtocolReq!");
            return sa.PASS_ON;
        }

        const auto res = handle_request(variant->get<message_2::SupportedAppProtocolRequest>());

        ctx.respond(res);
        return sa.create_simple<SessionSetup>(ctx);
    }

    return sa.PASS_ON;
}

} // namespace iso15118::d2::state
