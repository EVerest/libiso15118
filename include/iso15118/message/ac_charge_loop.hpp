// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include <variant>

#include "common_types.hpp"

namespace iso15118::message_20 {

namespace datatypes {

struct ApparentPower {
    std::optional<Phase> max_charge_apparent_power;
    std::optional<Phase> max_discharge_apparent_power;
};

struct ReactivePower {
    std::optional<Phase> max_charge_reactive_power;
    std::optional<Phase> min_charge_reactive_power;
    std::optional<Phase> max_discharge_reactive_power;
    std::optional<Phase> min_discharge_reactive_power;
};

struct Excitation {
    std::optional<RationalNumber> over_excited_maximum_discharge_power;
    std::optional<RationalNumber> over_excited_power_factor;
    std::optional<RationalNumber> under_excited_maximum_discharge_power;
    std::optional<RationalNumber> under_excited_power_factor;
};

struct SetPoints {
    std::optional<RationalNumber> set_nominal_voltage;
    std::optional<RationalNumber> set_nominal_voltage_offset;
    std::optional<RationalNumber> set_max_nominal_voltage;
    std::optional<RationalNumber> set_min_nonimal_voltage;
};

enum class DERFunctionName {
    EnterService,
    HFTrip,
    LFTrip,
    HVTrip,
    LVTrip,
    FrequencyDroop,
    FrequencyWatt,
    VoltWatt,
    LimitMaxPower,
    ConstantPFInjection,
    ConstantPFAbsorption,
    ConstantVarInjection,
    ConstantVarAbsorption,
    VoltVar,
    WattVar,
    WattCosPhi,
};

enum class GridEventFault {
    OverCurrent,
    OverVoltage,
    UnderVoltage,
    OverFrequency,
    UnderFrequency,
    VoltageImbalance,
    CurrentImbalance,
    EmergencyLocal,
    LowPowerInput,
    PhaseRotation,
};

struct DERGridSupportActiveInfo {
    std::optional<DERFunctionName> der_function_name;
    std::optional<GridEventFault> grid_event_fault;
    std::optional<std::string> extra_info;
    bool event_condition;
};

struct Scheduled_AC_CLReqControlMode : Scheduled_CLReqControlMode {
    std::optional<RationalNumber> max_charge_power;
    std::optional<RationalNumber> max_charge_power_L2;
    std::optional<RationalNumber> max_charge_power_L3;
    std::optional<RationalNumber> min_charge_power;
    std::optional<RationalNumber> min_charge_power_L2;
    std::optional<RationalNumber> min_charge_power_L3;
    RationalNumber present_active_power;
    std::optional<RationalNumber> present_active_power_L2;
    std::optional<RationalNumber> present_active_power_L3;
    std::optional<RationalNumber> present_reactive_power;
    std::optional<RationalNumber> present_reactive_power_L2;
    std::optional<RationalNumber> present_reactive_power_L3;
};

struct BPT_Scheduled_AC_CLReqControlMode : Scheduled_AC_CLReqControlMode {
    std::optional<RationalNumber> max_discharge_power;
    std::optional<RationalNumber> max_discharge_power_L2;
    std::optional<RationalNumber> max_discharge_power_L3;
    std::optional<RationalNumber> min_discharge_power;
    std::optional<RationalNumber> min_discharge_power_L2;
    std::optional<RationalNumber> min_discharge_power_L3;
};

struct DER_Scheduled_AC_CLReqControlMode : Scheduled_AC_CLReqControlMode {
    Phase max_discharge_power;
    Phase min_discharge_power;
    std::optional<RationalNumber> session_total_discharge_energy_available;
    std::optional<ApparentPower> apparent_power;
    std::optional<ReactivePower> reactive_power;
    std::optional<Excitation> excitation;
    std::optional<SetPoints> set_points;
    std::optional<Phase> present_voltage;
    std::optional<Phase> present_frequency;
    std::optional<DERGridSupportActiveInfo> der_grid_support_active_info;
};

struct Dynamic_AC_CLReqControlMode : Dynamic_CLReqControlMode {
    RationalNumber max_charge_power;
    std::optional<RationalNumber> max_charge_power_L2;
    std::optional<RationalNumber> max_charge_power_L3;
    RationalNumber min_charge_power;
    std::optional<RationalNumber> min_charge_power_L2;
    std::optional<RationalNumber> min_charge_power_L3;
    RationalNumber present_active_power;
    std::optional<RationalNumber> present_active_power_L2;
    std::optional<RationalNumber> present_active_power_L3;
    RationalNumber present_reactive_power;
    std::optional<RationalNumber> present_reactive_power_L2;
    std::optional<RationalNumber> present_reactive_power_L3;
};

struct BPT_Dynamic_AC_CLReqControlMode : Dynamic_AC_CLReqControlMode {
    RationalNumber max_discharge_power;
    std::optional<RationalNumber> max_discharge_power_L2;
    std::optional<RationalNumber> max_discharge_power_L3;
    RationalNumber min_discharge_power;
    std::optional<RationalNumber> min_discharge_power_L2;
    std::optional<RationalNumber> min_discharge_power_L3;
    std::optional<RationalNumber> max_v2x_energy_request;
    std::optional<RationalNumber> min_v2x_energy_request;
};

struct DER_Dynamic_AC_CLReqControlMode : Dynamic_AC_CLReqControlMode {
    Phase max_discharge_power;
    Phase min_discharge_power;
    std::optional<RationalNumber> session_total_discharge_energy_available;
    std::optional<ApparentPower> apparent_power;
    std::optional<ReactivePower> reactive_power;
    std::optional<Excitation> excitation;
    std::optional<SetPoints> set_points;
    std::optional<Phase> present_voltage;
    std::optional<Phase> present_frequency;
    std::optional<DERGridSupportActiveInfo> der_grid_support_active_info;
};

struct Scheduled_AC_CLResControlMode : Scheduled_CLResControlMode {
    std::optional<RationalNumber> target_active_power;
    std::optional<RationalNumber> target_active_power_L2;
    std::optional<RationalNumber> target_active_power_L3;
    std::optional<RationalNumber> target_reactive_power;
    std::optional<RationalNumber> target_reactive_power_L2;
    std::optional<RationalNumber> target_reactive_power_L3;
    std::optional<RationalNumber> present_active_power;
    std::optional<RationalNumber> present_active_power_L2;
    std::optional<RationalNumber> present_active_power_L3;
};

struct BPT_Scheduled_AC_CLResControlMode : Scheduled_AC_CLResControlMode {};

struct DER_Scheduled_AC_CLResControlMode : Scheduled_AC_CLResControlMode {
    std::optional<DERControl> der_control;
};

struct Dynamic_AC_CLResControlMode : Dynamic_CLResControlMode {
    RationalNumber target_active_power;
    std::optional<RationalNumber> target_active_power_L2;
    std::optional<RationalNumber> target_active_power_L3;
    std::optional<RationalNumber> target_reactive_power;
    std::optional<RationalNumber> target_reactive_power_L2;
    std::optional<RationalNumber> target_reactive_power_L3;
    std::optional<RationalNumber> present_active_power;
    std::optional<RationalNumber> present_active_power_L2;
    std::optional<RationalNumber> present_active_power_L3;
};

struct BPT_Dynamic_AC_CLResControlMode : Dynamic_AC_CLResControlMode {};

struct DER_Dynamic_AC_CLResControlMode : Dynamic_AC_CLResControlMode {
    std::optional<DERControl> der_control;
};

} // namespace datatypes

struct AC_ChargeLoopRequest {
    Header header;

