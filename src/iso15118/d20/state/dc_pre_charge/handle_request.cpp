// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/detail/d20/state/dc_pre_charge.hpp>

#include <iso15118/detail/d20/context_helper.hpp>

namespace iso15118::d20::state {

message_20::DC_PreChargeResponse handle_request(const message_20::DC_PreChargeRequest& req,
                                                const d20::Session& session) {

    message_20::DC_PreChargeResponse res;

    const float ev_target_voltage = iso15118::message_20::convert_RationalNumber(req.target_voltage);

    signal_DC_EVTargetVoltageCurrent(ev_target_voltage, 0);

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    res.present_voltage = {20, 3};

    return response_with_code(res, message_20::ResponseCode::OK);
}

} // namespace iso15118::d20::state
