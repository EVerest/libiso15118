// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include "common.hpp"
#include "iso15118/message_d2/data_types/complex_types/ev_evse_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/physical_value_type.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"

namespace iso15118::message_2 {

struct DC_WeldingDetectionReq {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::dc_ev_status_type dc_ev_status;
};

struct DC_WeldingDetectionRes {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
    iso15118::message_d2::data_types::dc_evse_status_type dc_evse_status;
    iso15118::message_d2::data_types::physical_value_type evse_present_voltage;
};

} // namespace iso15118::message_2
