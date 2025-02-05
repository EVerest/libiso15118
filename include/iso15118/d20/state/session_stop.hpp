// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include "../states.hpp"

namespace iso15118::d20::state {

struct SessionStop : public StateBase {
    SessionStop(Context& ctx) : StateBase(StateID::SessionStop), m_ctx(ctx){};

    void enter() final;

    Result feed(Event) final;

private:
    Context& m_ctx;
};

} // namespace iso15118::d20::state
