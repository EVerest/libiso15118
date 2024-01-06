// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/d2/context.hpp>
#include <iso15118/d2/session.hpp>
#include <iso15118/message_d2/common.hpp>

namespace iso15118::d2 {

// FIXME (aw): not sure about correct signature here for RVO
template <typename Response, typename ResponseCode> Response& response_with_code(Response& res, ResponseCode code) {
    // FIXME (aw): could add an static_assert here that ResponseCode is an enum?
    res.response_code = code;
    return res;
}

bool validate_and_setup_header(message_2::Header&, const Session&, const decltype(message_2::Header::session_id)&);

void setup_header(message_2::Header&, const Session&);

void send_sequence_error(const message_2::Type, d2::Context&);

} // namespace iso15118::d2
