// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <functional>
#include <string>

namespace iso15118 {
enum class LogLevel {
    Error,
    Warning,
    Info,
    Debug,
    Trace,
};

namespace io {
void set_logging_callback(const std::function<void(LogLevel, std::string)>&);

} // namespace io

} // namespace iso15118
