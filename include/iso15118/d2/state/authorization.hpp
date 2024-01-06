// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include "../fsm.hpp"
#include <iso15118/message_d2/authorization.hpp>

namespace iso15118::d2::state {

struct Authorization : public FsmSimpleState {
    using FsmSimpleState::FsmSimpleState;

    void enter() final;

    HandleEventReturnType handle_event(AllocatorType&, FsmEvent) final;

private:
    message_2::AuthStatus authorization_status{message_2::AuthStatus::Pending};
};

} // namespace iso15118::d2::state
