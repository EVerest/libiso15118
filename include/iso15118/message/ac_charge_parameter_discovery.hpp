// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>
#include <string>
#include <variant>

#include "common_types.hpp"

namespace iso15118::message_20 {

namespace datatypes {

struct ApparentPowerLimits {
    std::optional<Phase> max_charge_apparent_power;
    std::optional<Phase> max_discharge_apparent_power;
    std::optional<RationalNumber> max_apparent_power;
};

struct ReactivePowerLimits {
    std::optional<RationalNumber> max_charge_reactive_power;
    std::optional<RationalNumber> min_charge_reactive_power;
    std::optional<RationalNumber> max_discharge_reactive_power;
    std::optional<RationalNumber> min_discharge_reactive_power;
    std::optional<RationalNumber> reactive_susceptance;
};

struct ExcitationLimits {
    std::optional<RationalNumber> over_excited_max_power_factor;
    std::optional<RationalNumber> over_excited_max_discharge_power;
    std::optional<RationalNumber> under_excited_max_power_factor;
    std::optional<RationalNumber> under_excited_max_discharge_power;
};

struct InverterDetails {
    std::optional<std::string> inverter_sw_version;
    std::optional<std::string> inverter_hw_version;
    std::optional<std::string> inverter_manufacturer;
    std::optional<std::string> inverter_model;
    std::optional<std::string> inverter_serial_number;
};

struct GridLimits {
    RationalNumber nominal_frequency;
    RationalNumber nominal_voltage;
    std::optional<RationalNumber> nominal_voltage_offset;
    std::optional<RationalNumber> min_frequency;
    std::optional<RationalNumber> max_frequency;
    std::optional<RationalNumber> max_voltage;
    std::optional<RationalNumber> min_voltage;
};

struct AC_CPDReqEnergyTransferMode {
    RationalNumber max_charge_power;
    std::optional<RationalNumber> max_charge_power_L2;
    std::optional<RationalNumber> max_charge_power_L3;
    RationalNumber min_charge_power;
    std::optional<RationalNumber> min_charge_power_L2;
    std::optional<RationalNumber> min_charge_power_L3;
};

struct BPT_AC_CPDReqEnergyTransferMode : AC_CPDReqEnergyTransferMode {
    RationalNumber max_discharge_power;
    std::optional<RationalNumber> max_discharge_power_L2;
    std::optional<RationalNumber> max_discharge_power_L3;
    RationalNumber min_discharge_power;
    std::optional<RationalNumber> min_discharge_power_L2;
    std::optional<RationalNumber> min_discharge_power_L3;
};

struct DER_AC_CPDReqEnergyTransferMode : AC_CPDReqEnergyTransferMode {
    Processing processing;
    Phase max_discharge_power;
    Phase min_discharge_power;
    std::optional<RationalNumber> session_total_discharge_energy_available;
    std::optional<ApparentPowerLimits> apparent_power_limits;
    std::optional<ReactivePowerLimits> reactive_power_limits;
    std::optional<ExcitationLimits> excitation_limits;
    std::optional<InverterDetails> inverter_details;
};

struct AC_CPDResEnergyTransferMode {
    RationalNumber max_charge_power;
    std::optional<RationalNumber> max_charge_power_L2;
    std::optional<RationalNumber> max_charge_power_L3;
    RationalNumber min_charge_power;
    std::optional<RationalNumber> min_charge_power_L2;
    std::optional<RationalNumber> min_charge_power_L3;
    RationalNumber nominal_frequency;
    std::optional<RationalNumber> max_power_asymmetry;
    std::optional<RationalNumber> power_ramp_limitation;
    std::optional<RationalNumber> present_active_power;
    std::optional<RationalNumber> present_active_power_L2;
    std::optional<RationalNumber> present_active_power_L3;
};

struct BPT_AC_CPDResEnergyTransferMode : AC_CPDResEnergyTransferMode {
    RationalNumber max_discharge_power;
    std::optional<RationalNumber> max_discharge_power_L2;
    std::optional<RationalNumber> max_discharge_power_L3;
    RationalNumber min_discharge_power;
    std::optional<RationalNumber> min_discharge_power_L2;
    std::optional<RationalNumber> min_discharge_power_L3;
};

struct DER_AC_CPDResEnergyTransferMode : AC_CPDResEnergyTransferMode {
    std::optional<datatypes::EvseStatus> status;
    datatypes::DERControl der_control;
    datatypes::RationalNumber nominal_power;
    std::optional<datatypes::Phase> max_discharge_power;
    std::optional<datatypes::Phase> max_charge_reactive_power;
    std::optional<datatypes::Phase> max_discharge_reactive_power;
    datatypes::GridLimits grid_limits;
};

} // namespace datatypes

struct AC_ChargeParameterDiscoveryRequest {
    Header header;
    std::variant<datatypes::AC_CPDReqEnergyTransferMode, datatypes::BPT_AC_CPDReqEnergyTransferMode,
                 datatypes::DER_AC_CPDReqEnergyTransferMode>
        transfer_mode;
};

struct AC_ChargeParameterDiscoveryResponse {
    Header header;
    datatypes::ResponseCode response_code;

    std::variant<datatypes::AC_CPDResEnergyTransferMode, datatypes::BPT_AC_CPDResEnergyTransferMode,
                 datatypes::DER_AC_CPDResEnergyTransferMode>
        transfer_mode = datatypes::AC_CPDResEnergyTransferMode();
};

} // namespace iso15118::message_20
