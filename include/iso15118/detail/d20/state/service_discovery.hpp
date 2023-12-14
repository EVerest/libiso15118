// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <vector>

#include <iso15118/d20/config.hpp>
#include <iso15118/d20/session.hpp>
#include <iso15118/message/common.hpp>
#include <iso15118/message/service_discovery.hpp>

namespace iso15118::d20::state {

message_20::ServiceDiscoveryResponse handle_request(const message_20::ServiceDiscoveryRequest& req,
                                                    d20::Session& session,
                                                    const std::vector<message_20::ServiceCategory>& energy_services,
                                                    const std::vector<message_20::ServiceCategory>& vas_services);

} // namespace iso15118::d20::state
