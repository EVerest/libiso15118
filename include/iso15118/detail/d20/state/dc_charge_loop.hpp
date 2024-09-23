// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>
#include <tuple>
#include <variant>

#include <iso15118/d20/limits.hpp>
#include <iso15118/d20/session.hpp>
#include <iso15118/message/dc_charge_loop.hpp>

#include <iso15118/session/feedback.hpp>

namespace iso15118::d20::state {

using EvFeedbackControlMode =
    std::variant<std::monostate, session::feedback::DcChargeScheduledMode, session::feedback::DcChargeDynamicMode>;

std::tuple<message_20::DC_ChargeLoopResponse, EvFeedbackControlMode>
handle_request(const message_20::DC_ChargeLoopRequest& req, const d20::Session& session, const float present_voltage,
               const float present_current, const bool stop, const DcTransferLimits& dc_limits);

} // namespace iso15118::d20::state
