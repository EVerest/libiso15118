// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d2/state/service_detail.hpp>
#include <iso15118/d2/state/service_selection.hpp>
#include <iso15118/d2/state/authorization.hpp>


#include <iso15118/detail/d2/context_helper.hpp>
#include <iso15118/detail/d2/state/service_detail.hpp>
#include <iso15118/detail/d2/state/service_selection.hpp>
#include <iso15118/detail/d2/state/session_stop.hpp>

#include <iso15118/detail/helper.hpp>

namespace iso15118::d2::state {

message_2::ServiceDetailResponse handle_request(const message_2::ServiceDetailRequest& req, d2::Session& session,
                                                 const d2::SessionConfig& config) {

    message_2::ServiceDetailResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_2::ResponseCode::FAILED_UnknownSession);
    }

    bool service_found = false;

    for (auto& energy_service : session.offered_services.energy_services) {
        if (energy_service == req.service) {
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
        return response_with_code(res, message_2::ResponseCode::FAILED_ServiceIDInvalid);
    }

    res.service_parameter_list.clear(); // reset default values

    uint8_t id = 0;

    switch (req.service) {
    case message_2::ServiceCategory::DC:
        res.service = message_2::ServiceCategory::DC;
        for (auto& parameter_set : config.dc_parameter_list) {
            session.offered_services.dc_parameter_list[id] = parameter_set;
            res.service_parameter_list.push_back(message_2::ServiceDetailResponse::ParameterSet(id++, parameter_set));
        }
        break;
    case message_2::ServiceCategory::DC_BPT:
        res.service = message_2::ServiceCategory::DC_BPT;
        for (auto& parameter_set : config.dc_bpt_parameter_list) {
            session.offered_services.dc_bpt_parameter_list[id] = parameter_set;
            res.service_parameter_list.push_back(message_2::ServiceDetailResponse::ParameterSet(id++, parameter_set));
        }
        break;

    case message_2::ServiceCategory::Internet:
        res.service = message_2::ServiceCategory::Internet;

        for (auto& parameter_set : config.internet_parameter_list) {
            // TODO(sl): Possibly refactor, define const
            if (parameter_set.port == message_2::Port::Port20) {
                id = 1;
            } else if (parameter_set.port == message_2::Port::Port21) {
                id = 2;
            } else if (parameter_set.port == message_2::Port::Port80) {
                id = 3;
            } else if (parameter_set.port == message_2::Port::Port443) {
                id = 4;
            }
            session.offered_services.internet_parameter_list[id] = parameter_set;
            res.service_parameter_list.push_back(message_2::ServiceDetailResponse::ParameterSet(id, parameter_set));
        }

        break;

    case message_2::ServiceCategory::ParkingStatus:
        res.service = message_2::ServiceCategory::ParkingStatus;

        for (auto& parameter_set : config.parking_parameter_list) {
            session.offered_services.parking_parameter_list[id] = parameter_set;
            res.service_parameter_list.push_back(message_2::ServiceDetailResponse::ParameterSet(id++, parameter_set));
        }
        break;

    default:
        // Todo(sl): fill not supported
        break;
    }

    return response_with_code(res, message_2::ResponseCode::OK);
}

void ServiceDetail::enter() {
    ctx.log.enter_state("ServiceDetail");
}

FsmSimpleState::HandleEventReturnType ServiceDetail::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    const auto variant = ctx.get_request();

    if (const auto req = variant->get_if<message_2::ServiceDetailRequest>()) {
        logf("Requested info about ServiceID: %d\n", req->service);

        const auto res = handle_request(*req, ctx.session, ctx.config);

        ctx.respond(res);

        if (res.response_code >= message_2::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        return sa.create_simple<ServiceSelection>(ctx);
    } else if (const auto req = variant->get_if<message_2::ServiceSelectionRequest>()){
        //RDB add this case since in ISO2 apparently this can happen, going directly to PaymentServiceSelection with no service detail req.
        const auto res = handle_request(*req, ctx.session);

        // RDB ISO2 allows parameter lists to be optional so ignore this. It turns out that we need to simulate this
        //  by adding in a hard coded DC parameter list so that DC charge parameter discovery works.
        //  RDB TODO this is a hack.
        for (auto& parameter_set : ctx.config.dc_parameter_list) {
            ctx.session.offered_services.dc_parameter_list[0] = parameter_set;
        }

        ctx.respond(res);

        if (res.response_code >= message_2::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        return sa.create_simple<Authorization>(ctx);

    } else if (const auto req = variant->get_if<message_2::SessionStopRequest>()) {
        const auto res = handle_request(*req, ctx.session);

        ctx.respond(res);
        ctx.session_stopped = true;

        return sa.PASS_ON;
    } else {
        ctx.log("expected ServiceDetailReq! But code type id: %d", variant->get_type());

        // Sequence Error
        const message_2::Type req_type = variant->get_type();
        send_sequence_error(req_type, ctx);

        ctx.session_stopped = true;
        return sa.PASS_ON;
    }
}

} // namespace iso15118::d2::state
