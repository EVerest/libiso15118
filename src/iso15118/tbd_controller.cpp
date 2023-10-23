// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/tbd_controller.hpp>

#include <algorithm>
#include <chrono>
#include <cstdio>

#include <iso15118/io/connection_plain.hpp>
#include <iso15118/io/connection_ssl.hpp>
#include <iso15118/session/iso.hpp>

#include <iso15118/detail/helper.hpp>

namespace iso15118 {

TbdController::TbdController() : TbdController(TbdConfig()) {
}

TbdController::TbdController(TbdConfig config_) : config(std::move(config_)) {
    poll_manager.register_fd(sdp_server.get_fd(), [this]() { handle_sdp_server_input(); });
}

void TbdController::loop() {
    static constexpr auto POLL_MANAGER_TIMEOUT_MS = 50;

    auto next_event = get_current_time_point();

    while (true) {
        const auto poll_timeout_ms = get_timeout_ms_until(next_event, POLL_MANAGER_TIMEOUT_MS);
        poll_manager.poll(poll_timeout_ms);

        next_event = offset_time_point_by_ms(get_current_time_point(), POLL_MANAGER_TIMEOUT_MS);

        for (auto& session : sessions) {
            const auto next_session_event = session.poll();
            next_event = std::min(next_event, next_session_event);
        }
        //
    }
}

void TbdController::handle_sdp_server_input() {
    auto request = sdp_server.get_peer_request();

    if (not request) {
        return;
    }

    switch (config.tls_negotiation_strategy) {
    case config::TlsNegotiationStrategy::ACCEPT_CLIENT_OFFER:
        // nothing to change
        break;
    case config::TlsNegotiationStrategy::ENFORCE_TLS:
        request.security = io::v2gtp::Security::TLS;
        break;
    case config::TlsNegotiationStrategy::ENFORCE_NO_TLS:
        request.security = io::v2gtp::Security::NO_TRANSPORT_SECURITY;
        break;
    }

    auto connection = [this](bool secure_connection) -> std::unique_ptr<io::IConnection> {
        if (secure_connection) {
            return std::make_unique<io::ConnectionSSL>(poll_manager, config.interface_name, config.ssl);
        } else {
            return std::make_unique<io::ConnectionPlain>(poll_manager, config.interface_name);
        }
    }(request.security == io::v2gtp::Security::TLS);

    const auto ipv6_endpoint = connection->get_public_endpoint();

    const auto& new_session = sessions.emplace_back(std::move(connection), SessionConfig{});

    sdp_server.send_response(request, ipv6_endpoint);
}

} // namespace iso15118