    // the following 2 are inherited from ChargeLoopReq
    std::optional<datatypes::DisplayParameters> display_parameters;
    bool meter_info_requested;

    std::variant<datatypes::Scheduled_AC_CLReqControlMode, datatypes::BPT_Scheduled_AC_CLReqControlMode,
                 datatypes::DER_Scheduled_AC_CLReqControlMode, datatypes::Dynamic_AC_CLReqControlMode,
                 datatypes::BPT_Dynamic_AC_CLReqControlMode, datatypes::DER_Dynamic_AC_CLReqControlMode>
        control_mode;
};

struct AC_ChargeLoopResponse {
    Header header;
    datatypes::ResponseCode response_code;

    // the following 3 are inherited from ChargeLoopRes
    std::optional<datatypes::EvseStatus> status;
    std::optional<datatypes::MeterInfo> meter_info;
    std::optional<datatypes::Receipt> receipt;

    std::optional<datatypes::RationalNumber> target_frequency;

    std::variant<datatypes::Scheduled_AC_CLResControlMode, datatypes::BPT_Scheduled_AC_CLResControlMode,
                 datatypes::DER_Scheduled_AC_CLResControlMode, datatypes::Dynamic_AC_CLResControlMode,
                 datatypes::BPT_Dynamic_AC_CLResControlMode, datatypes::DER_Dynamic_AC_CLResControlMode>
        control_mode = datatypes::Scheduled_AC_CLResControlMode();
};

} // namespace iso15118::message_20
