// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/message/supported_app_protocol.hpp>

namespace iso15118::ev::d20 {

// Holds information about the EVSE
struct EVSEInformation {
    message_20::datatypes::SupportedAppProtocol selected_app_protocol;
    std::string evse_id;
    std::optional<std::string> evse_tls_leaf_cert;
    std::optional<std::string> evse_tls_sub_ca_1_cert;
    std::optional<std::string> evse_tls_sub_ca_2_cert;
    std::optional<std::string> evse_tls_root_cert;
};

} // namespace iso15118::ev::d20
