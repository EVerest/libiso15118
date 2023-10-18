// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/io/session_server.hpp>

#include <cstring>

#include <ifaddrs.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iso15118/detail/helper.hpp>

namespace iso15118::io {

SessionServer::SessionServer(const std::string& interface_name) {
    struct ifaddrs* if_list_head;
    const auto get_if_addrs_result = getifaddrs(&if_list_head);

    if (get_if_addrs_result == -1) {
        log_and_throw("Failed to call getifaddrs");
    }
    auto current_if = if_list_head;

    for (auto current_if = if_list_head; current_if != nullptr; current_if = current_if->ifa_next) {
        if (current_if->ifa_addr->sa_family != AF_INET6) {
            continue;
        }

        if (interface_name.compare(current_if->ifa_name) != 0) {
            continue;
        }

        // matching interface name and ipv6
        // FIXME (aw): is this cast allowed (alignment)
        const auto& socket_address = reinterpret_cast<const struct sockaddr_in6&>(*current_if->ifa_addr);
        memcpy(&address, &socket_address, sizeof(address));
    }

    freeifaddrs(if_list_head);

    fd = socket(AF_INET6, SOCK_STREAM, 0);

    if (fd == -1) {
        log_and_throw("Failed to open socket");
    }

    // we need to select some random ports and then check via EADDRINUSE if it is available
    // FIXME (aw): for now only use fixed port number
    address.sin6_port = htobe16(50000);

    const auto bind_result = bind(fd, reinterpret_cast<const struct sockaddr*>(&address), sizeof(address));
    if (bind_result == -1) {
        log_and_throw("Failed to bind to socket");
    }

    const auto listen_result = listen(fd, 0);
    if (listen_result == -1) {
        log_and_throw("Listen on socket failed");
    }
}

uint16_t SessionServer::get_port() {
    return be16toh(address.sin6_port);
}

int SessionServer::wait_for_session() {

    struct sockaddr_in6 peer_address;
    socklen_t peer_address_len = sizeof(peer_address);

    const auto accept_result = accept(fd, reinterpret_cast<struct sockaddr*>(&peer_address), &peer_address_len);
    if (accept_result == -1) {
        log_and_throw("Accept on socket failed");
    }

    logf("Accepted a connection\n");

    return accept_result;
}

} // namespace iso15118::io
