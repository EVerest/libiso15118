// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <memory>
#include <optional>

#include <iso15118/config.hpp>

#include <iso15118/d2/config.hpp>
#include <iso15118/d2/context.hpp>
#include <iso15118/d2/control_event_queue.hpp>
#include <iso15118/d2/fsm.hpp>

#include <iso15118/io/connection_abstract.hpp>
#include <iso15118/io/poll_manager.hpp>
#include <iso15118/io/sdp_packet.hpp>
#include <iso15118/io/time.hpp>

#include <iso15118/session_d2/feedback.hpp>
#include <iso15118/session_d2/logger.hpp>

namespace iso15118 {


struct SessionState_2 {
    bool connected{false};
    bool new_data{false};
    bool fsm_needs_call{false};
};

//RDB Parallel universe for 15118-2
class Session_2 {
public:
    Session_2(std::unique_ptr<io::IConnection>, const d2::SessionConfig&, const session_2::feedback::Callbacks&);
    ~Session_2();

    TimePoint const& poll();
    void push_control_event(const d2::ControlEvent&);

private:
    std::unique_ptr<io::IConnection> connection;
    session_2::SessionLogger log;

    SessionState_2 state;
    // input buffer
    io::SdpPacket packet;

    // output buffer
    uint8_t response_buffer[1028];

    d2::MessageExchange message_exchange{{response_buffer + io::SdpPacket::V2GTP_HEADER_SIZE,
                                           sizeof(response_buffer) - io::SdpPacket::V2GTP_HEADER_SIZE}};

    // control event buffer
    d2::ControlEventQueue control_event_queue;
    std::optional<d2::ControlEvent> active_control_event{std::nullopt};

    d2::Context ctx;

    d2::Fsm fsm;

    TimePoint next_session_event;

    bool session_stopped{false};

    void handle_connection_event(io::ConnectionEvent event);
};

} // namespace iso15118
