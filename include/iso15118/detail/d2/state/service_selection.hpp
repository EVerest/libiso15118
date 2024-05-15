// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/d2/config.hpp>
#include <iso15118/d2/session.hpp>
#include <iso15118/message_d2/service_selection.hpp>

namespace iso15118::d2::state {

message_2::ServiceSelectionResponse handle_request(const message_2::ServiceSelectionRequest& req, d2::Session& session);

} // namespace iso15118::d2::state
