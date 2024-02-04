// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d2/state/authorization.hpp>
#include <iso15118/d2/state/service_selection.hpp>
#include <iso15118/d2/config.hpp>

#include <iso15118/detail/d2/context_helper.hpp>
#include <iso15118/detail/d2/state/service_detail.hpp>
#include <iso15118/detail/d2/state/service_selection.hpp>
#include <iso15118/detail/d2/state/session_stop.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d2::state {

message_2::ServiceSelectionResponse handle_request(const message_2::ServiceSelectionRequest& req,
                                                    d2::Session& session) {

    message_2::ServiceSelectionResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_2::ResponseCode::FAILED_UnknownSession);
    }

    bool energy_service_found = false;
    bool vas_services_found = false;

    for (auto& energy_service : session.offered_services.energy_services) {
        if (energy_service == req.selected_energy_transfer_service.service_id) {
            energy_service_found = true;
            break;
        }
    }

    if (!energy_service_found) {
        //RDB change response code to equivalent
        return response_with_code(res, message_2::ResponseCode::FAILED_NoChargeServiceSelected);
    }

    if (req.selected_vas_list.has_value()) {
        auto& selected_vas_list = req.selected_vas_list.value();

        for (auto& vas_service : selected_vas_list) {
            if (std::find(session.offered_services.vas_services.begin(), session.offered_services.vas_services.end(),
                          vas_service.service_id) == session.offered_services.vas_services.end()) {
                vas_services_found = false;
                break;
            }
            vas_services_found = true;
        }

        if (not vas_services_found) {
            return response_with_code(res, message_2::ResponseCode::FAILED_ServiceSelectionInvalid);
        }
    }

    //RDB ISO2 allows parameter lists to be optional so ignore this. It turns out that we need to simulate this
    // by adding in a hard coded DC parameter list so that DC charge parameter discovery works.
    //RDB TODO allow parameter lists
    // if (not session.find_parameter_set_id(req.selected_energy_transfer_service.service_id,
    //                                       req.selected_energy_transfer_service.parameter_set_id)) {
    //     return response_with_code(res, message_2::ResponseCode::FAILED_ServiceSelectionInvalid);
    // }

    // RDB TODO Hack to get around the parameter list issue.
    session.offered_services.energy_services = {message_2::ServiceCategory::DC};
    session.offered_services.dc_parameter_list[0] = {
        message_2::DcConnector::Extended,
        message_2::ControlMode::Scheduled,
        message_2::MobilityNeedsMode::ProvidedByEvcc,
        message_2::Pricing::NoPricing,
    };
    session.selected_service_parameters(req.selected_energy_transfer_service.service_id, 0);

    if (req.selected_vas_list.has_value()) {
        auto& selected_vas_list = req.selected_vas_list.value();

        for (auto& vas_service : selected_vas_list) {
            if (not session.find_parameter_set_id(vas_service.service_id, vas_service.parameter_set_id)) {
                return response_with_code(res, message_2::ResponseCode::FAILED_ServiceSelectionInvalid);
            }
            session.selected_service_parameters(vas_service.service_id, vas_service.parameter_set_id);
        }
    }

    return response_with_code(res, message_2::ResponseCode::OK);
}

void ServiceSelection::enter() {
    ctx.log.enter_state("ServiceSelection");
}

FsmSimpleState::HandleEventReturnType ServiceSelection::handle_event(AllocatorType& sa, FsmEvent ev) {

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

        return sa.HANDLED_INTERNALLY;
    } else if (const auto req = variant->get_if<message_2::ServiceSelectionRequest>()) {
        const auto res = handle_request(*req, ctx.session);

        ctx.respond(res);

        if (res.response_code >= message_2::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        //RDB ISO2 goes to Authorization next
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
