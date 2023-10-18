// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/io/sdp_server.hpp>

#include <cstring>
#include <type_traits>

#include <exi/cb/exi_v2gtp.h>

#include <iso15118/detail/helper.hpp>

namespace iso15118::io {

PeerResponse::PeerResponse(const PeerRequest& request_, const struct sockaddr_in6& address_) :
    request(request_), server_address(address_) {
}

SdpServer::SdpServer() {
    fd = socket(AF_INET6, SOCK_DGRAM, 0);

    if (fd == -1) {
        log_and_throw("Failed to open socket");
    }

    // initialize socket address, leave scope_id and flowinfo at 0
    struct sockaddr_in6 socket_address;
    bzero(&socket_address, sizeof(socket_address));
    socket_address.sin6_family = AF_INET6;
    socket_address.sin6_port = htobe16(v2gtp::SDP_SERVER_PORT);
    memcpy(&socket_address.sin6_addr, &in6addr_any, sizeof(socket_address.sin6_addr));

    const auto bind_result =
        bind(fd, reinterpret_cast<const struct sockaddr*>(&socket_address), sizeof(socket_address));
    if (bind_result == -1) {
        log_and_throw("Failed to bind to socket");
    }
}

PeerRequest SdpServer::get_peer_request() {
    PeerRequest peer_request;
    socklen_t peer_addr_len = sizeof(peer_request.address);

    const auto read_result = recvfrom(fd, udp_buffer, sizeof(udp_buffer), 0,
                                      reinterpret_cast<struct sockaddr*>(&peer_request.address), &peer_addr_len);
    if (read_result <= 0) {
        log_and_throw("Read on socket failed");
    }

    if (read_result == sizeof(udp_buffer)) {
        log_and_throw("Read success, but reached maximum size of buffer");
    }

    logf("Received %d bytes on udp socket\n", read_result);

    uint32_t sdp_payload_len;
    const auto parse_sdp_result = V2GTP20_ReadHeader(udp_buffer, &sdp_payload_len, V2GTP20_SDP_REQUEST_PAYLOAD_ID);

    if (parse_sdp_result != V2GTP_ERROR__NO_ERROR) {
        log_and_throw("Failed to parse sdp header");
    }

    const uint8_t sdp_request_byte1 = udp_buffer[8];
    const uint8_t sdp_request_byte2 = udp_buffer[9];
    peer_request.security = static_cast<v2gtp::Security>(sdp_request_byte1);
    peer_request.transport_protocol = static_cast<v2gtp::TransportProtocol>(sdp_request_byte2);

    return peer_request;
}

void SdpServer::send_response(const PeerResponse& response) {
    // that worked, now response
    uint8_t v2g_packet[28];
    uint8_t* sdp_response = v2g_packet + 8;
    // fill in our ipv6 addr (FIXME (aw): should be a specific one, not just the loopback!)
    memcpy(sdp_response, &response.server_address.sin6_addr, sizeof(response.server_address.sin6_addr));
    const uint16_t port = response.server_address.sin6_port;
    memcpy(sdp_response + 16, &port, sizeof(port));

    // FIXME (aw): which values to take here?
    sdp_response[18] = static_cast<std::underlying_type_t<v2gtp::Security>>(response.request.security);
    sdp_response[19] =
        static_cast<std::underlying_type_t<v2gtp::TransportProtocol>>(response.request.transport_protocol);

    V2GTP20_WriteHeader(v2g_packet, 20, V2GTP20_SDP_RESPONSE_PAYLOAD_ID);

    const auto peer_addr_len = sizeof(response.request.address);

    sendto(fd, v2g_packet, sizeof(v2g_packet), 0, reinterpret_cast<const sockaddr*>(&response.request.address),
           peer_addr_len);
}

#if 0

void parse_sdp_request(uint8_t* packet) {
    // check sdp header
    uint32_t sdp_payload_len;
    const auto parse_sdp_result = V2GTP20_ReadHeader(packet, &sdp_payload_len, V2GTP20_SDP_REQUEST_PAYLOAD_ID);

    if (parse_sdp_result != V2GTP_ERROR__NO_ERROR) {
        log_and_throw("Failed to parse sdp header");
    }

    logf("Got sdp payload of %d bytes\n", sdp_payload_len);
    const uint8_t sdp_request_byte1 = packet[8];

    switch (static_cast<v2gtp::Security>(sdp_request_byte1)) {
    case v2gtp::Security::TLS:
        logf(" -> TLS requested\n");
        break;
    case v2gtp::Security::NO_TRANSPORT_SECURITY:
        logf(" -> no security\n");
        break;
    default:
        logf(" -> EXCEPTION: reserved value\n");
        break;
    }

    const uint8_t sdp_request_byte2 = packet[9];
    switch (static_cast<v2gtp::TransportProtocol>(sdp_request_byte2)) {
    case v2gtp::TransportProtocol::TCP:
        logf(" -> TCP requested\n");
        break;
    case v2gtp::TransportProtocol::RESERVED_FOR_UDP:
        logf(" -> reserved for UDP\n");
        break;
    default:
        logf(" -> EXCEPTION: reserved value\n");
        break;
    }
}
#endif

} // namespace iso15118::io
