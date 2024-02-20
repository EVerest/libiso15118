// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <variant>

#include <iostream>

#include <iso15118/message_d2/variant.hpp>
#include <iso15118/message_d20/payload_type.hpp>
#include <iso15118/message_d20/variant.hpp>
#include <iso15118/session/feedback.hpp>
#include <iso15118/session/logger.hpp>

#include "config.hpp"
#include "control_event.hpp"
#include "session.hpp"

namespace iso15118::states {

enum class SessionProtocol {
    DIN70121,
    ISO15118_2,
    ISO15118_20,
};

// forward declare
class ControlEventQueue;

using UniqueVariants = std::variant<std::unique_ptr<message_2::Variant>, std::unique_ptr<message_20::Variant>>;

class MessageExchange {
public:
    MessageExchange(io::StreamOutputView);

    template <typename T> void set_request(T new_request) {

        if (std::holds_alternative<T>(request)) {
            if (std::get<T>(request)) {
                // FIXME (aw): we might want to have a stack here?
                throw std::runtime_error("Previous V2G message has not been handled yet");
            }
        }

        request = std::move(new_request);
    }

    template <typename T> T get_request() {

        if (not std::holds_alternative<T>(request)) {
            throw std::runtime_error("Tried to access V2G message, but this is the wrong message type");
        }

        if (not std::get<T>(request)) {
            throw std::runtime_error("Tried to access V2G message, but there is none");
        }

        return std::move(std::get<T>(request));
    }

    template <typename MessageType> void set_response(const MessageType& msg, bool d20_active) {
        response_size = serialize(msg, response);
        response_available = true;
        payload_type = io::v2gtp::PayloadType::SAP;
        if (d20_active) {
            payload_type = message_20::PayloadTypeTrait<MessageType>::type;
        }
    }

    std::tuple<bool, size_t, io::v2gtp::PayloadType> check_and_clear_response();

private:
    // input
    UniqueVariants request;

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
    Context(MessageExchange&, const std::optional<ControlEvent>&, session::feedback::Callbacks, bool&,
            session::SessionLogger&, const states::SessionConfig&, SessionProtocol&);

    template <typename T> std::unique_ptr<T> get_request() {
        return message_exchange.get_request<std::unique_ptr<T>>();
    }

    template <typename MessageType> void respond(const MessageType& msg, bool d20_active) {
        message_exchange.set_response(msg, d20_active);
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

    void set_active_protocol(SessionProtocol protocol) {
        active_protocol = protocol;
    }

    const session::Feedback feedback;

    session::SessionLogger& log;

    Session session;

    const SessionConfig& config;

    bool& session_stopped;

private:
    const std::optional<ControlEvent>& current_control_event;
    MessageExchange& message_exchange;

    SessionProtocol& active_protocol;
};

} // namespace iso15118::states
