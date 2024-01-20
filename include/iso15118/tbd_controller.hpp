// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <list>
#include <memory>

#include "config.hpp"
#include "d20/control_event.hpp"
#include "io/poll_manager.hpp"
#include "io/sdp_server.hpp"
#include "session/feedback.hpp"
#include "session/iso.hpp"

#include "message/common.hpp"

namespace iso15118 {

struct TbdConfig {
    config::SSLConfig ssl{config::CertificateBackend::EVEREST_LAYOUT, ""};
    std::string interface_name;
    config::TlsNegotiationStrategy tls_negotiation_strategy{config::TlsNegotiationStrategy::ACCEPT_CLIENT_OFFER};
};

class TbdController {
public:
    TbdController(TbdConfig, session::feedback::Callbacks);

    void loop();

    void send_control_event(const d20::ControlEvent&);

    void setup_config();

    void setup_session(const std::vector<message_20::Authorization>& auth_services, bool cert_install_service);

    //RBD allow to pass in the IConnection made by SAP
    void set_SAP_IConnection(std::unique_ptr<io::IConnection>);

    //RDB also allow to copy the poll manager.
    void set_PollManager(io::PollManager pm);


private:
    io::PollManager poll_manager;
    io::SdpServer sdp_server;

    d20::SessionConfig session_config;

    std::list<Session> sessions;

    // callbacks for sdp server
    void handle_sdp_server_input();

    const TbdConfig config;
    const session::feedback::Callbacks callbacks;
};

} // namespace iso15118
