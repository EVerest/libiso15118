// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include "simple_type_string_enumeration_template.hpp"

namespace iso15118::message_d2::data_types {

namespace ChargeProgress {

constexpr char Start[] = "Start";
constexpr char Stop[] = "Stop";
constexpr char Renegotiate[] = "Renegotiate";

using Type = SimpleTypeStringEnumerationT<Start, Stop, Renegotiate>::Type;
} // namespace ChargeProgress

} // namespace iso15118::message_d2::data_types
