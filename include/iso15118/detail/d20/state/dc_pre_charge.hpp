// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/d20/session.hpp>
#include <iso15118/message/dc_pre_charge.hpp>

namespace iso15118::d20::state {

message_20::DC_PreChargeResponse handle_request(const message_20::DC_PreChargeRequest& req,
                                                const d20::Session& session);

} // namespace iso15118::d20::state
