// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cstdint>
#include <string>

#include <netinet/in.h>

namespace iso15118::io {

class SessionServer {
public:
    SessionServer(const std::string& interface_name);
    int wait_for_session();
    const auto& get_socket_address() {
        return address;
    }
    uint16_t get_port();

private:
    int fd{-1};
    uint8_t tcp_buffer[2048];

    sockaddr_in6 address;
};

} // namespace iso15118::io
