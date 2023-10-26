// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/detail/d20/context_helper.hpp>

#include <ctime>

namespace iso15118::d20 {

static inline void setup_timestamp(message_20::Header& header) {
    header.timestamp = static_cast<uint64_t>(std::time(nullptr));
}

bool validate_and_setup_header(message_20::Header& header, const Session& cur_session,
                               const decltype(message_20::Header::session_id)& req_session_id) {

    setup_header(header, cur_session);

    return (cur_session.id == req_session_id);
}

void setup_header(message_20::Header& header, const Session& cur_session) {
    header.session_id = cur_session.id;
    setup_timestamp(header);
}

} // namespace iso15118::d20
