// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cstdint>

#include <iso15118/io/sdp_packet.hpp>
#include <iso15118/io/session_ssl_server.hpp>

#include "iso2_context.hpp"
#include "iso2_fsm.hpp"

namespace iso15118::session {

// IsoSession should contain the connection handle, and the session state/machine itself

class Iso2 {
public:
    Iso2(io::SessionSSLServer);
    int handle_input();

private:
    // FIXME (aw): this functions parameters could be bundled in a struct
    void handle_v2g_payload(const uint8_t* payload, size_t payload_len, uint16_t payload_type);

    io::SessionSSLServer server;
    io::SdpPacket sdp_packet;

    Iso2Context ctx;
    iso2_fsm::Controller fsm_controller{ctx};
};

} // namespace iso15118::session
