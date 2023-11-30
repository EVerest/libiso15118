// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <array>
#include <cstdint>
#include <map>
#include <variant>
#include <vector>

#include <iso15118/message/common.hpp>

namespace iso15118::d20 {

struct OfferedServices {

    std::vector<message_20::Authorization> auth_services;
    // std::vector<> energy_services;
    // std::vector<> vas_services;

    std::map<uint8_t, message_20::DcParameterList> dc_parameter_list;
    std::map<uint8_t, message_20::DcBptParameterList> dc_bpt_parameter_list;
};

struct SelectedServiceParameters {

    message_20::ServiceCategory selected_energy_service;

    std::variant<message_20::AcConnector, message_20::DcConnector> selected_connector;
    message_20::ControlMode selected_control_mode;
    message_20::MobilityNeedsMode selected_mobility_needs_mode;
    message_20::Pricing selected_pricing;

    message_20::BptChannel selected_bpt_channel;
    message_20::GeneratorMode selected_generator_mode;

    SelectedServiceParameters(){}; // TODO(sl): What to do here?
    // Constructor for DC
    SelectedServiceParameters(message_20::ServiceCategory energy_service_, message_20::DcConnector dc_connector_,
                              message_20::ControlMode control_mode_, message_20::MobilityNeedsMode mobility_,
                              message_20::Pricing pricing_) :
        selected_energy_service(energy_service_),
        selected_control_mode(control_mode_),
        selected_mobility_needs_mode(mobility_),
        selected_pricing(pricing_) {
        selected_connector.emplace<message_20::DcConnector>(dc_connector_);
    };

    // Constructor for DC_BPT
    SelectedServiceParameters(message_20::ServiceCategory energy_service_, message_20::DcConnector dc_connector_,
                              message_20::ControlMode control_mode_, message_20::MobilityNeedsMode mobility_,
                              message_20::Pricing pricing_, message_20::BptChannel channel_,
                              message_20::GeneratorMode generator_) :
        selected_energy_service(energy_service_),
        selected_control_mode(control_mode_),
        selected_mobility_needs_mode(mobility_),
        selected_pricing(pricing_),
        selected_bpt_channel(channel_),
        selected_generator_mode(generator_) {
        selected_connector.emplace<message_20::DcConnector>(dc_connector_);
    };
};

class Session {

    // todo(sl): move to a common defs file
    static constexpr auto ID_LENGTH = 8;

public:
    Session();
    Session(SelectedServiceParameters service_parameters_) : selected_services(service_parameters_){};
    Session(OfferedServices services_) : offered_services(services_){};

    void save_offered_auth_services(const std::vector<message_20::Authorization> services) {
        offered_services.auth_services = services;
    }

    void save_offered_parameter_list(const uint8_t id, const message_20::DcParameterList list) {
        offered_services.dc_parameter_list[id] = list;
    }

    void save_offered_parameter_list(const uint8_t id, const message_20::DcBptParameterList list) {
        offered_services.dc_bpt_parameter_list[id] = list;
    }

    std::vector<message_20::Authorization> get_offered_auth_services() const {
        return offered_services.auth_services;
    }

    bool find_parameter_set_id(const message_20::ServiceCategory service, int16_t id);

    void selected_service_parameters(const message_20::ServiceCategory service, const uint16_t id);

    message_20::ServiceCategory get_selected_energy_service() const {
        return selected_services.selected_energy_service;
    }

    message_20::ControlMode get_selected_control_mode() const {
        return selected_services.selected_control_mode;
    }

    ~Session();

    // NOTE (aw): could be const
    std::array<uint8_t, ID_LENGTH> id{};

    std::vector<message_20::ServiceCategory> selected_vas_services;
    std::vector<uint16_t> selected_vas_parameter_set_id;

private:
    OfferedServices offered_services;

    SelectedServiceParameters selected_services;
};

} // namespace iso15118::d20
