// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <tuple>

#include <iso15118/d2/session.hpp>
#include <iso15118/message_d2/dc_pre_charge.hpp>

#include <iso15118/session_d2/feedback.hpp>

namespace iso15118::d2::state {

std::tuple<message_2::DC_PreChargeResponse, session::feedback::DcChargeTarget>
handle_request(const message_2::DC_PreChargeRequest& req, const d2::Session& session, const float present_voltage);

} // namespace iso15118::d2::state
