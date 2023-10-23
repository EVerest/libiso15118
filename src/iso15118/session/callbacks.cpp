// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/session/callbacks.hpp>

static std::function<void(float, float)> signal_DC_EVTargetVoltageCurrent_callback{nullptr};

namespace iso15118 {

void signal_DC_EVTargetVoltageCurrent(float voltage, float current) {
    if (signal_DC_EVTargetVoltageCurrent_callback) {
        signal_DC_EVTargetVoltageCurrent_callback(voltage, current);
    }
}

namespace session::callbacks {
void set_dc_ev_target_voltage_current(const std::function<void(float, float)>& callback) {
    signal_DC_EVTargetVoltageCurrent_callback = callback;
}
} // namespace session::callbacks

} // namespace iso15118
