// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include "../multiplier_and_unit_types.hpp"
#include <cbv2g/iso_2/iso2_msgDefEncoder.h>
#include <stdexcept>

namespace iso15118::message_d2::data_types {

inline const auto convertUnitSymbol = [](iso2_unitSymbolType iso2Unit) {
    switch (iso2Unit) {
    case iso2_unitSymbolType_h:
        return iso15118::message_d2::data_types::unit_symbol_type::h;
    case iso2_unitSymbolType_m:
        return iso15118::message_d2::data_types::unit_symbol_type::m;
    case iso2_unitSymbolType_s:
        return iso15118::message_d2::data_types::unit_symbol_type::s;
    case iso2_unitSymbolType_A:
        return iso15118::message_d2::data_types::unit_symbol_type::A;
    case iso2_unitSymbolType_V:
        return iso15118::message_d2::data_types::unit_symbol_type::V;
    case iso2_unitSymbolType_W:
        return iso15118::message_d2::data_types::unit_symbol_type::W;
    case iso2_unitSymbolType_Wh:
        return iso15118::message_d2::data_types::unit_symbol_type::Wh;
    default:
        throw std::runtime_error("Unsupported unit symbol");
    }
};

struct physical_value_type {
    unit_multiplier_type multiplier;
    unit_symbol_type unit;
    short value;

    inline physical_value_type& operator=(const iso2_PhysicalValueType& rhs) {
        multiplier = rhs.Multiplier;
        value = rhs.Value;
        unit = convertUnitSymbol(rhs.Unit);
        return *this;
    };
};

} // namespace iso15118::message_d2::data_types
