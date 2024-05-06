// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <string>
#include <vector>

#include "common.hpp"

namespace iso15118::message_20 {

struct ServiceDetailRequest {
    Header header;
    ServiceCategory service;
};

struct ServiceDetailResponse {
    Header header;
    ResponseCode response_code;
    ServiceCategory service = ServiceCategory::AC;
    std::vector<ParameterSet> service_parameter_list = {ParameterSet(0)};
};

} // namespace iso15118::message_20
