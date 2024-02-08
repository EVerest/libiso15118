// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <list>
#include <memory>

#include "config.hpp"
#include "d2_sap/control_event.hpp"
#include "io/poll_manager.hpp"
#include "io/sdp_server.hpp"
#include "session_d2_sap/feedback.hpp"
#include "session_d2_sap/iso.hpp"

#include "message_d2_sap/common.hpp"

namespace iso15118 {


//RDB Parallel universe for iso-2

struct TbdConfig_2_sap {
    config::SSLConfig ssl{config::CertificateBackend::EVEREST_LAYOUT, ""};
    std::string interface_name;
    config::TlsNegotiationStrategy tls_negotiation_strategy{config::TlsNegotiationStrategy::ACCEPT_CLIENT_OFFER};
};

class TbdController_2_sap {
public:
    TbdController_2_sap(TbdConfig_2_sap, session_2_sap::feedback::Callbacks);

    void loop();

    void send_control_event(const d2_sap::ControlEvent&);

    void setup_config();

    void setup_session(const std::vector<message_2_sap::Authorization>& auth_services, bool cert_install_service);

    //RDB Get the Supported Application Protocol that was selected.
    int get_SAP_Version();

    //RDB Get the IConnection so we can pass this to ISO20 or ISO2
    std::unique_ptr<io::IConnection> get_SAP_IConnection(); 

    //RDB Get the Poll manager so we can initialize either the ISO20 or ISO2 poll manager
    io::PollManager GetPollManager();

private:
    io::PollManager poll_manager;
    io::SdpServer sdp_server;

    d2_sap::SessionConfig session_config;

    std::list<Session_2_sap> sessions;

    // callbacks for sdp server
    void handle_sdp_server_input();

    const TbdConfig_2_sap config;
    const session_2_sap::feedback::Callbacks callbacks;
};

} // namespace iso15118
