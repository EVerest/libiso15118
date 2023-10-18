// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/detail/d20/state/dc_charge_loop.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

message_20::DC_ChargeLoopResponse handle_request(const message_20::DC_ChargeLoopRequest& req,
                                                 const d20::Session& session) {

    message_20::DC_ChargeLoopResponse res;

    if (std::get<0>(res.control_mode).max_charge_power) {
        log("Has value!\n");
    }

    if (std::get<0>(res.control_mode).max_voltage) {
        log("Has value!\n");
    }

    // FIXME (aw): remove, debug only
    logf("Received: %d\n", std::get<1>(req.control_mode).target_voltage.value);

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    return response_with_code(res, message_20::ResponseCode::OK);
}

} // namespace iso15118::d20::state
