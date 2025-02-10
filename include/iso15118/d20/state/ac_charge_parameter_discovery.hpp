// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include "../states.hpp"

namespace iso15118::d20::state {
struct AC_ChargeParameterDiscovery : public StateBase {
    AC_ChargeParameterDiscovery(Context& ctx) : StateBase(ctx, StateID::AC_ChargeParameterDiscovery) {
    }

    void enter() final;

    Result feed(Event) final;
};

} // namespace iso15118::d20::state