// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include <string>

namespace iso15118::message_d2::data_types {

using gen_challenge_type = std::string;     // base64Binary, length 16
using certificate_type = std::string;       // base64Binary, max length 800
using dh_publickey_type = std::string;      // base64Binary, max length 65
using private_key_type = std::string;       // base64Binary, max length 48
using sig_meter_reading_type = std::string; // base64Binary, max length 64

} // namespace iso15118::message_d2::data_types