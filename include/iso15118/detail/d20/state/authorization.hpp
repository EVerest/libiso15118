// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/message_d20/authorization.hpp>
#include <iso15118/states/session.hpp>

namespace iso15118::d20::state {

message_20::AuthorizationResponse handle_request(const message_20::AuthorizationRequest& req,
                                                 const states::Session& session,
                                                 const message_20::AuthStatus& authorization_status);

} // namespace iso15118::d20::state
