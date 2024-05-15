// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/d2/session.hpp>
#include <iso15118/message_d2/session_setup.hpp>

namespace iso15118::d2::state {

message_2::SessionSetupResponse handle_request(const message_2::SessionSetupRequest& req, const d2::Session& session,
                                               const std::string evse_id, bool new_session);
} // namespace iso15118::d2::state
