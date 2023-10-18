// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <string>

namespace iso15118::config {

enum class CertificateBackend {
    EVEREST_LAYOUT,
    JOSEV_LAYOUT,
};
struct SSLConfig {
    CertificateBackend backend;
    std::string config_string;
};

} // namespace iso15118::config
