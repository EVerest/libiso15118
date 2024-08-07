// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <string>

namespace iso15118 {

// FIXME(SL): Double declaration here and io/logging.hpp
enum class LogLevel {
    Error,
    Warning,
    Info,
    Debug,
    Trace,
};

void logf(const char* fmt, ...);
void logf(const LogLevel&, const char* fmt, ...);

void logf_error(const char* fmt, ...);
void logf_warning(const char* fmt, ...);
void logf_info(const char* fmt, ...);
void logf_debug(const char* fmt, ...);
void logf_trace(const char* fmt, ...);

void vlogf(const char* fmt, va_list ap);
void vlogf(const LogLevel&, const char* fmt, va_list ap);

void log(const LogLevel&, const std::string&);

void log_and_throw(const char* msg);

void log_and_raise_mbed_error(const std::string& error_msg, int error_code);

void log_and_raise_openssl_error(const std::string& error_msg);

std::string adding_err_msg(const std::string& msg);

template <typename CallbackType, typename... Args> bool call_if_available(const CallbackType& callback, Args... args) {
    if (not callback) {
        return false;
    }

    callback(std::forward<Args>(args)...);
    return true;
}

} // namespace iso15118
