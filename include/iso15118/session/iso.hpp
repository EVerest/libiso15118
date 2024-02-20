// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <memory>
#include <optional>

#include <iso15118/config.hpp>

#include <iso15118/states/config.hpp>
#include <iso15118/states/context.hpp>
#include <iso15118/states/control_event_queue.hpp>
#include <iso15118/states/fsm.hpp>

#include <iso15118/io/connection_abstract.hpp>
#include <iso15118/io/poll_manager.hpp>
#include <iso15118/io/sdp_packet.hpp>
#include <iso15118/io/time.hpp>

#include <iso15118/session/feedback.hpp>
#include <iso15118/session/logger.hpp>

namespace iso15118 {

struct SessionState {
    bool connected{false};
    bool new_data{false};
    bool fsm_needs_call{false};
};

class Session {
public:
    Session(std::unique_ptr<io::IConnection>, const states::SessionConfig&, const session::feedback::Callbacks&);
    ~Session();

    TimePoint const& poll();
    void push_control_event(const states::ControlEvent&);

private:
    std::unique_ptr<io::IConnection> connection;
    session::SessionLogger log;

    SessionState state;
    // input buffer
    io::SdpPacket packet;

    // output buffer
    uint8_t response_buffer[1028];

    states::MessageExchange message_exchange{{response_buffer + io::SdpPacket::V2GTP_HEADER_SIZE,
                                              sizeof(response_buffer) - io::SdpPacket::V2GTP_HEADER_SIZE}};

    // control event buffer
    states::ControlEventQueue control_event_queue;
    std::optional<states::ControlEvent> active_control_event{std::nullopt};

    states::Context ctx;

    states::Fsm fsm;

    TimePoint next_session_event;

    bool session_stopped{false};

    states::SessionProtocol active_protocol{states::SessionProtocol::ISO15118_20};

    void handle_connection_event(io::ConnectionEvent event);
};

} // namespace iso15118
