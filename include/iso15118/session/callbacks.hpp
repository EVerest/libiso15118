// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <functional>

namespace iso15118::session::callbacks {

void set_start_cable_check(const std::function<void()>&);
void set_dc_ev_target_voltage_current(const std::function<void(float, float)>&);
void set_v2g_setup_finished(const std::function<void()>&);
void set_dc_charge_loop_started(const std::function<void()>&);
void set_dc_ev_maximum_limits_callback(const std::function<void(float, float, float)>&);

} // namespace iso15118::session::callbacks
