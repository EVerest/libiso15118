// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <memory>
#include <optional>

#include <iso15118/config.hpp>

#include <iso15118/d20/config.hpp>
#include <iso15118/d20/context.hpp>
#include <iso15118/d20/control_event_queue.hpp>
#include <iso15118/d20/fsm.hpp>

#include <iso15118/io/connection_abstract.hpp>
#include <iso15118/io/poll_manager.hpp>
#include <iso15118/io/sdp_packet.hpp>
#include <iso15118/io/time.hpp>

#include <iso15118/session/feedback.hpp>
#include <iso15118/session/logger.hpp>

namespace iso15118 {

//RDB these were never declared in an hpp file but can be reused in iso-2.
static void log_sdp_packet(const iso15118::io::SdpPacket& sdp);
bool read_single_sdp_packet(io::IConnection& connection, io::SdpPacket& sdp_packet);
static size_t setup_response_header(uint8_t* buffer, iso15118::io::v2gtp::PayloadType payload_type, size_t size);

struct SessionState {
    bool connected{false};
    bool new_data{false};
    bool fsm_needs_call{false};
};

class Session {
public:
    Session(std::unique_ptr<io::IConnection>, const d20::SessionConfig&, const session::feedback::Callbacks&);
    ~Session();

    TimePoint const& poll();
    void push_control_event(const d20::ControlEvent&);

    //RDB also allow to set the session state to connected manually.
    void SetSessionStateConnected();


private:
    std::unique_ptr<io::IConnection> connection;
    session::SessionLogger log;

    SessionState state;
    // input buffer
    io::SdpPacket packet;

    // output buffer
    uint8_t response_buffer[1028];

    d20::MessageExchange message_exchange{{response_buffer + io::SdpPacket::V2GTP_HEADER_SIZE,
                                           sizeof(response_buffer) - io::SdpPacket::V2GTP_HEADER_SIZE}};

    // control event buffer
    d20::ControlEventQueue control_event_queue;
    std::optional<d20::ControlEvent> active_control_event{std::nullopt};

    d20::Context ctx;

    d20::Fsm fsm;

    TimePoint next_session_event;

    bool session_stopped{false};

    void handle_connection_event(io::ConnectionEvent event);
};

} // namespace iso15118
