// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <string>
#include <variant>
#include <vector>

#include "common.hpp"

namespace iso15118::message_20 {

// todo(sl): Adding internet and parking status service

struct ServiceDetailRequest {
    Header header;
    ServiceCategory service;
};

struct ServiceDetailResponse {
    struct Parameter {
        std::string name;
        std::variant<bool, int8_t, int16_t, int32_t, std::string, RationalNumber>
            value; // todo(sl): refactor because ISO-20 use only int32_t values
    };

    struct ParameterSet {
        uint16_t id;
        std::vector<Parameter> parameter;

        ParameterSet();
        ParameterSet(uint16_t _id, const DcParameterList& list);
        ParameterSet(uint16_t _id, const DcBptParameterList& list);
    };

    Header header;
    ResponseCode response_code;
    ServiceCategory service = ServiceCategory::DC;
    std::vector<ParameterSet> service_parameter_list = {ParameterSet()};
};

} // namespace iso15118::message_20
