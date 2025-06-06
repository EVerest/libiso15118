// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#pragma once

#include <algorithm>
#include <array>
#include <map>
#include <optional>
#include <tuple>

#include <iso15118/detail/helper.hpp>
#include <iso15118/io/time.hpp>

namespace iso15118::d20 {

template <typename T> constexpr auto to_underlying_value(T t) {
    return static_cast<std::underlying_type_t<T>>(t);
}

enum class TimeoutType : uint8_t {
    SEQUENCE = 0,
    PERFORMANCE,
    ONGOING,
    CONTACTOR,
};

constexpr uint8_t TIMEOUT_TYPE_SIZE = 4;

static_assert(TIMEOUT_TYPE_SIZE == to_underlying_value(TimeoutType::CONTACTOR) + 1,
              "TIMEOUT_TYPE_SIZE should be in sync with the TimeoutType enum definition");

class Timeouts {
public:
    explicit Timeouts() = default;
    ~Timeouts() = default;

    void start_timeout(TimeoutType type, uint32_t timeout_ms) {
        const auto type_u8 = to_underlying_value(type);
        if (timeouts.at(type_u8).has_value()) {
            logf_warning("Timeout %u already started", type_u8);
            return;
        }
        timeouts.at(type_u8).emplace(Timeout(timeout_ms));
    }

    void stop_timeout(TimeoutType type) {
        const auto type_u8 = to_underlying_value(type);
        if (not timeouts.at(type_u8).has_value()) {
            logf_warning("Timeout %u is not started", type_u8);
        }
        timeouts.at(type_u8).reset();
    }

    void reset_timeout(TimeoutType type) {
        const auto type_u8 = to_underlying_value(type);
        timeouts.at(type_u8).reset();
    }

    std::optional<std::vector<TimeoutType>> check() {
        bool reached{false};

        std::map<TimePoint, TimeoutType> active_timeouts_map;

        for (uint8_t i = 0; i < TIMEOUT_TYPE_SIZE; i++) {
            auto timeout = timeouts.at(i);
            if (timeout.has_value() and timeout.value().is_reached()) {
                active_timeouts_map.insert({timeout.value().get_timeout_point(), static_cast<TimeoutType>(i)});
                reached = true;
            }
        }

        if (reached) {
            std::vector<TimeoutType> active_timeouts{};
            for (const auto& [_, value] : active_timeouts_map) {
                active_timeouts.push_back(value);
            }
            return active_timeouts;
        }

        return std::nullopt;
    }

private:
    std::array<std::optional<Timeout>, TIMEOUT_TYPE_SIZE> timeouts;
};

} // namespace iso15118::d20
