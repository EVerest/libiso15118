// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/context.hpp>

#include <stdexcept>

namespace iso15118::d20 {

std::unique_ptr<MessageExchange> create_message_exchange(uint8_t* buf, const size_t len) {
    io::StreamOutputView view = {buf, len};
    return std::make_unique<MessageExchange>(std::move(view));
}

MessageExchange::MessageExchange(io::StreamOutputView output_) : response(std::move(output_)) {
}

void MessageExchange::set_request(io::v2gtp::PayloadType payload_type, const io::StreamInputView& stream_view) {
    if (request) {
        // FIXME (aw): we might want to have a stack here?
        throw std::runtime_error("Previous V2G message has not been handled yet");
    }

    request = std::make_unique<message_20::Variant>(payload_type, stream_view);
}

std::unique_ptr<message_20::Variant> MessageExchange::get_request() {
    if (not request) {
        throw std::runtime_error("Tried to access V2G message, but there is none");
    }

    return std::move(request);
}

std::tuple<bool, size_t> MessageExchange::check_and_clear_response() {
    auto retval = std::make_tuple(response_available, response_size);

    response_available = false;
    response_size = 0;

    return retval;
}

Context::Context(MessageExchange& message_exchange_) : message_exchange(message_exchange_){};

std::unique_ptr<message_20::Variant> Context::get_request() {
    return message_exchange.get_request();
}

} // namespace iso15118::d20
