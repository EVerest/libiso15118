// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>
#include <vector>

#include "msg_data_types.hpp"

namespace iso15118::message_20 {

namespace datatypes {

struct SelectedService {
    ServiceCategory service_id;
    uint16_t parameter_set_id;
};

using selected_service_list_type = std::vector<SelectedService>; // Max: 16

} // namespace datatypes

struct ServiceSelectionRequest {
    Header header;
    datatypes::SelectedService selected_energy_transfer_service;
    std::optional<datatypes::selected_service_list_type> selected_vas_list;
};

struct ServiceSelectionResponse {
    Header header;
    datatypes::ResponseCode response_code;
};

} // namespace iso15118::message_20
