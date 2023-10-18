// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <netinet/in.h>

#include "sdp.hpp"

namespace iso15118::io {

struct PeerRequest {
    v2gtp::Security security;
    v2gtp::TransportProtocol transport_protocol;
    struct sockaddr_in6 address;
};

struct PeerResponse {
    PeerResponse() = default;
    PeerResponse(const PeerRequest&, const struct sockaddr_in6& server_address);

    const PeerRequest& request;
    struct sockaddr_in6 server_address;
};

class SdpServer {
public:
    SdpServer();
    PeerRequest get_peer_request();
    void send_response(const PeerResponse& response);

    auto get_fd() const {
        return fd;
    }

private:
    int fd{-1};
    uint8_t udp_buffer[2048];
};

} // namespace iso15118::io
