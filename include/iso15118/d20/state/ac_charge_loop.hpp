// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#pragma once

#include "../states.hpp"

namespace iso15118::d20::state {
struct AC_ChargeLoop : public StateBase {
    AC_ChargeLoop(Context& ctx) : StateBase(ctx, StateID::AC_ChargeLoop) {
    }

    void enter() final;

    Result feed(Event) final;

private:
    float target_frequency{0};
    bool stop{false};

    bool first_entry_in_charge_loop{false};
};

} // namespace iso15118::d20::state