// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <memory>
#include <optional>
#include <string>
#include <tuple>

#include <iso15118/message_d2/payload_type.hpp>
#include <iso15118/message_d2/variant.hpp>
#include <iso15118/session_d2/feedback.hpp>
#include <iso15118/session_d2/logger.hpp>

#include "config.hpp"
#include "control_event.hpp"
#include "session.hpp"

namespace iso15118::d2 {

// forward declare
class ControlEventQueue;

class MessageExchange {
public:
    MessageExchange(io::StreamOutputView);

    void set_request(std::unique_ptr<message_2::Variant> new_request);
    std::unique_ptr<message_2::Variant> get_request();

    template <typename MessageType> void set_response(const MessageType& msg) {
        response_size = message_2::serialize(msg, response);
        response_available = true;
        payload_type = message_2::PayloadTypeTrait<MessageType>::type;
    }

    std::tuple<bool, size_t, io::v2gtp::PayloadType> check_and_clear_response();

private:
    // input
    std::unique_ptr<message_2::Variant> request{nullptr};

    // output
    const io::StreamOutputView response;
    size_t response_size{0};
    bool response_available{false};
    io::v2gtp::PayloadType payload_type;
};

std::unique_ptr<MessageExchange> create_message_exchange(uint8_t* buf, const size_t len);

class Context {
public:
    // FIXME (aw): bundle arguments
    Context(MessageExchange&, const std::optional<iso15118::d2::ControlEvent>&, session_2::feedback::Callbacks, bool&,
            session_2::SessionLogger&, const d2::SessionConfig&);

    std::unique_ptr<message_2::Variant> get_request();

    template <typename MessageType> void respond(const MessageType& msg) {
        message_exchange.set_response(msg);
    }

    const auto& get_control_event() {
        return current_control_event;
    }

    template <typename T> T const* get_control_event() {
        if (not current_control_event.has_value()) {
            return nullptr;
        }

        if (not std::holds_alternative<T>(*current_control_event)) {
            return nullptr;
        }

        return &std::get<T>(*current_control_event);
    }

    const session_2::Feedback feedback;

    session_2::SessionLogger& log;

    Session session;

    const SessionConfig& config;

    bool& session_stopped;

private:
    const std::optional<ControlEvent>& current_control_event;
    MessageExchange& message_exchange;
};

} // namespace iso15118::d2
