// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/session/feedback.hpp>

namespace iso15118::d20 {

// Holds information reported by the EV
struct EVSessionInfo {    
    session::feedback::EV_TransferLimits ev_transfer_limits;
    session::feedback::EV_SEControlMode ev_control_mode;
};

} // namespace iso15118::d20