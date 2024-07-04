// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include <string>

namespace iso15118::message_d2::data_types {

template <typename base_t, auto validate_function> class SimpleTypeT {
public:
    explicit SimpleTypeT(const base_t new_value) : value{validate_function(new_value)} {};
    SimpleTypeT(){};

    base_t& to_base_type() {
        return value;
    }

    const base_t& to_base_type() const {
        return value;
    }

private:
    template <typename T, auto vfn>
    friend bool operator==(const SimpleTypeT<T, vfn>& lhs, const SimpleTypeT<T, vfn>& rhs);

    base_t value;
};

template <typename base_t, auto validate_function>
bool operator==(const SimpleTypeT<base_t, validate_function>& lhs,
                const SimpleTypeT<base_t, validate_function>& rhs) {
    return lhs.value == rhs.value;
}

} // namespace iso15118::message_d2::data_types