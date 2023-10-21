// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <list>
#include <memory>

#include "io/poll_manager.hpp"
#include "io/sdp_server.hpp"
// #include "session/d20.hpp"
#include "config.hpp"
#include "session/iso.hpp"

namespace iso15118 {

struct TbdConfig {
    config::SSLConfig ssl{config::CertificateBackend::EVEREST_LAYOUT, ""};
    std::string interface_name;
    config::TlsNegotiationStrategy tls_negotiation_strategy{config::TlsNegotiationStrategy::ACCEPT_CLIENT_OFFER};
};

class TbdController {
public:
    TbdController();
    explicit TbdController(TbdConfig);

    void loop();

private:
    io::PollManager poll_manager;
    io::SdpServer sdp_server;

    std::list<Session> sessions;

    // callbacks for sdp server
    void handle_sdp_server_input();

    const TbdConfig config;
};

} // namespace iso15118
