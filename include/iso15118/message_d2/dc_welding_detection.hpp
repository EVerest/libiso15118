// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

struct DC_WeldingDetectionReq {
    V2GMessageHeader header;
    data_types::DcEvStatus dc_ev_status;
};

struct DC_WeldingDetectionRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::DcEvseStatus dc_evse_status;
    data_types::PhysicalValue evse_present_voltage;
};

} // namespace iso15118::message_2
