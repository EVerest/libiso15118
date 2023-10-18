// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/detail/d20/state/service_detail.hpp>

#include <iso15118/detail/d20/context_helper.hpp>

namespace iso15118::d20::state {

message_20::ServiceDetailResponse handle_request(const message_20::ServiceDetailRequest& req,
                                                 const d20::Session& session, const d20::Config& config) {

    message_20::ServiceDetailResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    bool service_found = false;

    for (auto& energy_service : config.supported_energy_transfer_services) {
        if (energy_service.service_id == req.service) {
            service_found = true;
            break;
        }
    }

    for (auto& vas_service : config.supported_vas_services) {
        if (vas_service.service_id == req.service) {
            service_found = true;
            break;
        }
    }

    if (!service_found) {
        return response_with_code(res, message_20::ResponseCode::FAILED_ServiceIDInvalid);
    }

    res.service_parameter_list.clear(); // reset default values

    uint8_t id = 0;

    switch (req.service) {
    case message_20::ServiceCategory::DC:
        res.service = message_20::ServiceCategory::DC;
        for (auto& parameter_set : config.dc_parameter_list) {
            res.service_parameter_list.push_back(message_20::ServiceDetailResponse::ParameterSet(id++, parameter_set));
        }
        break;
    case message_20::ServiceCategory::DC_BPT:
        res.service = message_20::ServiceCategory::DC_BPT;
        for (auto& parameter_set : config.dc_bpt_parameter_list) {
            res.service_parameter_list.push_back(message_20::ServiceDetailResponse::ParameterSet(id++, parameter_set));
        }
        break;
    default:
        // Todo(sl): fill not supported
        break;
    }

    return response_with_code(res, message_20::ResponseCode::OK);
}

} // namespace iso15118::d20::state
