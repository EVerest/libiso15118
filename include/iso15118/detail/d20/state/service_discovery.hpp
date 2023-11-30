// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/d20/config.hpp>
#include <iso15118/d20/session.hpp>
#include <iso15118/message/service_discovery.hpp>

namespace iso15118::d20::state {

message_20::ServiceDiscoveryResponse handle_request(const message_20::ServiceDiscoveryRequest& req,
                                                    d20::Session& session, const d20::Config& config);

} // namespace iso15118::d20::state
