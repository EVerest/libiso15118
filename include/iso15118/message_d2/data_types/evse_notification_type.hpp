// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include "simple_type_string_enumeration_template.hpp"
#include <set>

namespace iso15118::message_d2::data_types {

namespace EVSENotification {

constexpr char None[] = "None";
constexpr char StopCharging[] = "StopCharging";
constexpr char ReNegotiation[] = "ReNegotiation";

using Type = SimpleTypeStringEnumerationT<None, StopCharging, ReNegotiation>::Type;
} // namespace EVSENotification

} // namespace iso15118::message_d2::data_types
