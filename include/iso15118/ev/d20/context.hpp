// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#pragma once

#include <any>
#include <memory>

#include <iso15118/message/common_types.hpp>
#include <iso15118/message/variant.hpp>

#include <iso15118/ev/d20/session.hpp>

namespace iso15118::ev::d20 {

class MessageExchange {
public:
    MessageExchange(io::StreamOutputView);

    void set_response(std::unique_ptr<message_20::Variant> new_request);
    std::unique_ptr<message_20::Variant> pull_response();
    message_20::Type peek_response_type() const;

    template <typename MessageType> void set_request(const MessageType& msg) {
        // TODO(SL): Adding serialize

        request_type = message_20::TypeTrait<MessageType>::type;
        request_message = msg;
    }

    template <typename Msg> std::optional<Msg> get_request() {
        static_assert(message_20::TypeTrait<Msg>::type != message_20::Type::None, "Unhandled type!");
        if (message_20::TypeTrait<Msg>::type != request_type) {
            return std::nullopt;
        }
        try {
            return std::any_cast<Msg>(request_message);
        } catch (const std::bad_any_cast& ex) {
            return std::nullopt;
        }
    }

private:
    // input
    std::unique_ptr<message_20::Variant> response{nullptr};

    // output
    const io::StreamOutputView request;
    message_20::Type request_type;
    std::any request_message;
};

struct StateBase;
using BasePointerType = std::unique_ptr<StateBase>;
class Session;

class Context {
public:
    Context(MessageExchange&);

    template <typename StateType, typename... Args> BasePointerType create_state(Args&&... args) {
        return std::make_unique<StateType>(*this, std::forward<Args>(args)...);
    }

    std::unique_ptr<message_20::Variant> pull_response();
    message_20::Type peek_response_type() const;

    template <typename MessageType> void respond(const MessageType& msg) {
        message_exchange.set_request(msg);
    }

    template <typename Msg> std::optional<Msg> get_request() {
        return message_exchange.get_request<Msg>();
    }

    void stop_session(bool stop) {
        session_stopped = stop;
    }

    message_20::datatypes::Identifier get_evcc_id() {
        return evcc_id;
    }

    Session& get_session() {
        return session;
    }

private:
    MessageExchange& message_exchange;

    // TODO(Sl): How to set evcc_id on startup and in which format (Identifier is a string)
    message_20::datatypes::Identifier evcc_id{};

    Session session{std::array<uint8_t, Session::ID_LENGTH>{}};

    bool session_stopped{false};
};

} // namespace iso15118::ev::d20
