// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/io/connection_plain.hpp>

#include <cassert>
#include <cstring>

#include <unistd.h>

#include <thread>

#include <iso15118/detail/helper.hpp>
#include <iso15118/detail/io/socket_helper.hpp>

namespace iso15118::io {

ConnectionPlain::ConnectionPlain(PollManager& poll_manager_, const std::string& interface_name) :
    poll_manager(poll_manager_) {
    sockaddr_in6 address;
    if (not get_first_sockaddr_in6_for_interface(interface_name, address)) {
        const auto msg = "Failed to get ipv6 socket address for interface " + interface_name;
        log_and_throw(msg.c_str());
    }

    // setup end point information
    end_point.port = 50000;
    memcpy(&end_point.address, &address.sin6_addr, sizeof(address.sin6_addr));

    fd = socket(AF_INET6, SOCK_STREAM, 0);
    if (fd == -1) {
        log_and_throw("Failed to create an ipv6 socket");
    }

    // before bind, set the port
    address.sin6_port = htobe16(end_point.port);

    const auto bind_result = bind(fd, reinterpret_cast<const struct sockaddr*>(&address), sizeof(address));
    if (bind_result == -1) {
        const auto error = "Failed to bind ipv6 socket to interface " + interface_name;
        log_and_throw(error.c_str());
    }

    const auto listen_result = listen(fd, 0);
    if (listen_result == -1) {
        log_and_throw("Listen on socket failed");
    }

    poll_manager.register_fd(fd, [this]() { this->handle_connect(); });
}

ConnectionPlain::~ConnectionPlain() = default;

void ConnectionPlain::set_event_callback(const ConnectionEventCallback& callback) {
    this->event_callback = callback;
}

Ipv6EndPoint ConnectionPlain::get_public_endpoint() const {
    return end_point;
}

void ConnectionPlain::write(const uint8_t* buf, size_t len) {
    assert(connection_open);

    const auto write_result = ::write(fd, buf, len);

    if (write_result == -1) {
        log_and_throw("Failed to write()");
    } else if (write_result != len) {
        log_and_throw("Could not complete write");
    }
}

ReadResult ConnectionPlain::read(uint8_t* buf, size_t len) {
    assert(connection_open);

    const auto read_result = ::read(fd, buf, len);
    if (read_result > 0) {
        size_t bytes_read = read_result;
        const auto would_block = (bytes_read < len);
        return {would_block, bytes_read};
    }

    if (read_result == -1) {
        // handle blocking read case
        if (errno == EAGAIN) {
            return {true, 0};
        }

        logf("ConnectionPlain::read failed with error code: %d", errno);
    }

    return {false, 0};
}

void ConnectionPlain::handle_connect() {
    // NOTE(aw): we could also determine the remote party here
    const auto accept_fd = accept4(fd, nullptr, nullptr, SOCK_NONBLOCK);
    if (accept_fd == -1) {
        log_and_throw("Failed to accept4");
    }

    poll_manager.unregister_fd(fd);
    ::close(fd);

    call_if_available(event_callback, ConnectionEvent::ACCEPTED);

    connection_open = true;
    call_if_available(event_callback, ConnectionEvent::OPEN);

    fd = accept_fd;
    poll_manager.register_fd(fd, [this]() { this->handle_data(); });
}

void ConnectionPlain::handle_data() {
    assert(connection_open);

    call_if_available(event_callback, ConnectionEvent::NEW_DATA);
}

void ConnectionPlain::close() {

    /* tear down TCP connection gracefully */
    logf("Closing TCP connection\n");

    // Wait for 5 seconds [V2G20-1643]
    std::this_thread::sleep_for(std::chrono::seconds(5));

    const auto shutdown_result = shutdown(fd, SHUT_RDWR);

    if (shutdown_result == -1) {
        log_and_throw("shutdown() failed");
    }

    // Waiting for client closing the connection
    std::this_thread::sleep_for(std::chrono::seconds(2));

    poll_manager.unregister_fd(fd);

    const auto close_shutdown = ::close(fd);

    if (close_shutdown == -1) {
        log_and_throw("close() failed");
    }

    logf("TCP connection closed gracefully");

    connection_open = false;
    call_if_available(event_callback, ConnectionEvent::CLOSED);
}

} // namespace iso15118::io
