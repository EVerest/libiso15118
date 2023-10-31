// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/detail/d20/state/session_stop.hpp>

#include <iso15118/detail/d20/context_helper.hpp>

#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

message_20::SessionStopResponse handle_request(const message_20::SessionStopRequest& req, const d20::Session& session) {

    message_20::SessionStopResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    // Todo(sl): Check req.charging_session, ev_termination_code & ev_termination_explanation

    return response_with_code(res, message_20::ResponseCode::OK);
}

} // namespace iso15118::d20::state
