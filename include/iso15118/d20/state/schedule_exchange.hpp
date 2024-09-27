// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include "../fsm.hpp"

#include <cstdint>
#include <ctime>
#include <optional>

namespace iso15118::d20::state {

struct ScheduleExchange : public FsmSimpleState {
    using FsmSimpleState::FsmSimpleState;

    void enter() final;

    HandleEventReturnType handle_event(AllocatorType&, FsmEvent) final;

private:
    std::optional<std::time_t> new_departure_time;
    std::optional<uint8_t> new_target_soc;
    std::optional<uint8_t> new_min_soc;
};

} // namespace iso15118::d20::state
