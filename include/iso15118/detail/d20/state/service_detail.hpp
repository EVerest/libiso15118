// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/message_d20/service_detail.hpp>
#include <iso15118/states/config.hpp>
#include <iso15118/states/session.hpp>

namespace iso15118::d20::state {

message_20::ServiceDetailResponse handle_request(const message_20::ServiceDetailRequest& req, states::Session& session,
                                                 const states::SessionConfig& config);

} // namespace iso15118::d20::state
