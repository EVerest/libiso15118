// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <memory>
#include <optional>
#include <string>
#include <tuple>

#include <iso15118/message/variant.hpp>
#include <iso15118/shared/fsm_logger.hpp>

#include "config.hpp"
#include "control_event.hpp"
#include "session.hpp"

namespace iso15118::d20 {

// forward declare
class ControlEventQueue;

class MessageExchange {
public:
    MessageExchange(io::StreamOutputView);

    void set_request(io::v2gtp::PayloadType, const io::StreamInputView&);
    std::unique_ptr<message_20::Variant> get_request();

    template <typename MessageType> void set_response(const MessageType& msg) {
        response_size = message_20::serialize(msg, response);
        response_available = true;
    }

    std::tuple<bool, size_t> check_and_clear_response();

private:
    // input
    std::unique_ptr<message_20::Variant> request{nullptr};

    // output
    const io::StreamOutputView response;
    size_t response_size{0};
    bool response_available{false};
};

std::unique_ptr<MessageExchange> create_message_exchange(uint8_t* buf, const size_t len);

class Context {
public:
    Context(MessageExchange&, ControlEventQueue&);

    std::unique_ptr<message_20::Variant> get_request();

    std::optional<ControlEvent> get_next_control_event();

    template <typename MessageType> void respond(const MessageType& msg) {
        message_exchange.set_response(msg);
    }

    const shared::FsmLogger log{"FSM20"};

    Session session;

    Config config;

private:
    MessageExchange& message_exchange;
    ControlEventQueue& control_events;
};

} // namespace iso15118::d20
