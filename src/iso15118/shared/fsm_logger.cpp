// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/shared/fsm_logger.hpp>

#include <cstdarg>
#include <cstdio>

#include <iso15118/detail/helper.hpp>

namespace iso15118::shared {

void FsmLogger::operator()(const std::string& msg) const {
    logf("[%s] %s\n", prefix.c_str(), msg.c_str());
}

void FsmLogger::operator()(const char* format, ...) const {
    printf("[%s] ", prefix.c_str());
    static constexpr auto MAX_FMT_LOG_BUFSIZE = 1024;
    char fmt_buffer[MAX_FMT_LOG_BUFSIZE];

    const auto fmt_string = "[" + prefix + "] " + std::string(format);

    va_list list;
    va_start(list, format);

    vlogf(fmt_string.c_str(), list);

    va_end(list);
}

void FsmLogger::enter_state(std::string new_state) const {
    if (last_state_name.size()) {
        this->operator()("transition: %s -> %s", last_state_name.c_str(), new_state.c_str());
    } else {
        this->operator()("transition: entered %s", new_state.c_str());
    }

    last_state_name = std::move(new_state);
}

} // namespace iso15118::shared
