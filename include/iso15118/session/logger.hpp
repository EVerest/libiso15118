// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <chrono>
#include <cstdint>
#include <functional>
#include <string>
#include <variant>

namespace iso15118::session {

namespace logging {

using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

struct SimpleEvent {
    TimePoint time_point;
    std::string info;
};

enum class ExiMessageDirection {
    FROM_EV,
    TO_EV,
};
struct ExiMessageEvent {
    TimePoint time_point;
    std::string const& xml_namespace;
    uint8_t const* data;
    size_t len;
    ExiMessageDirection direction;
};

using Event = std::variant<SimpleEvent, ExiMessageEvent>;

using Callback = std::function<void(std::size_t id, const Event&)>;

void set_session_log_callback(const Callback&);

} // namespace logging

class SessionLogger {
public:
    SessionLogger(void*);
    void log_event(const std::string& info) const;
    void log_exi(const std::string& xml_namespace, uint8_t const* data, size_t len,
                 logging::ExiMessageDirection direction) const;

private:
    std::uintptr_t id;
};

} // namespace iso15118::session
