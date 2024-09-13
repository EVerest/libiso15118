// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <string>
#include <variant>
#include <vector>

#include "msg_data_types.hpp"

namespace iso15118::message_20 {

namespace datatypes {

struct Parameter {
    name_type name;
    std::variant<bool, int8_t, int16_t, int32_t, name_type, RationalNumber> value;
};

struct ParameterSet {
    uint16_t id;
    std::vector<Parameter> parameter;

    ParameterSet();
    ParameterSet(uint16_t _id, const DcParameterList& list);
    ParameterSet(uint16_t _id, const DcBptParameterList& list);
    ParameterSet(uint16_t _id, const InternetParameterList& list);
    ParameterSet(uint16_t _id, const ParkingParameterList& list);
};

using service_parameter_list_type = std::vector<ParameterSet>; // Max: 32

} // namespace datatypes

struct ServiceDetailRequest {
    Header header;
    datatypes::ServiceCategory service;
};

struct ServiceDetailResponse {
    Header header;
    datatypes::ResponseCode response_code;
    datatypes::ServiceCategory service{datatypes::ServiceCategory::DC};
    datatypes::service_parameter_list_type service_parameter_list = {datatypes::ParameterSet()};
};

} // namespace iso15118::message_20
