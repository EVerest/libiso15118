// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#include <iso15118/ev/d20/state/authorization_setup.hpp>

namespace iso15118::ev::d20::state {

void AuthorizationSetup::enter() {
}

Result AuthorizationSetup::feed([[maybe_unused]] Event ev) {
    return {};
}

} // namespace iso15118::ev::d20::state
