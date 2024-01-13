// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <list>
#include <memory>

#include "config.hpp"
#include "d2/control_event.hpp"
#include "io/poll_manager.hpp"
#include "io/sdp_server.hpp"
#include "session_d2/feedback.hpp"
#include "session_d2/iso.hpp"

#include "message_d2/common.hpp"

namespace iso15118 {


//RDB Parallel universe for iso-2

struct TbdConfig_2 {
    config::SSLConfig ssl{config::CertificateBackend::EVEREST_LAYOUT, ""};
    std::string interface_name;
    config::TlsNegotiationStrategy tls_negotiation_strategy{config::TlsNegotiationStrategy::ACCEPT_CLIENT_OFFER};
};

class TbdController_2 {
public:
    TbdController_2(TbdConfig_2, session_2::feedback::Callbacks);

    void loop();

    void send_control_event(const d2::ControlEvent&);

    void setup_config();

    void setup_session(const std::vector<message_2::Authorization>& auth_services, bool cert_install_service);

private:
    io::PollManager poll_manager;
    io::SdpServer sdp_server;

    d2::SessionConfig session_config;

    std::list<Session_2> sessions;

    // callbacks for sdp server
    void handle_sdp_server_input();

    const TbdConfig_2 config;
    const session_2::feedback::Callbacks callbacks;
};

} // namespace iso15118
