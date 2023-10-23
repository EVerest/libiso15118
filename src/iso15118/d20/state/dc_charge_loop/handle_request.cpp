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

message_20::DC_ChargeLoopResponse handle_request(const message_20::DC_ChargeLoopRequest& req,
                                                 const d20::Session& session) {

    message_20::DC_ChargeLoopResponse res;

    if (std::holds_alternative<Scheduled_DC_Req>(req.control_mode)) {
        const auto& mode = std::get<Scheduled_DC_Req>(req.control_mode);

        const float target_voltage = message_20::convert_RationalNumber(mode.target_voltage);
        const float target_current = message_20::convert_RationalNumber(mode.target_current);

        signal_DC_EVTargetVoltageCurrent(target_voltage, target_current);
    } else if (std::holds_alternative<Scheduled_BPT_DC_Req>(req.control_mode)) {
        const auto& mode = std::get<Scheduled_BPT_DC_Req>(req.control_mode);

        const float target_voltage = message_20::convert_RationalNumber(mode.target_voltage);
        const float target_current = message_20::convert_RationalNumber(mode.target_current);

        signal_DC_EVTargetVoltageCurrent(target_voltage, target_current);
    }

    if (std::get<0>(res.control_mode).max_charge_power) {
        log("Has value!\n");
    }

    if (std::get<0>(res.control_mode).max_voltage) {
        log("Has value!\n");
    }

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    return response_with_code(res, message_20::ResponseCode::OK);
}

} // namespace iso15118::d20::state
