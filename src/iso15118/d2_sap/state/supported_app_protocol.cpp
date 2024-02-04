// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d2_sap/state/supported_app_protocol.hpp>

//#include <iso15118/d2_sap/state/session_setup.hpp>

#include <iso15118/message_d2_sap/supported_app_protocol.hpp>

#include <iso15118/detail/d2_sap/context_helper.hpp>

namespace iso15118::d2_sap::state {

static auto handle_request(const message_2_sap::SupportedAppProtocolRequest& req) {
    message_2_sap::SupportedAppProtocolResponse res;

    //RDB Decide here which app protocol to use. Send it back in res.SAP_Version
    for (const auto& protocol : req.app_protocol) {
        if (false){//protocol.protocol_namespace.compare("urn:iso:std:iso:15118:-20:DC") == 0) {
            res.schema_id = protocol.schema_id;
            res.SAP_Version = 20;
            return response_with_code(
                res, message_2_sap::SupportedAppProtocolResponse::ResponseCode::OK_SuccessfulNegotiation);
        } 
        else if (protocol.protocol_namespace.compare("urn:iso:15118:2:2013:MsgDef") == 0) {
            res.schema_id = protocol.schema_id;
            res.SAP_Version = 2;
            return response_with_code(
                res, message_2_sap::SupportedAppProtocolResponse::ResponseCode::OK_SuccessfulNegotiation);
        }
    }

    return response_with_code(res, message_2_sap::SupportedAppProtocolResponse::ResponseCode::Failed_NoNegotiation);
}




void SupportedAppProtocol::enter() {
    ctx.log.enter_state("SupportedAppProtocol");
}

FsmSimpleState::HandleEventReturnType SupportedAppProtocol::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev == FsmEvent::V2GTP_MESSAGE) {
        auto variant = ctx.get_request();
        if (variant->get_type() != message_2_sap::Type::SupportedAppProtocolReq) {
            ctx.log("expected SupportedAppProtocolReq!");
            return sa.PASS_ON;
        }

        const auto res = handle_request(variant->get<message_2_sap::SupportedAppProtocolRequest>());

        //RDB Surface the SAP version via the context
        ctx.SAP_Version=res.SAP_Version;
        ctx.respond(res);

        //RDB - just stop here, don't try to go to the next state
        return sa.PASS_ON;
    }

    return sa.PASS_ON;
}

} // namespace iso15118::d2_sap::state
