// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/detail/d20/state/dc_charge_loop.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

using Scheduled_DC_Req = message_20::DC_ChargeLoopRequest::Scheduled_DC_CLReqControlMode;
using Scheduled_BPT_DC_Req = message_20::DC_ChargeLoopRequest::BPT_Scheduled_DC_CLReqControlMode;
using Dynamic_DC_Req = message_20::DC_ChargeLoopRequest::Dynamic_DC_CLReqControlMode;
using Dynamic_BPT_DC_Req = message_20::DC_ChargeLoopRequest::BPT_Dynamic_DC_CLReqControlMode;

std::tuple<message_20::DC_ChargeLoopResponse, std::optional<session::feedback::DcChargeTarget>>
handle_request(const message_20::DC_ChargeLoopRequest& req, const d20::Session& session, const float present_voltage,
               const float present_current) {

    message_20::DC_ChargeLoopResponse res;
    std::optional<session::feedback::DcChargeTarget> charge_target{std::nullopt};

    if (std::holds_alternative<Scheduled_DC_Req>(req.control_mode)) {
        const auto& mode = std::get<Scheduled_DC_Req>(req.control_mode);

        charge_target = {
            message_20::from_RationalNumber(mode.target_voltage),
            message_20::from_RationalNumber(mode.target_current),
        };

    } else if (std::holds_alternative<Scheduled_BPT_DC_Req>(req.control_mode)) {
        const auto& mode = std::get<Scheduled_BPT_DC_Req>(req.control_mode);

        charge_target = {
            message_20::from_RationalNumber(mode.target_voltage),
            message_20::from_RationalNumber(mode.target_current),
        };

        // res.control_mode = message_20::DC_ChargeLoopResponse::BPT_Scheduled_DC_CLResControlMode();
    }

    res.present_voltage = iso15118::message_20::from_float(present_voltage);
    res.present_current = iso15118::message_20::from_float(present_current);
    
    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return {response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession), charge_target};
    }

    return {response_with_code(res, message_20::ResponseCode::OK), charge_target};
}

} // namespace iso15118::d20::state
