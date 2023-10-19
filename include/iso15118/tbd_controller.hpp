// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <list>
#include <memory>

#include "io/poll_manager.hpp"
#include "io/sdp_server.hpp"
#include "session/d20.hpp"
#include "config.hpp"

namespace iso15118 {

struct SessionDescriptor {
    // FIXME (aw): is it possible to inplace construct a struct with initializer list initialization where one of the
    // ctor arguments needs to be inplace constructed too?
    SessionDescriptor(io::SessionSSLServer&& session_server, int fd) :
        session(std::move(session_server)), current_fd(fd){};

    session::D20Session session;
    int current_fd;
};

struct TbdConfig {
    config::SSLConfig ssl {config::CertificateBackend::EVEREST_LAYOUT, ""};
    std::string interface_name;
};

class TbdController {
public:
    TbdController();
    explicit TbdController(TbdConfig);

    void loop();

private:
    io::PollManager poll_manager;
    io::SdpServer sdp_server;

    std::list<SessionDescriptor> session_descriptors;

    // callbacks for SdpServer and SessionSSLServer
    void handle_sdp_server_input();
    void handle_session_input(SessionDescriptor&);

    uint16_t next_tcp_port{50000};

    const TbdConfig config;
};

} // namespace iso15118
