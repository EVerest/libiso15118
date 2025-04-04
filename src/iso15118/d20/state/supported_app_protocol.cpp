// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/supported_app_protocol.hpp>

#include <optional>
#include <tuple>

#include <iso15118/d20/state/session_setup.hpp>

#include <iso15118/message/supported_app_protocol.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

std::tuple<message_20::SupportedAppProtocolResponse, std::optional<std::string>>
handle_request(const message_20::SupportedAppProtocolRequest& req, const std::optional<std::string>& custom_protocol) {
    message_20::SupportedAppProtocolResponse res;
    std::optional<std::string> selected_protocol{std::nullopt};

    for (const auto& protocol : req.app_protocol) {
        // TODO(sl): Handle priority
        if (protocol.protocol_namespace.compare("urn:iso:std:iso:15118:-20:DC") == 0) {
            res.schema_id = protocol.schema_id;
            selected_protocol = "ISO15118-20:DC";
            return {response_with_code(
                        res, message_20::SupportedAppProtocolResponse::ResponseCode::OK_SuccessfulNegotiation),
                    selected_protocol};
        } else if (custom_protocol.has_value() and protocol.protocol_namespace.compare(custom_protocol.value()) == 0) {
            res.schema_id = protocol.schema_id;
            selected_protocol = custom_protocol;
            logf_warning("EV and EVSE have agreed on a custom protocol namespace. Problems or aborts can occur in the "
                         "following states!");
            return {response_with_code(
                        res, message_20::SupportedAppProtocolResponse::ResponseCode::OK_SuccessfulNegotiation),
                    selected_protocol};
        }
    }

    return {response_with_code(res, message_20::SupportedAppProtocolResponse::ResponseCode::Failed_NoNegotiation),
            selected_protocol};
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

        const auto [res, selected_protocol] = handle_request(*req, m_ctx.session_config.custom_protocol);
        m_ctx.respond(res);

        if (selected_protocol.has_value()) {
            m_ctx.feedback.selected_protocol(*selected_protocol);
            return m_ctx.create_state<SessionSetup>();
        }

        m_ctx.log("unsupported app protocol: [%s]",
                  req->app_protocol.size() ? req->app_protocol[0].protocol_namespace.c_str() : "unknown");
        return {};
    } else {
        m_ctx.log("expected SupportedAppProtocolReq! But code type id: %d", variant->get_type());

        m_ctx.session_stopped = true;
        return {};
    }
}

} // namespace iso15118::d20::state
