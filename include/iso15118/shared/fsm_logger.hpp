// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <string>

namespace iso15118::shared {

class FsmLogger {
public:
    FsmLogger(std::string log_prefix) : prefix(std::move(log_prefix)){};

    void enter_state(std::string new_state) const;

    void operator()(const std::string&) const;
    void operator()(const char* format, ...) const;

private:
    std::string prefix;
    mutable std::string last_state_name;
};

} // namespace iso15118::shared
