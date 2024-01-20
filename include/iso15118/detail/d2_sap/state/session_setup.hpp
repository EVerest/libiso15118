// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/d2_sap/session.hpp>
#include <iso15118/message_d2_sap/session_setup.hpp>

namespace iso15118::d2_sap::state {

message_2_sap::SessionSetupResponse handle_request(const message_2_sap::SessionSetupRequest& req, const d2_sap::Session& session,
                                                const std::string evse_id, bool new_session);
} // namespace iso15118::d2_sap::state
