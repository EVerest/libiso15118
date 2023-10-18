// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <array>
#include <cstdint>
#include <vector>

#include <iso15118/message/common.hpp>

namespace iso15118::d20 {

struct Session {
    // todo(sl): move to a common defs file
    static constexpr auto ID_LENGTH = 8;

    Session();

    // NOTE (aw): could be const
    std::array<uint8_t, ID_LENGTH> id{};

    std::vector<message_20::Authorization> offered_auth_services;

    message_20::ServiceCategory selected_energy_service;
    uint16_t selected_energy_parameter_set_id; // todo(sl): save the hole parameter_set structs or specific parameter
                                               // e.g. Dynamic or Schedule mode

    std::vector<message_20::ServiceCategory> selected_vas_services;
    std::vector<uint16_t> selected_vas_parameter_set_id;
};

} // namespace iso15118::d20
