// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest

#pragma once

#include "common.hpp"
#include "iso15118/message_d2/data_types/complex_types/evse_ev_charge_parameter_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/tariff_related_types.hpp"
#include "iso15118/message_d2/data_types/energy_transfer_type.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"

namespace iso15118::message_2 {

struct ChargeParameterDiscoveryReq {
    V2GMessageHeader header;
    std::optional<uint16_t> max_entries_sa_schedule_tuple;
    iso15118::message_d2::data_types::energy_transfer_mode_type requested_energy_transfer_mode;
    iso15118::message_d2::data_types::ev_charge_parameter_type ev_charge_parameter;
};

struct ChargeParameterDiscoveryRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
    iso15118::message_d2::data_types::evse_processing_type evse_processing;
    std::optional<iso15118::message_d2::data_types::sa_schedules_type> sa_schedules;
    iso15118::message_d2::data_types::evse_charge_parameter_type evse_charge_parameter;
};

} // namespace iso15118::message_2
