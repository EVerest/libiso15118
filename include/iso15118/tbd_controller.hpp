// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <list>
#include <memory>
#include <string>
#include <vector>

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
    bool enable_sdp_server{true};
};

// FIXME(sl): Integrate in TbdConfig?
struct EvseSetupConfig {
    std::string evse_id;
    std::vector<message_20::ServiceCategory> supported_energy_services;
    std::vector<message_20::Authorization> authorization_services;
    bool enable_certificate_install_service;
};

class TbdController {
public:
    TbdController(TbdConfig, session::feedback::Callbacks, EvseSetupConfig);

    void loop();

    void send_control_event(const d20::ControlEvent&);

    void update_authorization_services(const std::vector<message_20::Authorization>& services,
                                       bool cert_install_service);

private:
    io::PollManager poll_manager;
    std::unique_ptr<io::SdpServer> sdp_server;

    std::unique_ptr<Session> session;

    // callbacks for sdp server
    void handle_sdp_server_input();

    const TbdConfig config;
    const session::feedback::Callbacks callbacks;

    EvseSetupConfig evse_setup;
};

} // namespace iso15118
