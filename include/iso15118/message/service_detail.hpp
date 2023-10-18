// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <string>
#include <variant>
#include <vector>

#include "common.hpp"

namespace iso15118::message_20 {

// todo(sl): find a better place for the parameter struct and enum definitions
enum class AcConnector {
    SinglePhase = 1,
    ThreePhase = 3,
};
enum class DcConnector {
    Core = 1,
    Extended = 2,
    Dual2 = 3,
    Dual4 = 4,
};
enum class ControlMode {
    Scheduled = 1,
    Dynamic = 2,
};
enum class MobilityNeedsMode {
    ProvidedByEvcc = 1,
    ProvidedBySecc = 2,
};
enum class Pricing {
    NoPricing = 0,
    AbsolutePricing = 1,
    PriceLevels = 2,
};

enum class BptChannel {
    Unified = 1,
    Separated = 2,
};

enum class GeneratorMode {
    GridFollowing = 1,
    GridForming = 2,
};

struct AcParameterList {
    AcConnector connector;
    ControlMode control_mode;
    MobilityNeedsMode mobility_needs_mode;
    uint32_t evse_nominal_voltage;
    Pricing pricing;
};

struct AcBptParameterList : AcParameterList {
    enum class GridCodeIslandingDetectionMethode {
        Active = 1,
        Passive = 2,
    };
    BptChannel bpt_channel;
    GeneratorMode generator_mode;
    GridCodeIslandingDetectionMethode grid_code_detection_methode;
};

struct DcParameterList {
    DcConnector connector;
    ControlMode control_mode;
    MobilityNeedsMode mobility_needs_mode;
    Pricing pricing;
};

struct DcBptParameterList : DcParameterList {
    BptChannel bpt_channel;
    GeneratorMode generator_mode;
};

// todo(sl): Adding internet and parking status service

struct ServiceDetailRequest {
    Header header;
    ServiceCategory service;
};

struct ServiceDetailResponse {
    struct Parameter {
        std::string name;
        std::variant<bool, int8_t, int16_t, int32_t, std::string, RationalNumber>
            value; // todo(sl): refactor because ISO-20 use only int32_t values
    };

    struct ParameterSet {
        uint16_t id;
        std::vector<Parameter> parameter;

        ParameterSet();
        ParameterSet(uint16_t _id, const DcParameterList& list);
        ParameterSet(uint16_t _id, const DcBptParameterList& list);
    };

    Header header;
    ResponseCode response_code;
    ServiceCategory service = ServiceCategory::DC;
    std::vector<ParameterSet> service_parameter_list = {ParameterSet()};
};

} // namespace iso15118::message_20
