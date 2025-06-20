// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include "../states.hpp"

namespace iso15118::d20::state {

struct ServiceSelection : public StateBase {
public:
    ServiceSelection(Context& ctx) : StateBase(ctx, StateID::ServiceSelection) {
    }

    void enter() final;

    Result feed(Event) final;

private:
    bool stop{false};
};

} // namespace iso15118::d20::state
