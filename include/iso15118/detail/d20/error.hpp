// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/detail/d20/context_helper.hpp>

#include <iso15118/message/authorization.hpp>
#include <iso15118/message/authorization_setup.hpp>
#include <iso15118/message/session_setup.hpp>
#include <iso15118/message/service_discovery.hpp>
#include <iso15118/message/service_detail.hpp>
#include <iso15118/message/service_selection.hpp>
#include <iso15118/message/dc_charge_parameter_discovery.hpp>
#include <iso15118/message/schedule_exchange.hpp>
#include <iso15118/message/dc_cable_check.hpp>
#include <iso15118/message/dc_pre_charge.hpp>
#include <iso15118/message/power_delivery.hpp>
#include <iso15118/message/dc_charge_loop.hpp>
#include <iso15118/message/dc_welding_detection.hpp>
#include <iso15118/message/session_stop.hpp>

namespace iso15118::d20 {

template <typename Response> Response handle_sequence_error(const d20::Session& session) {
    Response res;
    setup_header(res.header, session);
    return response_with_code(res, message_20::ResponseCode::FAILED_SequenceError);
}

} // namespace iso15118::d20