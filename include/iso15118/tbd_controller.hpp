// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <atomic>
#include <list>
#include <memory>
#include <optional>

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

class TbdController {
public:
    TbdController(TbdConfig, session::feedback::Callbacks);

    void loop();

    void send_control_event(const d20::ControlEvent&);

    void setup_config(const std::string&, const std::vector<message_20::ServiceCategory>&);

    void setup_session(const std::vector<message_20::Authorization>&, bool);

    void update_dc_max_values(float, float, float, std::optional<float>, std::optional<float>);

    void update_dc_min_values(float, float, float, std::optional<float>, std::optional<float>);

private:
    io::PollManager poll_manager;
    io::SdpServer sdp_server;

    d20::SessionConfig session_config;

    std::unique_ptr<Session> session;
    std::atomic_bool session_active{false};

    // callbacks for sdp server
    void handle_sdp_server_input();

    const TbdConfig config;
    const session::feedback::Callbacks callbacks;
};

} // namespace iso15118
