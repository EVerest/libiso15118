// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <fsm/fsm.hpp>

#include "iso2_context.hpp"

namespace iso15118::session::iso2_fsm {

enum class Event {
    RESET,
    NEW_V2GTP_MESSAGE,

    // internal events
    FAILED,
};

using FsmReturnType = int;

using Fsm = fsm::FSM<Event, FsmReturnType>;
using FsmSimpleState = fsm::states::StateWithContext<Fsm::SimpleStateType, Iso2Context>;
using FsmCompoundState = fsm::states::StateWithContext<Fsm::CompoundStateType, Iso2Context>;

class Controller {
public:
    explicit Controller(Iso2Context&);
};

} // namespace iso15118::session::iso2_fsm
