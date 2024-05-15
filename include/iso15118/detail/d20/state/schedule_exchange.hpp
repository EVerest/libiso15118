// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/message_d20/schedule_exchange.hpp>
#include <iso15118/states/session.hpp>

namespace iso15118::d20::state {

message_20::ScheduleExchangeResponse handle_request(const message_20::ScheduleExchangeRequest& req,
                                                    const states::Session& session,
                                                    const message_20::RationalNumber& max_power);

} // namespace iso15118::d20::state
