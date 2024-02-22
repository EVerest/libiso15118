// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/d2/session.hpp>
#include <iso15118/message_d2/power_delivery.hpp>

namespace iso15118::d2::state {

message_2::PowerDeliveryResponse handle_request(const message_2::PowerDeliveryRequest& req,
                                                 const d2::Session& session);

} // namespace iso15118::d2::state
