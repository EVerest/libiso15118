// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/tbd_controller.hpp>

#include <algorithm>
#include <chrono>
#include <cstdio>

#include <iso15118/io/connection_plain.hpp>
#include <iso15118/session/iso.hpp>
#ifdef LIBISO_OPENSSL
#include <iso15118/io/connection_ssl.hpp>
using ConnectionType = iso15118::io::ConnectionSSL;
#else
#include <iso15118/io/connection_tls.hpp>
using ConnectionType = iso15118::io::ConnectionTLS;
#endif

#include <iso15118/detail/helper.hpp>

namespace iso15118 {

TbdController::TbdController(TbdConfig config_, session::feedback::Callbacks callbacks_) :
    config(std::move(config_)), callbacks(std::move(callbacks_)) {
    if (config.enable_sdp_server) {
        sdp_server.init();
        poll_manager.register_fd(sdp_server.get_fd(), [this]() { handle_sdp_server_input(); });
    }
    session_config = d20::SessionConfig();
}

void TbdController::loop() {
    static constexpr auto POLL_MANAGER_TIMEOUT_MS = 50;
    bool session_finished = false;

    if (not config.enable_sdp_server) {
        auto connection = std::make_unique<io::ConnectionPlain>(poll_manager, config.interface_name);
        session = std::make_unique<Session>(std::move(connection), session_config, callbacks);
        session_active = true;
    }

    auto next_event = get_current_time_point();

    while (true) {
        const auto poll_timeout_ms = get_timeout_ms_until(next_event, POLL_MANAGER_TIMEOUT_MS);
        poll_manager.poll(poll_timeout_ms);

        next_event = offset_time_point_by_ms(get_current_time_point(), POLL_MANAGER_TIMEOUT_MS);

        if (session_active == true and session.get() != nullptr) {
            const auto next_session_event = session.get()->poll();
            next_event = std::min(next_event, next_session_event);
            session_finished = session.get()->is_session_finished();
        }

        // Reset session
        if (session_finished) {
            session_finished = false;
            session_active = false;
            if (not config.enable_sdp_server) {
                // Create a connection and start a new session directly
                auto connection = std::make_unique<io::ConnectionPlain>(poll_manager, config.interface_name);
                session = std::make_unique<Session>(std::move(connection), session_config, callbacks);
                session_active = true;
            }
        }
    }
}

void TbdController::send_control_event(const d20::ControlEvent& event) {
    if (session_active == true and session.get() != nullptr) {
        session.get()->push_control_event(event);
    }
}

// Should be called once
void TbdController::setup_config(const std::string& evse_id,
                                 const std::vector<message_20::ServiceCategory>& supported_energy_transfer_services) {
    session_config.evse_id = evse_id;

    if (supported_energy_transfer_services.empty() == false) {
        session_config.supported_energy_transfer_services = supported_energy_transfer_services;
    } else {
        std::runtime_error("Supported energy services are empty!");
    }
}

// Should be called before every session
void TbdController::setup_session(const std::vector<message_20::Authorization>& auth_services,
                                  bool cert_install_service) {

    if (auth_services.empty() == false) {
        session_config.authorization_services = auth_services;
    } else {
        session_config.authorization_services = {{message_20::Authorization::EIM}};
    }

    session_config.cert_install_service = cert_install_service;
}

// Should be called at least once. Values can be updated during session
void TbdController::update_dc_max_values(float max_charge_power, float max_charge_current, float max_voltage,
                                         std::optional<float> max_discharge_power,
                                         std::optional<float> max_discharge_current) {
    session_config.max_charge_power = message_20::from_float(max_charge_power);
    session_config.max_charge_current = message_20::from_float(max_charge_current);
    session_config.max_voltage = message_20::from_float(max_voltage);

    if (max_discharge_power.has_value()) {
        session_config.max_discharge_power = message_20::from_float(max_discharge_power.value());
    }
    if (max_discharge_current.has_value()) {
        session_config.max_discharge_current = message_20::from_float(max_discharge_current.value());
    }
}

// Should be called at least once. Values can be updated during session
void TbdController::update_dc_min_values(float min_charge_power, float min_charge_current, float min_voltage,
                                         std::optional<float> min_discharge_power,
                                         std::optional<float> min_discharge_current) {
    session_config.min_charge_power = message_20::from_float(min_charge_power);
    session_config.min_charge_current = message_20::from_float(min_charge_current);
    session_config.min_voltage = message_20::from_float(min_voltage);

    if (min_discharge_power.has_value()) {
        session_config.min_discharge_power = message_20::from_float(min_discharge_power.value());
    }
    if (min_discharge_current.has_value()) {
        session_config.min_discharge_current = message_20::from_float(min_discharge_current.value());
    }
}

void TbdController::handle_sdp_server_input() {
    auto request = sdp_server.get_peer_request();

    if (not request) {
        return;
    }

    switch (config.tls_negotiation_strategy) {
    case config::TlsNegotiationStrategy::ACCEPT_CLIENT_OFFER:
        // nothing to change
        break;
    case config::TlsNegotiationStrategy::ENFORCE_TLS:
        request.security = io::v2gtp::Security::TLS;
        break;
    case config::TlsNegotiationStrategy::ENFORCE_NO_TLS:
        request.security = io::v2gtp::Security::NO_TRANSPORT_SECURITY;
        break;
    }

    auto connection = [this](bool secure_connection) -> std::unique_ptr<io::IConnection> {
        if (secure_connection) {
            return std::make_unique<ConnectionType>(poll_manager, config.interface_name, config.ssl);
        } else {
            return std::make_unique<io::ConnectionPlain>(poll_manager, config.interface_name);
        }
    }(request.security == io::v2gtp::Security::TLS);

    const auto ipv6_endpoint = connection->get_public_endpoint();

    // Todo(sl): Check if session_config is empty
    session = std::make_unique<Session>(std::move(connection), session_config, callbacks);
    session_active = true;

    sdp_server.send_response(request, ipv6_endpoint);
}

} // namespace iso15118
