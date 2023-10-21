// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <memory>

#include <iso15118/config.hpp>

#include <iso15118/d20/context.hpp>
#include <iso15118/d20/fsm.hpp>

#include <iso15118/io/connection_abstract.hpp>
#include <iso15118/io/poll_manager.hpp>
#include <iso15118/io/sdp_packet.hpp>
#include <iso15118/io/time.hpp>

#include <iso15118/session/logger.hpp>

namespace iso15118 {

struct SessionConfig {
    config::SSLConfig ssl;
};

struct SessionState {
    bool connected{false};
    bool new_data{false};
    bool fsm_needs_call{false};
};

class Session {
public:
    Session(std::unique_ptr<io::IConnection>, const SessionConfig&);
    ~Session();
    TimePoint const& poll();

private:
    std::unique_ptr<io::IConnection> connection;
    session::SessionLogger session_logger;

    SessionState state;
    // input buffer
    io::SdpPacket packet;

    // output buffer
    uint8_t response_buffer[1028];

    d20::MessageExchange message_exchange{{response_buffer + io::SdpPacket::V2GTP_HEADER_SIZE,
                                           sizeof(response_buffer) - io::SdpPacket::V2GTP_HEADER_SIZE}};

    d20::Context ctx{message_exchange};

    d20::Fsm fsm;

    TimePoint next_session_event;

    void handle_connection_event(io::ConnectionEvent event);
};

} // namespace iso15118
