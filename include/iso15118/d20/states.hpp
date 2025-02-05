// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest
#pragma once

#include "context.hpp"

namespace iso15118::d20 {

class Context;

enum class Event {
    RESET,
    V2GTP_MESSAGE,
    CONTROL_MESSAGE,

    // internal events
    FAILED,
};

enum class StateID {
    SupportedAppProtocol,
    SessionSetup,
    AuthorizationSetup,
    SessionStop
};

struct Result {
    constexpr Result() = default;
    Result(BasePointerType result_state) : unhandled(false), new_state(std::move(result_state)) {
    }

    bool unhandled{true};
    BasePointerType new_state{nullptr};
};

struct StateBase {
    using ContainerType = BasePointerType;
    StateBase(StateID id) : m_id(id) {};

    virtual ~StateBase() = default;

    StateID get_id() const {
        return m_id;
    }

    virtual void enter() {};
    virtual Result feed(Event) = 0;
    virtual void leave() {};

private:
    StateID m_id;
};

} // namespace iso15118::d20
