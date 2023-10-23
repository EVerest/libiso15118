// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/session/callbacks.hpp>

// Todo(sl): Defince callback struct
static std::function<void()> signal_dc_charge_loop_started_callback{nullptr};
static std::function<void()> signal_v2g_setup_finished_callback{nullptr};
static std::function<void(float, float)> signal_DC_EVTargetVoltageCurrent_callback{nullptr};
static std::function<void(float, float, float)> signal_dc_ev_maximum_limits_callback{nullptr};

namespace iso15118 {

void signal_DC_EVTargetVoltageCurrent(float voltage, float current) {
    if (signal_DC_EVTargetVoltageCurrent_callback) {
        signal_DC_EVTargetVoltageCurrent_callback(voltage, current);
    }
}

void signal_v2g_setup_finished() {
    if (signal_v2g_setup_finished_callback) {
        signal_v2g_setup_finished_callback();
    }
}

void signal_dc_charge_loop_started() {
    if (signal_dc_charge_loop_started_callback) {
        signal_dc_charge_loop_started_callback();
    }
}

namespace session::callbacks {
void set_dc_ev_target_voltage_current(const std::function<void(float, float)>& callback) {
    signal_DC_EVTargetVoltageCurrent_callback = callback;
}

void set_v2g_setup_finished(const std::function<void()>& callback) {
    signal_v2g_setup_finished_callback = callback;
}

void set_dc_charge_loop_started(const std::function<void()>& callback) {
    signal_dc_charge_loop_started_callback = callback;
}

void set_dc_ev_maximum_limits_callback(const std::function<void(float, float, float)>& callback) {
    signal_dc_ev_maximum_limits_callback = callback;
}

} // namespace session::callbacks

} // namespace iso15118
