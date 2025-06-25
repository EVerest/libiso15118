// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#include <iso15118/ev/d20/context.hpp>

#include <iso15118/detail/helper.hpp>

namespace iso15118::ev::d20 {

MessageExchange::MessageExchange(io::StreamOutputView output_) : response(std::move(output_)) {
}

void MessageExchange::set_request(std::unique_ptr<message_20::Variant> new_request) {
    if (request) {
        // FIXME (aw): we might want to have a stack here?
        throw std::runtime_error("Previous V2G message has not been handled yet");
    }

    request = std::move(new_request);
}

std::unique_ptr<message_20::Variant> MessageExchange::pull_request() {
    if (not request) {
        throw std::runtime_error("Tried to access V2G message, but there is none");
    }

    return std::move(request);
}

message_20::Type MessageExchange::peek_request_type() const {
    if (not request) {
        logf_warning("Tried to access V2G message, but there is none");
        return message_20::Type::None;
    }
    return request->get_type();
}

Context::Context(MessageExchange& message_exchange_) : message_exchange(message_exchange_) {
}

std::unique_ptr<message_20::Variant> Context::pull_request() {
    return message_exchange.pull_request();
}

message_20::Type Context::peek_request_type() const {
    return message_exchange.peek_request_type();
}

} // namespace iso15118::ev::d20
