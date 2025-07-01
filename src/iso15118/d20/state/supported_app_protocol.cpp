// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/supported_app_protocol.hpp>

#include <map>
#include <optional>

#include <iso15118/d20/state/session_setup.hpp>

#include <iso15118/message/supported_app_protocol.hpp>

#include <iso15118/detail/d20/context_helper.hpp>

namespace iso15118::d20::state {

constexpr auto ISO20_DC_NAMESPACE = "urn:iso:std:iso:15118:-20:DC";
constexpr auto ISO20_AC_NAMESPACE = "urn:iso:std:iso:15118:-20:AC";

using ResponseCode = message_20::SupportedAppProtocolResponse::ResponseCode;

message_20::SupportedAppProtocolResponse handle_request(const message_20::SupportedAppProtocolRequest& req) {
    message_20::SupportedAppProtocolResponse res;

    std::map<uint8_t, uint8_t> ev_supported_protocols{}; // key: priority, value: schema_id

    for (const auto& protocol : req.app_protocol) {
        if (protocol.protocol_namespace.compare(ISO20_DC_NAMESPACE) == 0) {
            ev_supported_protocols[protocol.priority] = protocol.schema_id;
        }
        if (protocol.protocol_namespace.compare(ISO20_AC_NAMESPACE) == 0) {
            ev_supported_protocols[protocol.priority] = protocol.schema_id;
        }
    }

    if (ev_supported_protocols.empty()) {
        return response_with_code(res, ResponseCode::Failed_NoNegotiation);
    }

    res.schema_id = ev_supported_protocols.begin()->second; // [V2G20-167] Highest Prio: 1, Lowest Prio: 20
    return response_with_code(res, ResponseCode::OK_SuccessfulNegotiation);
}

void SupportedAppProtocol::enter() {
    m_ctx.log.enter_state("SupportedAppProtocol");
}

Result SupportedAppProtocol::feed(Event ev) {
    if (ev != Event::V2GTP_MESSAGE) {
        return {};
    }

    auto variant = m_ctx.pull_request();

    if (const auto req = variant->get_if<message_20::SupportedAppProtocolRequest>()) {
        m_ctx.ev_info.ev_supported_app_protocols = req->app_protocol;

        const auto res = handle_request(*req);
        m_ctx.respond(res);

        if (res.response_code == ResponseCode::Failed_NoNegotiation) {
            m_ctx.log("unsupported app protocol: [%s]",
                      req->app_protocol.size() ? req->app_protocol[0].protocol_namespace.c_str() : "unknown");
            return {};
        }

        for (const auto& protocol : req->app_protocol) {
            if (protocol.schema_id == res.schema_id) {
                m_ctx.ev_info.selected_app_protocol = protocol;

                if (protocol.protocol_namespace.compare(ISO20_DC_NAMESPACE) == 0) {
                    m_ctx.feedback.selected_protocol("ISO15118-20:DC");
                }
                if (protocol.protocol_namespace.compare(ISO20_AC_NAMESPACE) == 0) {
                    m_ctx.feedback.selected_protocol("ISO15118-20:AC");
                }
            }
        }
        return m_ctx.create_state<SessionSetup>();
    } else {
        m_ctx.log("expected SupportedAppProtocolReq! But code type id: %d", variant->get_type());

        m_ctx.session_stopped = true;
        return {};
    }
}

} // namespace iso15118::d20::state
