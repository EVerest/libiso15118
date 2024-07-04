// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include "iso15118/message_d2/common.hpp"
#include "iso15118/message_d2/data_types/complex_types/ev_evse_related_types.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"

namespace iso15118::message_2 {

struct DC_CableCheckRequest {
    V2GMessageHeader header;
    iso15118::message_d2::data_types::dc_ev_status_type dc_ev_status;
};

struct DC_CableCheckResponse {

    DC_CableCheckResponse() : evse_processing(iso15118::message_d2::data_types::evse_processing_type::Ongoing){};
    V2GMessageHeader header;
    iso15118::message_d2::data_types::response_code_type response_code;
    iso15118::message_d2::data_types::dc_evse_status_type dc_evse_status;
    iso15118::message_d2::data_types::evse_processing_type evse_processing;
};

} // namespace iso15118::message_2
