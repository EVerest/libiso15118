// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/message_d20/dc_welding_detection.hpp>
#include <iso15118/states/session.hpp>

namespace iso15118::d20::state {

message_20::DC_WeldingDetectionResponse handle_request(const message_20::DC_WeldingDetectionRequest& req,
                                                       const states::Session& session, const float present_voltage);

} // namespace iso15118::d20::state
