// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest

#pragma once

#include "common.hpp"
#include "iso15118/message_d2/msg_data_types.hpp"

namespace iso15118::message_2 {

struct ChargeParameterDiscoveryReq {
    V2GMessageHeader header;
    std::optional<uint16_t> max_entries_sa_schedule_tuple;
    data_types::EnergyTransferMode requested_energy_transfer_mode;
    data_types::EvChargeParameter ev_charge_parameter;
};

struct ChargeParameterDiscoveryRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::EvseProcessing evse_processing;
    std::optional<data_types::SaSchedules> sa_schedules;
    data_types::EvseChargeParameter evse_charge_parameter;
};

} // namespace iso15118::message_2
