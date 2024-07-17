// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include "common.hpp"
#include "iso15118/message_d2/msg_data_types.hpp"

namespace iso15118::message_2 {

struct DC_PreChargeReq {
    V2GMessageHeader header;
    data_types::DcEvStatus dc_ev_status;
    data_types::PhysicalValue ev_target_voltage;
    data_types::PhysicalValue ev_target_current;
};

struct DC_PreChargeRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::DcEvseStatus dc_evse_status;
    data_types::PhysicalValue evse_present_voltage;
};

} // namespace iso15118::message_2
