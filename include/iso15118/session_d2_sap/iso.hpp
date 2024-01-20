// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <memory>
#include <optional>

#include <iso15118/config.hpp>

#include <iso15118/d2_sap/config.hpp>
#include <iso15118/d2_sap/context.hpp>
#include <iso15118/d2_sap/control_event_queue.hpp>
#include <iso15118/d2_sap/fsm.hpp>

#include <iso15118/io/connection_abstract.hpp>
#include <iso15118/io/poll_manager.hpp>
#include <iso15118/io/sdp_packet.hpp>
#include <iso15118/io/time.hpp>

#include <iso15118/session_d2_sap/feedback.hpp>
#include <iso15118/session_d2_sap/logger.hpp>

namespace iso15118 {


struct SessionState_2_sap {
    bool connected{false};
    bool new_data{false};
    bool fsm_needs_call{false};
};

//RDB Parallel universe for 15118-2 sap
class Session_2_sap {
public:
    Session_2_sap(std::unique_ptr<io::IConnection>, const d2_sap::SessionConfig&, const session_2_sap::feedback::Callbacks&);
    ~Session_2_sap();

    TimePoint const& poll();
    void push_control_event(const d2_sap::ControlEvent&);

    //RDB Get the selected ap
    int get_SAP_Version();

    //RDB make this public so we can pass it to ISO20 or ISO2
    std::unique_ptr<io::IConnection> connection;

private:
    
    session_2_sap::SessionLogger log;

    SessionState_2_sap state;
    // input buffer
    io::SdpPacket packet;

    // output buffer
    uint8_t response_buffer[1028];

    d2_sap::MessageExchange message_exchange{{response_buffer + io::SdpPacket::V2GTP_HEADER_SIZE,
                                           sizeof(response_buffer) - io::SdpPacket::V2GTP_HEADER_SIZE}};

    // control event buffer
    d2_sap::ControlEventQueue control_event_queue;
    std::optional<d2_sap::ControlEvent> active_control_event{std::nullopt};

    d2_sap::Context ctx;

    d2_sap::Fsm fsm;

    TimePoint next_session_event;

    bool session_stopped{false};

    void handle_connection_event(io::ConnectionEvent event);
};

} // namespace iso15118
