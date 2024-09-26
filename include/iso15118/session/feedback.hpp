// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cmath>
#include <functional>
#include <optional>
#include <string>

#include <iso15118/message/type.hpp>

namespace iso15118::session {

namespace feedback {

enum class Signal {
    REQUIRE_AUTH_EIM,
    START_CABLE_CHECK,
    SETUP_FINISHED,
    CHARGE_LOOP_STARTED,
    CHARGE_LOOP_FINISHED,
    DC_OPEN_CONTACTOR,
    DLINK_TERMINATE,
    DLINK_ERROR,
    DLINK_PAUSE,
};

struct DcChargeScheduledMode {
    float target_voltage{NAN};
    float target_current{NAN};
    std::optional<float> target_energy_request;
    std::optional<float> max_energy_request;
    std::optional<float> min_energy_request;
    std::optional<float> max_charge_power;
    std::optional<float> min_charge_power;
    std::optional<float> max_charge_current;
    std::optional<float> max_voltage;
    std::optional<float> min_voltage;
    std::optional<float> max_discharge_power;
    std::optional<float> min_discharge_power;
    std::optional<float> max_discharge_current;
};

struct DcChargeDynamicMode {
    std::optional<uint32_t> departure_time;
    float target_energy_request{NAN};
    float max_energy_request{NAN};
    float min_energy_request{NAN};
    float max_charge_power{NAN};
    float min_charge_power{NAN};
    float max_charge_current{NAN};
    float max_voltage{NAN};
    float min_voltage{NAN};
    std::optional<float> max_discharge_power;
    std::optional<float> min_discharge_power;
    std::optional<float> max_discharge_current;
    std::optional<float> max_v2x_energy_request;
    std::optional<float> min_v2x_energy_request;
};

struct DcMaximumLimits {
    float voltage{NAN};
    float current{NAN};
    float power{NAN};
};

struct DisplayParameters {
    std::optional<float> present_soc;
    std::optional<float> minimum_soc;
    std::optional<float> target_soc;
    std::optional<float> maximum_soc;
    std::optional<float> remaining_time_to_minimum_soc;
    std::optional<float> remaining_time_to_target_soc;
    std::optional<float> remaining_time_to_maximum_soc;
    std::optional<float> battery_energy_capacity;
    std::optional<bool> inlet_hot;
};

struct Callbacks {
    std::function<void(Signal)> signal;
    std::function<void(float)> dc_pre_charge_target_voltage;
    std::function<void(const DcChargeScheduledMode&)> dc_charge_scheduled_mode;
    std::function<void(const DcChargeDynamicMode&)> dc_charge_dynamic_mode;
    std::function<void(const DcMaximumLimits&)> dc_max_limits;
    std::function<void(const message_20::Type&)> v2g_message;
    std::function<void(const std::string&)> evccid;
    std::function<void(const std::string&)> selected_protocol;
    std::function<void(const DisplayParameters&)> display_parameters;
    std::function<void(float)> dc_present_voltage;
    std::function<void(bool)> meter_info_requested;
};

} // namespace feedback

class Feedback {
public:
    Feedback(feedback::Callbacks);

    void signal(feedback::Signal) const;
    void dc_pre_charge_target_voltage(float) const;
    void dc_charge_scheduled_mode(const feedback::DcChargeScheduledMode&) const;
    void dc_charge_dynamic_mode(const feedback::DcChargeDynamicMode&) const;
    void dc_max_limits(const feedback::DcMaximumLimits&) const;
    void v2g_message(const message_20::Type&) const;
    void evcc_id(const std::string&) const;
    void selected_protocol(const std::string&) const;
    void display_parameters(const feedback::DisplayParameters&) const;
    void dc_present_voltage(float) const;
    void meter_info_requested(bool) const;

private:
    feedback::Callbacks callbacks;
};

} // namespace iso15118::session
