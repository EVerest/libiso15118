// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/detail/d20/state/dc_welding_detection.hpp>

#include <iso15118/detail/d20/context_helper.hpp>

#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

message_20::DC_WeldingDetectionResponse handle_request(const message_20::DC_WeldingDetectionRequest& req,
                                                       const d20::Session& session, const float present_voltage) {
    message_20::DC_WeldingDetectionResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    res.present_voltage = message_20::from_float(present_voltage);

    return response_with_code(res, message_20::ResponseCode::OK);
}

} // namespace iso15118::d20::state