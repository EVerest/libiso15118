// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest

#include <iso15118/states/d2/session_setup.hpp>

namespace iso15118::d2::state {

void SessionSetup::enter() {
    ctx.log.enter_state("SessionSetup");
}

FsmSimpleState::HandleEventReturnType SessionSetup::handle_event(AllocatorType& sa, FsmEvent ev) {

    return sa.PASS_ON;
}

} // namespace iso15118::d2::state
