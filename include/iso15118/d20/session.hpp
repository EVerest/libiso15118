// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <array>
#include <cstdint>
#include <map>
#include <variant>
#include <vector>

#include <iso15118/message/msg_data_types.hpp>

namespace iso15118::d20 {

namespace datatypes = message_20::datatypes;

struct OfferedServices {

    std::vector<datatypes::Authorization> auth_services;
    std::vector<datatypes::ServiceCategory> energy_services;
    std::vector<datatypes::ServiceCategory> vas_services;

    std::map<uint8_t, datatypes::DcParameterList> dc_parameter_list;
    std::map<uint8_t, datatypes::DcBptParameterList> dc_bpt_parameter_list;
    std::map<uint8_t, datatypes::InternetParameterList> internet_parameter_list;
    std::map<uint8_t, datatypes::ParkingParameterList> parking_parameter_list;
};

struct SelectedServiceParameters {

    datatypes::ServiceCategory selected_energy_service;

    std::variant<datatypes::AcConnector, datatypes::DcConnector> selected_connector;
    datatypes::ControlMode selected_control_mode;
    datatypes::MobilityNeedsMode selected_mobility_needs_mode;
    datatypes::Pricing selected_pricing;

    datatypes::BptChannel selected_bpt_channel;
    datatypes::GeneratorMode selected_generator_mode;

    SelectedServiceParameters(){}; // TODO(sl): What to do here?
    // Constructor for DC
    SelectedServiceParameters(datatypes::ServiceCategory energy_service_, datatypes::DcConnector dc_connector_,
                              datatypes::ControlMode control_mode_, datatypes::MobilityNeedsMode mobility_,
                              datatypes::Pricing pricing_) :
        selected_energy_service(energy_service_),
        selected_control_mode(control_mode_),
        selected_mobility_needs_mode(mobility_),
        selected_pricing(pricing_) {
        selected_connector.emplace<datatypes::DcConnector>(dc_connector_);
    };

    // Constructor for DC_BPT
    SelectedServiceParameters(datatypes::ServiceCategory energy_service_, datatypes::DcConnector dc_connector_,
                              datatypes::ControlMode control_mode_, datatypes::MobilityNeedsMode mobility_,
                              datatypes::Pricing pricing_, datatypes::BptChannel channel_,
                              datatypes::GeneratorMode generator_) :
        selected_energy_service(energy_service_),
        selected_control_mode(control_mode_),
        selected_mobility_needs_mode(mobility_),
        selected_pricing(pricing_),
        selected_bpt_channel(channel_),
        selected_generator_mode(generator_) {
        selected_connector.emplace<datatypes::DcConnector>(dc_connector_);
    };
};

struct SelectedVasParameter {
    std::vector<datatypes::ServiceCategory> vas_services;

    datatypes::Protocol internet_protocol;
    datatypes::Port internet_port;

    datatypes::IntendedService parking_intended_service;
    datatypes::ParkingStatus parking_status;
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

    bool find_parameter_set_id(const datatypes::ServiceCategory service, int16_t id);

    void selected_service_parameters(const datatypes::ServiceCategory service, const uint16_t id);

    datatypes::ServiceCategory get_selected_energy_service() const {
        return selected_services.selected_energy_service;
    }

    datatypes::ControlMode get_selected_control_mode() const {
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

} // namespace iso15118::d20
