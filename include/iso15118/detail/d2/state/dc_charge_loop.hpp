// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>
#include <tuple>

#include <iso15118/d2/session.hpp>
#include <iso15118/message_d2/dc_charge_loop.hpp>

#include <iso15118/session_d2/feedback.hpp>

namespace iso15118::d2::state {

std::tuple<message_2::DC_ChargeLoopResponse, std::optional<session::feedback::DcChargeTarget>>
handle_request(const message_2::DC_ChargeLoopRequest& req, const d2::Session& session, const float present_voltage,
               const float present_current);

} // namespace iso15118::d2::state
