// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/session.hpp>

#include <random>

namespace iso15118::d20 {

Session::Session() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<uint8_t> distribution(0x00, 0xff);

    for (auto& item : id) {
        item = distribution(generator);
    }
}

Session::~Session() = default;

bool Session::find_parameter_set_id(const message_20::ServiceCategory service, int16_t id) {

    switch (service) {
    case message_20::ServiceCategory::DC:

        if (this->offered_services.dc_parameter_list.find(id) != this->offered_services.dc_parameter_list.end()) {
            return true;
        }
        break;

    case message_20::ServiceCategory::DC_BPT:
        if (this->offered_services.dc_bpt_parameter_list.find(id) !=
            this->offered_services.dc_bpt_parameter_list.end()) {
            return true;
        }
        break;

    default:
        break;
    }

    return false;
}

void Session::selected_service_parameters(const message_20::ServiceCategory service, const uint16_t id) {

    switch (service) {
    case message_20::ServiceCategory::DC:

        if (this->offered_services.dc_parameter_list.find(id) != this->offered_services.dc_parameter_list.end()) {
            auto& parameters = this->offered_services.dc_parameter_list.at(id);
            this->selected_services =
                SelectedServiceParameters(message_20::ServiceCategory::DC, parameters.connector,
                                          parameters.control_mode, parameters.mobility_needs_mode, parameters.pricing);
        } else {
            // Todo(sl): Should be not the case -> Raise Error?
        }
        break;

    case message_20::ServiceCategory::DC_BPT:
        if (this->offered_services.dc_bpt_parameter_list.find(id) !=
            this->offered_services.dc_bpt_parameter_list.end()) {
            auto& parameters = this->offered_services.dc_bpt_parameter_list.at(id);
            this->selected_services = SelectedServiceParameters(
                message_20::ServiceCategory::DC_BPT, parameters.connector, parameters.control_mode,
                parameters.mobility_needs_mode, parameters.pricing, parameters.bpt_channel, parameters.generator_mode);
        } else {
            // Todo(sl): Should be not the case -> Raise Error?
        }
        break;

    default:
        break;
    }
}

} // namespace iso15118::d20
