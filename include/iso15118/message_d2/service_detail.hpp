// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {


struct Parameter {
    std::string name;
    union {
        bool bool_value;
        uint8_t byte_value;
        short short_value;
        int int_value;
        data_types::PhysicalValue physical_value;
        std::string string_value;
    };
};

struct ParameterSet {
    short parameter_set_id;
    std::vector<Parameter> parameter; // maxOccurs="16"
};

struct ServiceParameterList {
    std::vector<ParameterSet> parameter_set; // maxOccurs="255"
};
struct ServiceDetailReq {
    V2GMessageHeader header;
    data_types::service_id_type service_id;
};

struct ServiceDetailRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::service_id_type service_id;
    std::optional<ServiceParameterList> service_parameter_list;
};

} // namespace iso15118::message_2
