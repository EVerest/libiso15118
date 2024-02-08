// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/d2/session.hpp>
#include <iso15118/message_d2/dc_cable_check.hpp>

namespace iso15118::d2::state {

message_2::DC_CableCheckResponse handle_request(const message_2::DC_CableCheckRequest& req,
                                                 const d2::Session& session, bool cable_check_done);

} // namespace iso15118::d2::state
