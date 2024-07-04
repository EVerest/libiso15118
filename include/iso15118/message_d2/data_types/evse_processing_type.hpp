// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

#include "simple_type_string_enumeration_template.hpp"
#include <set>

namespace iso15118::message_d2::data_types {

namespace EVSEProcessing {

constexpr char Finished[] = "Finished";
constexpr char Ongoing[] = "Ongoing";
constexpr char Ongoing_WaitingForCustomerInteraction[] = "Ongoing_WaitingForCustomerInteraction";

using Type = SimpleTypeStringEnumerationT<Finished, Ongoing, Ongoing_WaitingForCustomerInteraction>::Type;
} // namespace EVSEProcessing

} // namespace iso15118::message_d2::data_types