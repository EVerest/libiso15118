// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <filesystem>
#include <string>

namespace iso15118::config {

enum class TlsNegotiationStrategy {
    ACCEPT_CLIENT_OFFER,
    ENFORCE_TLS,
    ENFORCE_NO_TLS,
};

enum class CertificateBackend {
    EVEREST_LAYOUT,
    JOSEPPA_LAYOUT,
};

struct CertificatePaths {
    std::filesystem::path cpo_cert_chain_path{};
    std::filesystem::path secc_leaf_key_path{};
    std::filesystem::path v2g_root_cert_path{};
    std::filesystem::path oem_root_cert_path{};
};

struct SSLConfig {
    CertificateBackend backend{CertificateBackend::EVEREST_LAYOUT};
    CertificatePaths certificate_paths{};
    std::string private_key_password{};
    bool enable_ssl_logging{false};
    bool enable_tls_key_logging{false};
    bool enforce_tls_1_3{false};
    std::filesystem::path tls_key_logging_path{};
};

} // namespace iso15118::config
