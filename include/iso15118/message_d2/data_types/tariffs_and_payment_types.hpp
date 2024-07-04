// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace iso15118::message_d2::data_types {

using sa_id_type = uint8_t;                   // unsignedByte, range 1-255
using tariff_description_type = std::string; // max length 32

enum class cost_kind_type {
    relative_price_percentage,
    renewable_generation_percentage,
    carbon_dioxide_emission
};

struct payment_option_list_type {
    std::vector<std::string> payment_option; // paymentOptionType, minOccurs=1, maxOccurs=2
};

enum class payment_option_type {
    Contract,
    ExternalPayment
};

} // namespace iso15118::message_d2::data_types
