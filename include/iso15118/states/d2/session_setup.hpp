// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once
#include <string>

#include "../fsm.hpp"

namespace iso15118::d2::state {

using namespace states;

struct SessionSetup : public FsmSimpleState {
    using FsmSimpleState::FsmSimpleState;

    void enter() final;

    HandleEventReturnType handle_event(AllocatorType&, FsmEvent) final;

private:
    std::string evse_id;
};


} // namespace iso15118::d2::state
