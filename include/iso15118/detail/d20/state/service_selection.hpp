// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/message_d20/service_selection.hpp>
#include <iso15118/states/config.hpp>
#include <iso15118/states/session.hpp>

namespace iso15118::d20::state {

message_20::ServiceSelectionResponse handle_request(const message_20::ServiceSelectionRequest& req,
                                                    states::Session& session);

} // namespace iso15118::d20::state
