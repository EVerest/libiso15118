// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include "../general_types.hpp"
#include "../security_types.hpp"
#include "iso15118/message_d2/data_types/identification_number_types.hpp"
#include <cstdint>
#include <optional>

namespace iso15118::message_d2::data_types {

struct meter_info_type {
    meter_id_type meter_id;
    std::optional<uint64_t> meter_reading;
    std::optional<sig_meter_reading_type> sig_meter_reading;
    std::optional<meter_status_type> meter_status;
    std::optional<int64_t> t_meter;
};

} // namespace iso15118::message_d2::data_types