// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/service_detail.hpp>

#include <algorithm>

#include <iso15118/d20/state/service_selection.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/d20/state/service_detail.hpp>
#include <iso15118/detail/d20/state/session_stop.hpp>

#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

namespace {

bool find_service_vas(const std::vector<uint16_t>& req_service_ids, const uint16_t service) {
    return std::find(req_service_ids.begin(), req_service_ids.end(), service) == req_service_ids.end();
}

} // namespace

namespace dt = message_20::datatypes;

message_20::ServiceDetailResponse handle_request(const message_20::ServiceDetailRequest& req, d20::Session& session,
                                                 const d20::SessionConfig& config,
                                                 const std::optional<dt::ServiceParameterList>& custom_vas_parameters) {

    message_20::ServiceDetailResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, dt::ResponseCode::FAILED_UnknownSession);
    }

    bool service_found = false;

    for (auto& energy_service : session.offered_services.energy_services) {
        if (message_20::to_underlying_value(energy_service) == req.service) {
            service_found = true;
            break;
        }
    }

    for (auto& vas_service : session.offered_services.vas_services) {
        if (vas_service == req.service) {
            service_found = true;
            break;
        }
    }

    if (!service_found) {
        return response_with_code(res, dt::ResponseCode::FAILED_ServiceIDInvalid);
    }

    res.service_parameter_list.clear(); // reset default values

    if (custom_vas_parameters.has_value()) {
        logf_info("Sending custom vas parameters");

        const auto& vas_services_ref = custom_vas_parameters.value();

        for (auto& vas : vas_services_ref) {
            session.offered_services.vas_services.push_back(vas.id);
        }

        res.service = req.service;
        res.service_parameter_list = vas_services_ref;
        return response_with_code(res, dt::ResponseCode::OK);
    }

    uint8_t id = 0;

    if (req.service == message_20::to_underlying_value(dt::ServiceCategory::DC)) {
        res.service = message_20::to_underlying_value(dt::ServiceCategory::DC);
        for (auto& parameter_set : config.dc_parameter_list) {
            session.offered_services.dc_parameter_list[id] = parameter_set;
            res.service_parameter_list.push_back(dt::ParameterSet(id++, parameter_set));
        }
    } else if (req.service == message_20::to_underlying_value(dt::ServiceCategory::DC_BPT)) {
        res.service = message_20::to_underlying_value(dt::ServiceCategory::DC_BPT);
        for (auto& parameter_set : config.dc_bpt_parameter_list) {
            session.offered_services.dc_bpt_parameter_list[id] = parameter_set;
            res.service_parameter_list.push_back(dt::ParameterSet(id++, parameter_set));
        }
    } else if (req.service == message_20::to_underlying_value(dt::ServiceCategory::MCS)) {
        res.service = message_20::to_underlying_value(dt::ServiceCategory::MCS);
        for (auto& parameter_set : config.mcs_parameter_list) {
            session.offered_services.mcs_parameter_list[id] = parameter_set;
            res.service_parameter_list.push_back(dt::ParameterSet(id++, parameter_set));
        }
    } else if (req.service == message_20::to_underlying_value(dt::ServiceCategory::MCS_BPT)) {    
        res.service = message_20::to_underlying_value(dt::ServiceCategory::MCS_BPT);
        for (auto& parameter_set : config.mcs_bpt_parameter_list) {
            session.offered_services.mcs_bpt_parameter_list[id] = parameter_set;
            res.service_parameter_list.push_back(dt::ParameterSet(id++, parameter_set));
        }
    } else if (req.service == message_20::to_underlying_value(dt::ServiceCategory::Internet)) {
        res.service =  message_20::to_underlying_value(dt::ServiceCategory::Internet);

        for (auto& parameter_set : config.internet_parameter_list) {
            // TODO(sl): Possibly refactor, define const
            if (parameter_set.port == dt::Port::Port20) {
                id = 1;
            } else if (parameter_set.port == dt::Port::Port21) {
                id = 2;
            } else if (parameter_set.port == dt::Port::Port80) {
                id = 3;
            } else if (parameter_set.port == dt::Port::Port443) {
                id = 4;
            }
            session.offered_services.internet_parameter_list[id] = parameter_set;
            res.service_parameter_list.push_back(dt::ParameterSet(id, parameter_set));
        }
    } else if (req.service == message_20::to_underlying_value(dt::ServiceCategory::ParkingStatus)) {
        res.service = message_20::to_underlying_value(dt::ServiceCategory::ParkingStatus);

        for (auto& parameter_set : config.parking_parameter_list) {
            session.offered_services.parking_parameter_list[id] = parameter_set;
            res.service_parameter_list.push_back(dt::ParameterSet(id++, parameter_set));
        }
    } else {
        logf_warning("There is no parameters for this service %u available. Sending an \"empty\" response.",
                     req.service);
        res.service = req.service;
    }

    return response_with_code(res, dt::ResponseCode::OK);
}

void ServiceDetail::enter() {
    m_ctx.log.enter_state("ServiceDetail");
}

Result ServiceDetail::feed(Event ev) {

    if (ev != Event::V2GTP_MESSAGE) {
        return {};
    }

    const auto variant = m_ctx.pull_request();

    if (const auto req = variant->get_if<message_20::ServiceDetailRequest>()) {
        logf_info("Requested info about ServiceID: %d", req->service);

        using Service = dt::ServiceCategory;
        const std::vector<uint16_t> energy_services{
            message_20::to_underlying_value(Service::AC),         message_20::to_underlying_value(Service::DC),
            message_20::to_underlying_value(Service::WPT),        message_20::to_underlying_value(Service::DC_ACDP),
            message_20::to_underlying_value(Service::AC_BPT),     message_20::to_underlying_value(Service::DC_BPT),
            message_20::to_underlying_value(Service::DC_ACDP_BPT)};

        // TODO(SL): How to handle Internet and ParkingStatus Service?
        std::optional<dt::ServiceParameterList> custom_vas_parameters{std::nullopt};

        if (find_service_vas(energy_services, req->service)) {
            logf_info("Getting custom vas (id: %u) parameters", req->service);
            custom_vas_parameters = m_ctx.feedback.get_vas_parameters(req->service);

            // Check if Internet or ParkingStatus service is in custom_vas_parameters

            // If yes then
        }

        const auto res = handle_request(*req, m_ctx.session, m_ctx.session_config, custom_vas_parameters);

        m_ctx.respond(res);

        if (res.response_code >= dt::ResponseCode::FAILED) {
            m_ctx.session_stopped = true;
            return {};
        }

        return m_ctx.create_state<ServiceSelection>();
    } else if (const auto req = variant->get_if<message_20::SessionStopRequest>()) {
        const auto res = handle_request(*req, m_ctx.session);

        m_ctx.respond(res);
        m_ctx.session_stopped = true;

        return {};
    } else {
        m_ctx.log("expected ServiceDetailReq! But code type id: %d", variant->get_type());

        // Sequence Error
        const message_20::Type req_type = variant->get_type();
        send_sequence_error(req_type, m_ctx);

        m_ctx.session_stopped = true;
        return {};
    }
}

} // namespace iso15118::d20::state
