// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/ac_charge_loop.hpp>

namespace iso15118::d20::state {

void AC_ChargeLoop::enter() {
    m_ctx.log.enter_state("AC_ChargeLoop");
}

Result AC_ChargeLoop::feed(Event ev) {
    if (ev != Event::V2GTP_MESSAGE) {
        return {};
    }

    

    return {};
}

} // namespace iso15118::d20::state
