// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/tbd_controller.hpp>

#include <cstdio>

#include <iso15118/detail/helper.hpp>

namespace iso15118 {

TbdController::TbdController() : TbdController(TbdConfig()) {
}

TbdController::TbdController(TbdConfig config_) : config(std::move(config_)) {
    poll_manager.register_fd(sdp_server.get_fd(), [this]() { handle_sdp_server_input(); });
}

void TbdController::loop() {
    poll_manager.start();
    std::this_thread::sleep_for(std::chrono::minutes(1));
}

void TbdController::handle_sdp_server_input() {
    const auto peer_request = sdp_server.get_peer_request();
    char peer_hostname[128];
    if (get_ipv6_addr(peer_request.address, peer_hostname, sizeof(peer_hostname)) == false) {
        logf("Got SDP request, but failed to get the address\n");
    } else {
        logf("Got SDP request from %s\n", peer_hostname);
    }

    // now create new iso session
    io::SessionSSLServer session_server(config.interface_name, config.ssl);

    const auto session_listen_fd = session_server.get_fd();
    const auto session_socket_address = session_server.get_socket_address();

    auto& descriptor = session_descriptors.emplace_back(std::move(session_server), session_listen_fd);

    poll_manager.register_fd(session_listen_fd, [this, &descriptor]() { handle_session_input(descriptor); });

    sdp_server.send_response({peer_request, session_socket_address});
}

void TbdController::handle_session_input(SessionDescriptor& descriptor) {
    // FIXME (aw): this is still kind of asymetric - furthermore no clear teardown strategy yet
    const auto response = descriptor.session.handle_input();

    if (response != -1) {
        poll_manager.unregister_fd(descriptor.current_fd);
        poll_manager.register_fd(response, [&session = descriptor.session]() { session.handle_input(); });
    } else {
        // should be EAGAIN, right?
    }
}

} // namespace iso15118
