// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cstdarg>
#include <cstdint>
#include <cstdio>
#include <string>

namespace iso15118 {

void logf(const char* fmt, ...);

void vlogf(const char* fmt, va_list ap);

void log(const std::string&);

void log_and_throw(const char* msg);

void log_and_raise_mbed_error(const std::string& error_msg, int error_code);

} // namespace iso15118
