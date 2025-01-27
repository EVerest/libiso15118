// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once
#include <string>

#include "../states.hpp"

namespace iso15118::d20::state {

struct SessionSetup : public StateBase {
    SessionSetup(Context& ctx) : StateBase(StateID::SessionSetup), m_ctx(ctx) {};

    void enter() final;

    Result feed(Event) final;

private:
    Context& m_ctx;
    std::string evse_id;
};

} // namespace iso15118::d20::state
