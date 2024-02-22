// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/d2/config.hpp>
#include <iso15118/d2/session.hpp>
#include <iso15118/message_d2/service_detail.hpp>

namespace iso15118::d2::state {

message_2::ServiceDetailResponse handle_request(const message_2::ServiceDetailRequest& req, d2::Session& session,
                                                 const d2::SessionConfig& config);

} // namespace iso15118::d2::state
