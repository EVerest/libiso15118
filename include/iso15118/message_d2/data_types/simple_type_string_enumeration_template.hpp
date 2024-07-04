// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include "simple_type_template.hpp"
#include <set>
#include <sstream>

namespace iso15118::message_d2::data_types {

template <const char*... enumeration_values> class SimpleTypeStringEnumerationT {
private:
    using base_type = std::string;

    static base_type validate_function(const base_type& value) {
        const auto valid_values = std::set<std::string>{enumeration_values...};

        if (valid_values.find(value) == valid_values.end()) {
            // not found
            throw std::invalid_argument(create_error_message());
        }

        // found
        return value;
    }

    static std::string create_error_message() {
        auto ss = std::ostringstream{};

        // fold expression to concatenate all enumeration values
        ((ss << enumeration_values << ", "), ...);
        // where `(ss << enumeration_value << ", ")` is the expression E
        // and `,` is the comma operator (see: https://en.cppreference.com/w/c/language/operator_other#Comma_operator)
        //
        // the fold operator expands to:
        // (E1 op (... op (EN-1 op EN)))1
        // which in this case is:
        // ( (ss << enumeration_value1 << ", "), (... , (ss << enumeration_valueN-1 << ", "), << enumeration_valueN << ", "))

        std::string enum_values_str = ss.str();

        // remove last comma and space
        enum_values_str = enum_values_str.substr(0, enum_values_str.size() - 2);

        return "Value must be one of the following: " + enum_values_str + ".";
    }

public:
    SimpleTypeStringEnumerationT() = delete;

    using Type = SimpleTypeT<base_type, validate_function>;
};

} // namespace iso15118::message_d2::data_types
