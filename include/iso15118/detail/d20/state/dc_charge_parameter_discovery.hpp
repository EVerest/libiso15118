// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/message_d20/dc_charge_parameter_discovery.hpp>
#include <iso15118/states/config.hpp>
#include <iso15118/states/session.hpp>

namespace iso15118::d20::state {

message_20::DC_ChargeParameterDiscoveryResponse
handle_request(const message_20::DC_ChargeParameterDiscoveryRequest& req, const states::Session& session,
               const states::SessionConfig& config);

} // namespace iso15118::d20::state
