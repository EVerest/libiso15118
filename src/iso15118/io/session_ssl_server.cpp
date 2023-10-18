// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/io/session_ssl_server.hpp>

#include <cassert>
#include <cstring>
#include <filesystem>

#include <ifaddrs.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include "mbedtls/ctr_drbg.h"
#include "mbedtls/debug.h"
#include "mbedtls/entropy.h"
#include "mbedtls/error.h"
#include "mbedtls/net_sockets.h"
#include "mbedtls/ssl.h"

#include <iso15118/detail/helper.hpp>

namespace iso15118::io {

struct SSLContext {
    SSLContext();

    mbedtls_net_context listen_fd;
    mbedtls_net_context client_fd;
    mbedtls_ssl_context ssl;
    mbedtls_ssl_config conf;
    mbedtls_x509_crt server_certificate;
    mbedtls_ctr_drbg_context ctr_drbg;
    mbedtls_entropy_context entropy;
    mbedtls_pk_context pkey;
};

SSLContext::SSLContext() {
    mbedtls_net_init(&listen_fd);
    mbedtls_net_init(&client_fd);
    mbedtls_ssl_init(&ssl);
    mbedtls_ssl_config_init(&conf);
    mbedtls_x509_crt_init(&server_certificate);
    mbedtls_ctr_drbg_init(&ctr_drbg);
    mbedtls_entropy_init(&entropy);
    mbedtls_pk_init(&pkey);
};

static void parse_crt_file(mbedtls_x509_crt* chain, const std::filesystem::path& path) {
    const auto x509_crt_parse_result = mbedtls_x509_crt_parse_file(chain, path.c_str());
    if (x509_crt_parse_result != 0) {
        const std::string error = "Failed in mbedtls_x509_crt_parse_file() with file " + path.string();
        log_and_raise_mbed_error(error.c_str(), x509_crt_parse_result);
    }
}

static void parse_key_file(mbedtls_pk_context* pk_context, const std::filesystem::path& path, const char* password) {
    const auto parse_key_result = mbedtls_pk_parse_keyfile(pk_context, path.c_str(), password);
    if (parse_key_result != 0) {
        const std::string error = "Failed in mbedtls_pk_parse_keyfile() with file " + path.string();
        log_and_raise_mbed_error(error.c_str(), parse_key_result);
    }
}

static void load_certificates(SSLContext& ssl, const config::SSLConfig& ssl_config) {
    if (ssl_config.backend == config::CertificateBackend::JOSEV_LAYOUT) {
        const std::filesystem::path prefix(ssl_config.config_string);
        auto chain = &ssl.server_certificate;

        parse_crt_file(chain, prefix / "seccLeafCert.pem");
        parse_crt_file(chain, prefix / "cpoSubCA2Cert.pem");
        parse_crt_file(chain, prefix / "cpoSubCA1Cert.pem");
        parse_key_file(&ssl.pkey, prefix / "seccLeaf.key", "12345"); // FIXME (aw): hardcoded ...
    } else if (ssl_config.backend == config::CertificateBackend::EVEREST_LAYOUT) {
        const std::filesystem::path prefix(ssl_config.config_string);

        auto chain = &ssl.server_certificate;
        parse_crt_file(chain, prefix / "client/cso/SECC_LEAF.pem");
        parse_crt_file(chain, prefix / "ca/cso/CPO_SUB_CA2.pem");
        parse_crt_file(chain, prefix / "ca/cso/CPO_SUB_CA1.pem");
        parse_key_file(&ssl.pkey, prefix / "client/cso/SECC_LEAF.key", "123456");
    }
}

SessionSSLServer::SessionSSLServer(const std::string& interface_name, const config::SSLConfig& ssl_config) :
    ssl(std::make_unique<SSLContext>()) {
    //
    // figure out device
    //
    struct ifaddrs* if_list_head;
    const auto get_if_addrs_result = getifaddrs(&if_list_head);

    if (get_if_addrs_result == -1) {
        log_and_throw("Failed to call getifaddrs");
    }
    auto current_if = if_list_head;

    for (auto current_if = if_list_head; current_if != nullptr; current_if = current_if->ifa_next) {
        if (current_if->ifa_addr->sa_family != AF_INET6) {
            continue;
        }

        if (interface_name.compare(current_if->ifa_name) != 0) {
            continue;
        }

        // matching interface name and ipv6
        // FIXME (aw): is this cast allowed (alignment)
        const auto& socket_address = reinterpret_cast<const struct sockaddr_in6&>(*current_if->ifa_addr);
        memcpy(&address, &socket_address, sizeof(address));
    }

    freeifaddrs(if_list_head);
    address.sin6_port = htobe16(50000);

    //
    // mbedtls specifica
    //

    // initialize pseudo random number generator
    // FIXME (aw): what is the custom argument about?
    const auto ctr_drbg_seed_result =
        mbedtls_ctr_drbg_seed(&ssl->ctr_drbg, mbedtls_entropy_func, &ssl->entropy, nullptr, 0);
    if (ctr_drbg_seed_result != 0) {
        log_and_raise_mbed_error("Failed in mbedtls_ctr_drbg_seed()", ctr_drbg_seed_result);
    }

    // load certificate
    load_certificates(*ssl, ssl_config);

    // bind to socket "fe80:0000:0000:0000:0042:acff:fe12:0008"
    // FIXME (aw): get this ip string from somewhere instead of handcoded!
    const auto bind_result =
        mbedtls_net_bind(&ssl->listen_fd, "fe80::42:acff:fe12:2%eth0", "50000", MBEDTLS_NET_PROTO_TCP);
    if (bind_result != 0) {
        log_and_raise_mbed_error("Failed to mbedtls_net_bind()", bind_result);
    }

    // setup ssl context configuration
    const auto ssl_config_result = mbedtls_ssl_config_defaults(
        &ssl->conf, MBEDTLS_SSL_IS_SERVER, MBEDTLS_SSL_TRANSPORT_STREAM, MBEDTLS_SSL_PRESET_DEFAULT);
    if (ssl_config_result != 0) {
        log_and_raise_mbed_error("Failed to mbedtls_ssl_config_defaults()", ssl_config_result);
    }

    mbedtls_ssl_conf_rng(&ssl->conf, mbedtls_ctr_drbg_random, &ssl->ctr_drbg);

    mbedtls_ssl_conf_dbg(
        &ssl->conf,
        [](void* callback_context, int debug_level, const char* file_name, int line_number, const char* message) {
            logf("mbedtls debug (level: %d) - %s\n", debug_level, message);
        },
        stdout);
    // mbedtls_debug_set_threshold(3);

    mbedtls_ssl_conf_ca_chain(&ssl->conf, ssl->server_certificate.next, nullptr);
    const auto own_cert_result = mbedtls_ssl_conf_own_cert(&ssl->conf, &ssl->server_certificate, &ssl->pkey);
    if (own_cert_result != 0) {
        log_and_raise_mbed_error("Failed to mbedtls_ssl_conf_own_cert()", own_cert_result);
    }

    const auto ssl_setup_result = mbedtls_ssl_setup(&ssl->ssl, &ssl->conf);
    if (ssl_setup_result != 0) {
        log_and_raise_mbed_error("Failed to mbedtls_ssl_setup()", ssl_setup_result);
    }
}

SessionSSLServer::SessionSSLServer(SessionSSLServer&&) = default;

SessionSSLServer::~SessionSSLServer() = default;

uint16_t SessionSSLServer::get_port() const {
    return be16toh(address.sin6_port);
}

int SessionSSLServer::get_fd() const {
    return ssl->listen_fd.fd;
}

ReadResult SessionSSLServer::read_data(size_t bytes_to_read, uint8_t* buffer, size_t buffer_len) {

    if (state == SessionState::ACCEPTING) {
        const auto accept_result = mbedtls_net_accept(&ssl->listen_fd, &ssl->client_fd, nullptr, 0, nullptr);
        if (accept_result != 0) {
            log_and_raise_mbed_error("Failed to mbedtls_net_accept()", accept_result);
        }

        // setup callbacks for communcation
        mbedtls_ssl_set_bio(&ssl->ssl, &ssl->client_fd, mbedtls_net_send, mbedtls_net_recv, NULL);

        state = SessionState::HANDSHAKE;

        // FIXME (aw): close accept socket!

        // FIXME (aw): this is bogus, we want to pass this differently!
        std::memcpy(buffer, &ssl->client_fd.fd, sizeof(int));

        return {ReadResult::State::ACCEPTED_SESSION, 0};
    } else if (state == SessionState::HANDSHAKE) {

        const auto ssl_handshake_result = mbedtls_ssl_handshake(&ssl->ssl);

        if (ssl_handshake_result != 0) {
            if ((ssl_handshake_result == MBEDTLS_ERR_SSL_WANT_READ) or
                (ssl_handshake_result == MBEDTLS_ERR_SSL_WANT_WRITE)) {
            }

            log_and_raise_mbed_error("Failed to mbedtls_ssl_handshake()", ssl_handshake_result);
        } else {
            // handshake complete!
            logf("Handshake complete!\n");

            state = SessionState::CONNECTED;
        }

        // in case the handshake is complete, we still have to data, but would need more, in order to get a proper
        // header
        return {ReadResult::State::WOULD_BLOCK, 0};
    }

    // fall-through: should be connected
    assert(state == SessionState::CONNECTED);

    const auto ssl_read_result = mbedtls_ssl_read(&ssl->ssl, buffer, bytes_to_read);

    if (ssl_read_result > 0) {
        size_t bytes_read = ssl_read_result;
        return {(bytes_read == bytes_to_read) ? ReadResult::State::READ_COMPLETE : ReadResult::State::WOULD_BLOCK,
                bytes_read};
    }

    if ((ssl_read_result == MBEDTLS_ERR_SSL_WANT_READ) or (ssl_read_result == MBEDTLS_ERR_SSL_WANT_WRITE)) {
        // this should not happen, because we know from poll, that there should be data
        return {ReadResult::State::WOULD_BLOCK, 0};
    }

    log_and_raise_mbed_error("Failed to mbedtls_ssl_read()", ssl_read_result);
    return {ReadResult::State::WOULD_BLOCK, 0};
}

void SessionSSLServer::write_data(const uint8_t* buffer, size_t buffer_len) {
    if (state != SessionState::CONNECTED) {
        log_and_throw("Tried to write data on unconnected session");
    }

    const auto ssl_write_result = mbedtls_ssl_write(&ssl->ssl, buffer, buffer_len);

    if (ssl_write_result < 0) {
        log_and_raise_mbed_error("Failed to mbedtls_ssl_write()", ssl_write_result);
    } else if (ssl_write_result != buffer_len) {
        log_and_throw("Didn't complete to write");
    }
}

} // namespace iso15118::io
