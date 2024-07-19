// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <variant>
#include <vector>

#include "message_header.hpp"

namespace iso15118::message_2 {

struct DC_ChargeLoopRequest {
    struct DisplayParameters {
        std::optional<PercentValue> present_soc;
        std::optional<PercentValue> min_soc;
        std::optional<PercentValue> target_soc;
        std::optional<PercentValue> max_soc;
        std::optional<uint16_t> remaining_time_to_min_soc;
        std::optional<uint16_t> remaining_time_to_target_soc;
        std::optional<uint16_t> remaining_time_to_max_soc;
        std::optional<bool> charging_complete;
        std::optional<RationalNumber> battery_energy_capacity;
        std::optional<bool> inlet_hot;
    };

    struct Scheduled_DC_CLReqControlMode : Scheduled_CLReqControlMode {
        RationalNumber target_current;
        RationalNumber target_voltage;
        std::optional<RationalNumber> max_charge_power;
        std::optional<RationalNumber> min_charge_power;
        std::optional<RationalNumber> max_charge_current;
        std::optional<RationalNumber> max_voltage;
        std::optional<RationalNumber> min_voltage;
    };

    struct BPT_Scheduled_DC_CLReqControlMode : Scheduled_DC_CLReqControlMode {
        std::optional<RationalNumber> max_discharge_power;
        std::optional<RationalNumber> min_discharge_power;
        std::optional<RationalNumber> max_discharge_current;
    };

    struct Dynamic_DC_CLReqControlMode : Dynamic_CLReqControlMode {
        RationalNumber max_charge_power;
        RationalNumber min_charge_power;
        RationalNumber max_charge_current;
        RationalNumber max_voltage;
        RationalNumber min_voltage;
    };

    struct BPT_Dynamic_DC_CLReqControlMode : Dynamic_DC_CLReqControlMode {
        RationalNumber max_discharge_power;
        RationalNumber min_discharge_power;
        RationalNumber max_discharge_current;
        std::optional<RationalNumber> max_v2x_energy_request;
        std::optional<RationalNumber> min_v2x_energy_request;
    };

    Header header;

    // the following 2 are inherited from ChargeLoopReq
    std::optional<DisplayParameters> display_parameters;
    bool meter_info_requested;

    RationalNumber present_voltage;
    std::variant<Scheduled_DC_CLReqControlMode, BPT_Scheduled_DC_CLReqControlMode, Dynamic_DC_CLReqControlMode,
                 BPT_Dynamic_DC_CLReqControlMode>
        control_mode;
};

struct DC_ChargeLoopResponse {
    struct DetailedCost {
        RationalNumber amount;
        RationalNumber cost_per_unit;
    };

    struct DetailedTax {
        uint32_t tax_rule_id; // NOTE (aw): only 1 - 4294967295
        RationalNumber amount;
    };

    struct Receipt {
        uint64_t time_anchor;
        std::optional<DetailedCost> energy_costs;
        std::optional<DetailedCost> occupany_costs;
        std::optional<DetailedCost> additional_service_costs;
        std::optional<DetailedCost> overstay_costs;
        std::vector<DetailedTax> tax_costs; // 0 to 10 elements!
    };

    struct Scheduled_DC_CLResControlMode : Scheduled_CLResControlMode {
        std::optional<RationalNumber> max_charge_power;
        std::optional<RationalNumber> min_charge_power;
        std::optional<RationalNumber> max_charge_current;
        std::optional<RationalNumber> max_voltage;
    };

    struct BPT_Scheduled_DC_CLResControlMode : Scheduled_DC_CLResControlMode {
        std::optional<RationalNumber> max_discharge_power;
        std::optional<RationalNumber> min_discharge_power;
        std::optional<RationalNumber> max_discharge_current;
        std::optional<RationalNumber> min_voltage;
    };

    struct Dynamic_DC_CLResControlMode : Dynamic_CLResControlMode {
        RationalNumber max_charge_power;
        RationalNumber min_charge_power;
        RationalNumber max_charge_current;
        RationalNumber max_voltage;
    };

    struct BPT_Dynamic_DC_CLResControlMode : Dynamic_DC_CLResControlMode {
        RationalNumber max_discharge_power;
        RationalNumber min_discharge_power;
        RationalNumber max_discharge_current;
        RationalNumber min_voltage;
    };

    Header header;
    ResponseCode response_code;

    // the following 3 are inherited from ChargeLoopRes
    std::optional<EvseStatus> status;
    std::optional<MeterInfo> meter_info;
    std::optional<Receipt> receipt;

    RationalNumber present_current;
    RationalNumber present_voltage;
    bool power_limit_achieved;
    bool current_limit_achieved;
    bool voltage_limit_achieved;

    std::variant<Scheduled_DC_CLResControlMode, BPT_Scheduled_DC_CLResControlMode, Dynamic_DC_CLResControlMode,
                 BPT_Dynamic_DC_CLResControlMode>
        control_mode = Scheduled_DC_CLResControlMode();
};

} // namespace iso15118::message_2
