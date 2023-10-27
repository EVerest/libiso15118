// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <variant>

namespace iso15118::d20 {
class CableCheckFinished {
public:
    explicit CableCheckFinished(bool success_) : success(success_) {
    }

    operator bool() const {
        return success;
    }

private:
    bool success;
};

struct PresentVoltageCurrent {
    float voltage;
    float current;
};

using ControlEvent = std::variant<CableCheckFinished, PresentVoltageCurrent>;

} // namespace iso15118::d20
