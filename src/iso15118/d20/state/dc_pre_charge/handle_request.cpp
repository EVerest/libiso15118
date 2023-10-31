// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/detail/d20/state/dc_pre_charge.hpp>

#include <iso15118/detail/d20/context_helper.hpp>

#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

std::tuple<message_20::DC_PreChargeResponse, session::feedback::DcChargeTarget>
handle_request(const message_20::DC_PreChargeRequest& req, const d20::Session& session, const float present_voltage) {

    message_20::DC_PreChargeResponse res;
    session::feedback::DcChargeTarget charge_target{};

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return {response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession), charge_target};
    }

    charge_target.voltage = message_20::from_RationalNumber(req.target_voltage);
    charge_target.current = 0;

    res.present_voltage = message_20::from_float(present_voltage);

    return {response_with_code(res, message_20::ResponseCode::OK), charge_target};
}

} // namespace iso15118::d20::state
