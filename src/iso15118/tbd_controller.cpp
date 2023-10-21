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
    const auto request = sdp_server.get_peer_request();

    if (not request) {
        return;
    }

    // std::unique_ptr<io::IConnection> connection =
    //     std::make_unique<io::ConnectionSSL>(poll_manager, config.interface_name, config.ssl);

    std::unique_ptr<io::IConnection> connection =
        std::make_unique<io::ConnectionPlain>(poll_manager, config.interface_name);

    const auto ipv6_endpoint = connection->get_public_endpoint();

    const auto& new_session = sessions.emplace_back(std::move(connection), SessionConfig{config.ssl});

    sdp_server.send_response(request, ipv6_endpoint);
}

} // namespace iso15118
