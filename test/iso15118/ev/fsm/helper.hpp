// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#pragma once

#include <array>

#include <iso15118/ev/d20/context.hpp>
#include <iso15118/ev/d20/states.hpp>
#include <iso15118/fsm/fsm.hpp>
#include <iso15118/message/variant.hpp>

using namespace iso15118;

template <typename Msg> std::optional<Msg> check_msg_result(std::optional<ev::d20::MsgResult> result) {

    if (not result.has_value()) {
        return std::nullopt;
    }

    const auto& msg_result = result.value();

    if (msg_result.type != message_20::TypeTrait<Msg>::type or not msg_result.output_message.has_value()) {
        return std::nullopt;
    }

    Msg req{};

    try {
        req = std::any_cast<Msg>(msg_result.output_message);
    } catch (const std::bad_any_cast& ex) {
        return std::nullopt;
    }

    return req;
}

class FsmStateHelper {
public:
    FsmStateHelper() : ctx(msg_exch) {};

    ev::d20::Context& get_context();

    template <typename RequestType> void handle_response(const RequestType& request) {
        msg_exch.set_request(std::make_unique<message_20::Variant>(request));
    }

private:
    // TODO(SL): Check how to remove output_buffer & output_stream_view
    std::array<uint8_t, 1024> output_buffer{};
    io::StreamOutputView output_stream_view{output_buffer.data(), output_buffer.size()};

    ev::d20::MessageExchange msg_exch{output_stream_view};

    ev::d20::Context ctx;
};
