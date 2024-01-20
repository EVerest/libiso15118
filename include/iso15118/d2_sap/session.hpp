// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <array>
#include <cstdint>
#include <map>
#include <variant>
#include <vector>

#include <iso15118/message_d2_sap/common.hpp>

namespace iso15118::d2_sap{

struct OfferedServices {

    std::vector<message_2_sap::Authorization> auth_services;
    std::vector<message_2_sap::ServiceCategory> energy_services;
    std::vector<message_2_sap::ServiceCategory> vas_services;

    std::map<uint8_t, message_2_sap::DcParameterList> dc_parameter_list;
    std::map<uint8_t, message_2_sap::DcBptParameterList> dc_bpt_parameter_list;
    std::map<uint8_t, message_2_sap::InternetParameterList> internet_parameter_list;
    std::map<uint8_t, message_2_sap::ParkingParameterList> parking_parameter_list;
};

struct SelectedServiceParameters {

    message_2_sap::ServiceCategory selected_energy_service;

    std::variant<message_2_sap::AcConnector, message_2_sap::DcConnector> selected_connector;
    message_2_sap::ControlMode selected_control_mode;
    message_2_sap::MobilityNeedsMode selected_mobility_needs_mode;
    message_2_sap::Pricing selected_pricing;

    message_2_sap::BptChannel selected_bpt_channel;
    message_2_sap::GeneratorMode selected_generator_mode;

    SelectedServiceParameters(){}; // TODO(sl): What to do here?
    // Constructor for DC
    SelectedServiceParameters(message_2_sap::ServiceCategory energy_service_, message_2_sap::DcConnector dc_connector_,
                              message_2_sap::ControlMode control_mode_, message_2_sap::MobilityNeedsMode mobility_,
                              message_2_sap::Pricing pricing_) :
        selected_energy_service(energy_service_),
        selected_control_mode(control_mode_),
        selected_mobility_needs_mode(mobility_),
        selected_pricing(pricing_) {
        selected_connector.emplace<message_2_sap::DcConnector>(dc_connector_);
    };

    // Constructor for DC_BPT
    SelectedServiceParameters(message_2_sap::ServiceCategory energy_service_, message_2_sap::DcConnector dc_connector_,
                              message_2_sap::ControlMode control_mode_, message_2_sap::MobilityNeedsMode mobility_,
                              message_2_sap::Pricing pricing_, message_2_sap::BptChannel channel_,
                              message_2_sap::GeneratorMode generator_) :
        selected_energy_service(energy_service_),
        selected_control_mode(control_mode_),
        selected_mobility_needs_mode(mobility_),
        selected_pricing(pricing_),
        selected_bpt_channel(channel_),
        selected_generator_mode(generator_) {
        selected_connector.emplace<message_2_sap::DcConnector>(dc_connector_);
    };
};

struct SelectedVasParameter {
    std::vector<message_2_sap::ServiceCategory> vas_services;

    message_2_sap::Protocol internet_protocol;
    message_2_sap::Port internet_port;

    message_2_sap::IntendedService parking_intended_service;
    message_2_sap::ParkingStatus parking_status;
};

class Session {

    // todo(sl): move to a common defs file
    static constexpr auto ID_LENGTH = 8;

public:
    Session();
    Session(SelectedServiceParameters);
    Session(OfferedServices);

    std::array<uint8_t, ID_LENGTH> get_id() const {
        return id;
    }

    bool find_parameter_set_id(const message_2_sap::ServiceCategory service, int16_t id);

    void selected_service_parameters(const message_2_sap::ServiceCategory service, const uint16_t id);

    message_2_sap::ServiceCategory get_selected_energy_service() const {
        return selected_services.selected_energy_service;
    }

    message_2_sap::ControlMode get_selected_control_mode() const {
        return selected_services.selected_control_mode;
    }

    // TODO(sl): Define get_selected_*() if necessary

    ~Session();

    OfferedServices offered_services;

    bool service_renegotiation_supported{false};

private:
    // NOTE (aw): could be const
    std::array<uint8_t, ID_LENGTH> id{};

    SelectedServiceParameters selected_services;
    SelectedVasParameter selected_vas_services;
};

} // namespace iso15118::d2_sap
