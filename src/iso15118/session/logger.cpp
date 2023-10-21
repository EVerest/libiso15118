// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/session/logger.hpp>

#include <iso15118/detail/helper.hpp>

static iso15118::session::logging::Callback session_log_callback{nullptr};

namespace iso15118::session {

SessionLogger::SessionLogger(void* id_) : id(reinterpret_cast<std::uintptr_t>(id_)){};

void SessionLogger::log_event(const std::string& info) {
    logging::SimpleEvent event{std::chrono::system_clock::now(), info};
    session_log_callback(this->id, std::move(event));
}

namespace logging {
void set_session_log_callback(const logging::Callback& callback) {
    session_log_callback = callback;
}
} // namespace logging

} // namespace iso15118::session