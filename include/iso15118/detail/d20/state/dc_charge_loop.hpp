// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cstdint>
#include <ctime>
#include <optional>
#include <tuple>
#include <variant>

#include <iso15118/d20/limits.hpp>
#include <iso15118/d20/session.hpp>
#include <iso15118/message/dc_charge_loop.hpp>

#include <iso15118/session/feedback.hpp>

namespace iso15118::d20::state {

message_20::DC_ChargeLoopResponse
handle_request(const message_20::DC_ChargeLoopRequest& req, const d20::Session& session, const float present_voltage,
               const float present_current, const bool stop, const DcTransferLimits& dc_limits,
               std::optional<std::time_t> new_departure_time, std::optional<uint8_t> new_target_soc,
               std::optional<uint8_t> new_min_soc);

} // namespace iso15118::d20::state
