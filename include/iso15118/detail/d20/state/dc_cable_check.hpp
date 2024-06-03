// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/message_d20/dc_cable_check.hpp>
#include <iso15118/states/session.hpp>

namespace iso15118::d20::state {

message_20::DC_CableCheckResponse handle_request(const message_20::DC_CableCheckRequest& req,
                                                 const states::Session& session, bool cable_check_done);

} // namespace iso15118::d20::state
