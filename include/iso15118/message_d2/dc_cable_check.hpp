// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include "iso15118/message_d2/message_header.hpp"
#include "iso15118/message_d2/msg_data_types.hpp"

namespace iso15118::message_2 {

struct DC_CableCheckRequest {
    V2GMessageHeader header;
    data_types::DcEvStatus dc_ev_status;
};

struct DC_CableCheckResponse {

    DC_CableCheckResponse() : evse_processing(data_types::EvseProcessing::Ongoing){};
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::DcEvseStatus dc_evse_status;
    data_types::EvseProcessing evse_processing;
};

} // namespace iso15118::message_2
