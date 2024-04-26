// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <array>
#include <cstdint>
#include <map>
#include <variant>
#include <vector>

#include <iso15118/message/common_types.hpp>

namespace iso15118::d20 {

struct OfferedServices {

    std::vector<message_20::datatypes::Authorization> auth_services;
    std::vector<message_20::datatypes::ServiceCategory> energy_services;
    std::vector<message_20::datatypes::ServiceCategory> vas_services;

    std::map<uint8_t, message_20::datatypes::AcParameterList> ac_parameter_list;
    std::map<uint8_t, message_20::datatypes::AcBptParameterList> ac_bpt_parameter_list;
    std::map<uint8_t, message_20::datatypes::DcParameterList> dc_parameter_list;
    std::map<uint8_t, message_20::datatypes::DcBptParameterList> dc_bpt_parameter_list;
    std::map<uint8_t, message_20::datatypes::InternetParameterList> internet_parameter_list;
    std::map<uint8_t, message_20::datatypes::ParkingParameterList> parking_parameter_list;
};

struct SelectedServiceParameters {
    message_20::datatypes::ServiceCategory selected_energy_service;
    message_20::datatypes::ControlMode selected_control_mode;
};

struct AcSelectedServiceParameters : SelectedServiceParameters {
    message_20::datatypes::AcConnector selected_conntector;
    uint32_t evse_nominal_voltage;
    message_20::datatypes::MobilityNeedsMode selected_mobility_needs_mode;
    message_20::datatypes::Pricing selected_pricing;

    AcSelectedServiceParameters() = default;
    AcSelectedServiceParameters(message_20::datatypes::ServiceCategory energy_service_, message_20::datatypes::ControlMode control_mode_,
                                message_20::datatypes::AcConnector connector_, uint32_t voltage_,
                                message_20::datatypes::MobilityNeedsMode mobility_, message_20::datatypes::Pricing pricing_) :
        selected_conntector(connector_),
        evse_nominal_voltage(voltage_),
        selected_mobility_needs_mode(mobility_),
        selected_pricing(pricing_) {
        selected_energy_service = energy_service_;
        selected_control_mode = control_mode_;
    };
};

struct AcBptSelectedServiceParameters : AcSelectedServiceParameters {
    message_20::datatypes::BptChannel selected_bpt_channel;
    message_20::datatypes::GeneratorMode selected_generator_mode;
    message_20::datatypes::GridCodeIslandingDetectionMethode selected_grid_code_methode;

    AcBptSelectedServiceParameters(message_20::datatypes::ServiceCategory energy_service_, message_20::datatypes::ControlMode control_mode_,
                                   message_20::datatypes::AcConnector connector_, uint32_t voltage_,
                                   message_20::datatypes::MobilityNeedsMode mobility_, message_20::datatypes::Pricing pricing_,
                                   message_20::datatypes::BptChannel channel_, message_20::datatypes::GeneratorMode generator_mode_,
                                   message_20::datatypes::GridCodeIslandingDetectionMethode grid_detect_method_) :
        selected_bpt_channel(channel_),
        selected_generator_mode(generator_mode_),
        selected_grid_code_methode(grid_detect_method_) {
        selected_energy_service = energy_service_;
        selected_control_mode = control_mode_;
        selected_conntector = connector_;
        evse_nominal_voltage = voltage_;
        selected_mobility_needs_mode = mobility_;
        selected_pricing = pricing_;
    };
};

struct DcSelectedServiceParameters : SelectedServiceParameters {
    message_20::datatypes::DcConnector selected_connector;
    message_20::datatypes::MobilityNeedsMode selected_mobility_needs_mode;
    message_20::datatypes::Pricing selected_pricing;

    DcSelectedServiceParameters() = default;
    DcSelectedServiceParameters(message_20::datatypes::ServiceCategory energy_service_, message_20::datatypes::ControlMode control_mode_,
                                message_20::datatypes::DcConnector connector_, message_20::datatypes::MobilityNeedsMode mobility_,
                                message_20::datatypes::Pricing pricing_) :
        selected_mobility_needs_mode(mobility_), selected_pricing(pricing_), selected_connector(connector_) {
        selected_energy_service = energy_service_;
        selected_control_mode = control_mode_;
    };
};

struct DcBptDcSelectedServiceParameters : DcSelectedServiceParameters {
    message_20::datatypes::BptChannel selected_bpt_channel;
    message_20::datatypes::GeneratorMode selected_generator_mode;

    DcBptDcSelectedServiceParameters(message_20::datatypes::ServiceCategory energy_service_, message_20::datatypes::ControlMode control_mode_,
                                     message_20::datatypes::DcConnector dc_connector_, message_20::datatypes::MobilityNeedsMode mobility_,
                                     message_20::datatypes::Pricing pricing_, message_20::datatypes::BptChannel channel_,
                                     message_20::datatypes::GeneratorMode generator_) :
        selected_bpt_channel(channel_), selected_generator_mode(generator_) {
        selected_energy_service = energy_service_;
        selected_control_mode = control_mode_;
        selected_connector = dc_connector_;
        selected_mobility_needs_mode = mobility_;
        selected_pricing = pricing_;
    };
};

// Todo(sl): missing services
// WPT -> ControlMode, Pricing
// DC_ACDP -> ControlMode, MobilityNeedsMode
// DC_ACDP_BPT -> ControlMode, MobilityNeedsMode, BPTChannel

struct SelectedVasParameter {
    std::vector<message_20::datatypes::ServiceCategory> vas_services;

    message_20::datatypes::Protocol internet_protocol;
    message_20::datatypes::Port internet_port;

    message_20::datatypes::IntendedService parking_intended_service;
    message_20::datatypes::ParkingStatus parking_status;
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

    bool find_parameter_set_id(const message_20::datatypes::ServiceCategory service, int16_t id);

    void selected_service_parameters(const message_20::datatypes::ServiceCategory service, const uint16_t id);

    auto get_selected_services() const& {
        return selected_services;
    }

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
