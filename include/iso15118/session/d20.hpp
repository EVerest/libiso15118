// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cstdint>
#include <memory>

#include <iso15118/io/sdp_packet.hpp>
#include <iso15118/io/session_ssl_server.hpp>

#include <iso15118/d20/context.hpp>
#include <iso15118/d20/fsm.hpp>

namespace iso15118::session {

// IsoSession should contain the connection handle, and the session state/machine itself

class D20Session {
public:
    D20Session(io::SessionSSLServer);
    int handle_input();

private:
    // FIXME (aw): this functions parameters could be bundled in a struct
    void handle_v2g_payload();

    io::SessionSSLServer server;
    io::SdpPacket sdp_packet;

    // the splitting here might need some more thought,  the same sdp_packet might be directly reused
    uint8_t response_buffer[1028];
    d20::MessageExchange message_exchange{{response_buffer + io::SdpPacket::V2GTP_HEADER_SIZE,
                                           sizeof(response_buffer) - io::SdpPacket::V2GTP_HEADER_SIZE}};

    d20::Context ctx{message_exchange};

    d20::Fsm fsm;

    // iso20_fsm::Controller fsm_controller{ctx};
};

} // namespace iso15118::session
