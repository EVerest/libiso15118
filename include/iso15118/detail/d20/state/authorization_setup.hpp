// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/message_d20/authorization_setup.hpp>
#include <iso15118/states/config.hpp>
#include <iso15118/states/session.hpp>

namespace iso15118::d20::state {

message_20::AuthorizationSetupResponse
handle_request(const message_20::AuthorizationSetupRequest& req, states::Session& session, bool cert_install_service,
               const std::vector<message_20::Authorization>& authorization_services);

} // namespace iso15118::d20::state
