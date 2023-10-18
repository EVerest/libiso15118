// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include <netinet/in.h>

#include <iso15118/config.hpp>

namespace iso15118::io {

// forward declaration
struct SSLContext;

enum class SessionState {
    ACCEPTING,
    HANDSHAKE,
    CONNECTED,
};

struct ReadResult {
    enum class State {
        WOULD_BLOCK,
        READ_COMPLETE,
        ACCEPTED_SESSION,
    } state{State::WOULD_BLOCK};

    size_t bytes_read{0};
};

class SessionSSLServer {
public:
    SessionSSLServer(const std::string& interface_name, const config::SSLConfig& ssl_config);
    SessionSSLServer(SessionSSLServer&&);
    ReadResult read_data(size_t bytes_to_read, uint8_t* buffer, size_t buffer_len);
    void write_data(const uint8_t* buffer, size_t buffer_len);

    const auto& get_socket_address() {
        return address;
    }
    uint16_t get_port() const;

    int get_fd() const;

    auto get_state() const {
        return state;
    }

    ~SessionSSLServer();

private:
    uint8_t tcp_buffer[2048];

    sockaddr_in6 address;

    std::unique_ptr<SSLContext> ssl;

    SessionState state{SessionState::ACCEPTING};
};

} // namespace iso15118::io
