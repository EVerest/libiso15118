// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#pragma once

#include <any>
#include <optional>

#include "context.hpp"
#include <iso15118/message/type.hpp>

namespace iso15118::ev::d20 {

// FIXME(SL): Copied directly from d20/states.hpp. This should be refactored!

class Context;

enum class Event {
    RESET,
    V2GTP_MESSAGE,
    CONTROL_MESSAGE,

    // internal events
    FAILED,
};

struct MsgResult {
    message_20::Type type{message_20::Type::None};
    std::any output_message;
};

enum class StateID {
    SupportedAppProtocol,
    SessionSetup,
    AuthorizationSetup,
    Authorization,
    ServiceDetail,
    ServiceDiscovery,
    ServiceSelection,
    AC_ChargeParameterDiscovery,
    AC_ChargeLoop,
    DC_ChargeParameterDiscovery,
    DC_PreCharge,
    DC_ChargeLoop,
    DC_WeldingDetection,
    DC_CableCheck,
    PowerDelivery,
    ScheduleExchange,
    SessionStop
};

struct Result {
    constexpr Result() = default;
    Result(BasePointerType result_state, std::optional<MsgResult> output_) :
        unhandled(false), new_state(std::move(result_state)), output(std::move(output_)) {
    }

    bool unhandled{true};
    BasePointerType new_state{nullptr};
    std::optional<MsgResult> output{std::nullopt};
};

struct StateBase {
    using ContainerType = BasePointerType;
    using EventType = Event;

    StateBase(Context& ctx, StateID id) : m_ctx(ctx), m_id(id) {};

    virtual ~StateBase() = default;

    StateID get_id() const {
        return m_id;
    }

    virtual void enter() {};
    virtual Result feed(Event) = 0;
    virtual void leave() {};

protected:
    Context& m_ctx;

private:
    StateID m_id;
};

} // namespace iso15118::ev::d20
