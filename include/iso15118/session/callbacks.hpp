// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <functional>

namespace iso15118::session::callbacks {

void set_dc_ev_target_voltage_current(const std::function<void(float, float)>&);

} // namespace iso15118::session::callbacks
