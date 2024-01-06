// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/d2/config.hpp>
#include <iso15118/d2/session.hpp>
#include <iso15118/message_d2/authorization_setup.hpp>

namespace iso15118::d2::state {

message_2::AuthorizationSetupResponse
handle_request(const message_2::AuthorizationSetupRequest& req, d2::Session& session, bool cert_install_service,
               const std::vector<message_2::Authorization>& authorization_services);

} // namespace iso15118::d2::state
