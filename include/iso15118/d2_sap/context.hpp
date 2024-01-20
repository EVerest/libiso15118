// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <memory>
#include <optional>
#include <string>
#include <tuple>

#include <iso15118/message_d2_sap/payload_type.hpp>
#include <iso15118/message_d2_sap/variant.hpp>
#include <iso15118/session_d2_sap/feedback.hpp>
#include <iso15118/session_d2_sap/logger.hpp>

#include "config.hpp"
#include "control_event.hpp"
#include "session.hpp"

namespace iso15118::d2_sap{

// forward declare
class ControlEventQueue;

class MessageExchange {
public:
    MessageExchange(io::StreamOutputView);

    void set_request(std::unique_ptr<message_2_sap::Variant> new_request);
    std::unique_ptr<message_2_sap::Variant> get_request();

    template <typename MessageType> void set_response(const MessageType& msg) {
        response_size = message_2_sap::serialize(msg, response);
        response_available = true;
        payload_type = message_2_sap::PayloadTypeTrait<MessageType>::type;
    }

    std::tuple<bool, size_t, io::v2gtp::PayloadType> check_and_clear_response();

private:
    // input
    std::unique_ptr<message_2_sap::Variant> request{nullptr};

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
    Context(MessageExchange&, const std::optional<iso15118::d2_sap::ControlEvent>&, session_2_sap::feedback::Callbacks, bool&,
            session_2_sap::SessionLogger&, const d2_sap::SessionConfig&);

    std::unique_ptr<message_2_sap::Variant> get_request();

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

    const session_2_sap::Feedback feedback;

    session_2_sap::SessionLogger& log;

    Session session;

    const SessionConfig& config;

    bool& session_stopped;

    //RDB add this to pass back the selected app protocol
    int SAP_Version = -1;

private:
    const std::optional<ControlEvent>& current_control_event;
    MessageExchange& message_exchange;
};

} // namespace iso15118::d2_sap
