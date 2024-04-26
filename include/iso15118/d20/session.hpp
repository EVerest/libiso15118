// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <array>
#include <cstdint>
#include <map>
#include <memory>
#include <variant>
#include <vector>

#include <iso15118/message/common_types.hpp>

namespace iso15118::d20 {

namespace dt = message_20::datatypes;

struct OfferedServices {
    std::vector<dt::Authorization> auth_services;
    std::vector<dt::ServiceCategory> energy_services;
    std::vector<dt::ServiceCategory> vas_services;

    std::map<uint8_t, dt::AcParameterList> ac_parameter_list;
    std::map<uint8_t, dt::AcBptParameterList> ac_bpt_parameter_list;
    std::map<uint8_t, dt::DcParameterList> dc_parameter_list;
    std::map<uint8_t, dt::DcBptParameterList> dc_bpt_parameter_list;
    std::map<uint8_t, dt::InternetParameterList> internet_parameter_list;
    std::map<uint8_t, dt::ParkingParameterList> parking_parameter_list;
};

struct SelectedServiceParameters {
    dt::ServiceCategory selected_energy_service;
    dt::ControlMode selected_control_mode;
    dt::MobilityNeedsMode selected_mobility_needs_mode;

    SelectedServiceParameters() {
    }

    SelectedServiceParameters(dt::ServiceCategory selected_energy_service_, dt::ControlMode selected_control_mode_,
                              dt::MobilityNeedsMode selected_mobility_needs_mode_) :
        selected_energy_service(selected_energy_service_),
        selected_control_mode(selected_control_mode_),
        selected_mobility_needs_mode(selected_mobility_needs_mode_) {
    }
};

struct AcSelectedServiceParameters : SelectedServiceParameters {
    dt::AcConnector selected_conntector;
    uint32_t evse_nominal_voltage;
    dt::Pricing selected_pricing;

    AcSelectedServiceParameters() = default;
    AcSelectedServiceParameters(dt::ServiceCategory energy_service_, dt::ControlMode control_mode_,
                                dt::AcConnector connector_, uint32_t voltage_, dt::MobilityNeedsMode mobility_,
                                dt::Pricing pricing_) :
        SelectedServiceParameters(energy_service_, control_mode_, mobility_),
        selected_conntector(connector_),
        evse_nominal_voltage(voltage_),
        selected_pricing(pricing_){};
};

struct AcBptSelectedServiceParameters : AcSelectedServiceParameters {
    dt::BptChannel selected_bpt_channel;
    dt::GeneratorMode selected_generator_mode;
    dt::GridCodeIslandingDetectionMethode selected_grid_code_methode;

    AcBptSelectedServiceParameters(dt::ServiceCategory energy_service_, dt::ControlMode control_mode_,
                                   dt::AcConnector connector_, uint32_t voltage_, dt::MobilityNeedsMode mobility_,
                                   dt::Pricing pricing_, dt::BptChannel channel_, dt::GeneratorMode generator_mode_,
                                   dt::GridCodeIslandingDetectionMethode grid_detect_method_) :
        AcSelectedServiceParameters(energy_service_, control_mode_, connector_, voltage_, mobility_, pricing_),
        selected_bpt_channel(channel_),
        selected_generator_mode(generator_mode_),
        selected_grid_code_methode(grid_detect_method_){};
};

struct DcSelectedServiceParameters : SelectedServiceParameters {
    dt::DcConnector selected_connector;
    dt::Pricing selected_pricing;

    DcSelectedServiceParameters() = default;
    DcSelectedServiceParameters(dt::ServiceCategory energy_service_, dt::DcConnector connector_,
                                dt::ControlMode control_mode_, dt::MobilityNeedsMode mobility_, dt::Pricing pricing_) :
        SelectedServiceParameters(energy_service_, control_mode_, mobility_),
        selected_connector(connector_),
        selected_pricing(pricing_){

        };
};

struct DcBptSelectedServiceParameters : DcSelectedServiceParameters {
    dt::BptChannel selected_bpt_channel;
    dt::GeneratorMode selected_generator_mode;

    DcBptSelectedServiceParameters(dt::ServiceCategory energy_service_, dt::DcConnector dc_connector_,
                                   dt::ControlMode control_mode_, dt::MobilityNeedsMode mobility_, dt::Pricing pricing_,
                                   dt::BptChannel channel_, dt::GeneratorMode generator_) :
        DcSelectedServiceParameters(energy_service_, dc_connector_, control_mode_, mobility_, pricing_),
        selected_bpt_channel(channel_),
        selected_generator_mode(generator_){};
};

// Todo(sl): missing services
// WPT -> ControlMode, Pricing
// DC_ACDP -> ControlMode, MobilityNeedsMode
// DC_ACDP_BPT -> ControlMode, MobilityNeedsMode, BPTChannel

struct SelectedVasParameter {
    std::vector<dt::ServiceCategory> vas_services;

    dt::Protocol internet_protocol;
    dt::Port internet_port;

    dt::IntendedService parking_intended_service;
    dt::ParkingStatus parking_status;
};

class Session {

    // todo(sl): move to a common defs file
    static constexpr auto ID_LENGTH = 8;

public:
    Session();
    Session(const AcSelectedServiceParameters&);
    Session(const AcBptSelectedServiceParameters&);
    Session(const DcSelectedServiceParameters&);
    Session(const DcBptSelectedServiceParameters&);
    Session(OfferedServices);

    std::array<uint8_t, ID_LENGTH> get_id() const {
        return id;
    }

    bool find_parameter_set_id(const dt::ServiceCategory service, int16_t id);

    void selected_service_parameters(const dt::ServiceCategory service, const uint16_t id);

    const SelectedServiceParameters& get_selected_services() const {
        // All vararg params inherit from 'SelectedServiceParameters'
        auto visitor = [](const auto& val) -> const SelectedServiceParameters& { return val; };

        return std::visit(visitor, selected_services);
    }

    auto& get_var_selected_services() const {
        // In case we need the vararg access
        return selected_services;
    }

    ~Session();

    OfferedServices offered_services;

    bool service_renegotiation_supported{false};

private:
    // NOTE (aw): could be const
    std::array<uint8_t, ID_LENGTH> id{};

    // Request was to change this to a vararg instead of a shared pointer
    std::variant<AcSelectedServiceParameters, AcBptSelectedServiceParameters, DcSelectedServiceParameters,
                 DcBptSelectedServiceParameters>
        selected_services;
    SelectedVasParameter selected_vas_services;
};

} // namespace iso15118::d20
