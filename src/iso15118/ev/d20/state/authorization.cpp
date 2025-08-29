// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#include <iso15118/detail/helper.hpp>
#include <iso15118/ev/d20/state/authorization.hpp>
#include <iso15118/ev/detail/d20/context_helper.hpp>
#include <iso15118/message/authorization.hpp>

namespace iso15118::ev::d20::state {

void Authorization::enter() {
    // TODO(SL): Adding logging
}

Result Authorization::feed(Event ev) {
    if (ev != Event::V2GTP_MESSAGE) {
        return {};
    } else {
        return {};
    }
}

} // namespace iso15118::ev::d20::state
