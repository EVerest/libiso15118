// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/message_d2/message_header.hpp>
#include <iso15118/states/context.hpp>
#include <iso15118/states/session.hpp>

namespace iso15118::d2 {

// FIXME (aw): not sure about correct signature here for RVO
template <typename Response, typename ResponseCode> Response& response_with_code(Response& res, ResponseCode code) {
    // FIXME (aw): could add an static_assert here that ResponseCode is an enum?
    res.response_code = code;
    return res;
}

bool validate_and_setup_header(message_20::Header&, const states::Session&,
                               const decltype(message_20::Header::session_id)&);

void setup_header(message_20::Header&, const states::Session&);

void send_sequence_error(const message_20::Type, states::Context&);

} // namespace iso15118::d2
