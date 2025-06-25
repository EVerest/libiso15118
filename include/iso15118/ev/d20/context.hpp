// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#pragma once

#include <memory>

#include <iso15118/message/common_types.hpp>
#include <iso15118/message/variant.hpp>

#include <iso15118/ev/d20/session.hpp>

namespace iso15118::ev::d20 {

class MessageExchange {
public:
    MessageExchange(io::StreamOutputView);

    void set_request(std::unique_ptr<message_20::Variant> new_request);
    std::unique_ptr<message_20::Variant> pull_request();
    message_20::Type peek_request_type() const;

private:
    // input
    std::unique_ptr<message_20::Variant> request{nullptr};

    // output
    const io::StreamOutputView response;
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

    std::unique_ptr<message_20::Variant> pull_request();
    message_20::Type peek_request_type() const;

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
