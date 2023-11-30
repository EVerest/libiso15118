// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/dc_charge_parameter_discovery.hpp>
#include <iso15118/d20/state/service_selection.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/d20/state/service_detail.hpp>
#include <iso15118/detail/d20/state/service_selection.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

message_20::ServiceSelectionResponse handle_request(const message_20::ServiceSelectionRequest& req,
                                                    d20::Session& session, const d20::Config& config) {

    message_20::ServiceSelectionResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    bool energy_service_found = false;

    for (auto& energy_service : config.supported_energy_transfer_services) {
        if (energy_service.service_id == req.selected_energy_transfer_service.service_id) {
            energy_service_found = true;
            break;
        }
    }

    if (!energy_service_found) {
        return response_with_code(res, message_20::ResponseCode::FAILED_NoEnergyTransferServiceSelected);
    }

    // Todo(sl): check supported_vas_list service id

    if (not session.find_parameter_set_id(req.selected_energy_transfer_service.service_id,
                                      req.selected_energy_transfer_service.parameter_set_id)) {
        return response_with_code(res, message_20::ResponseCode::FAILED_ServiceSelectionInvalid);
    }

    // Todo(sl): check supported_vas_list parameter set id

    session.selected_service_parameters(req.selected_energy_transfer_service.service_id,
                                        req.selected_energy_transfer_service.parameter_set_id);

    // TODO(sl): Really important: Save the vas selected services in session!!!

    return response_with_code(res, message_20::ResponseCode::OK);
}

void ServiceSelection::enter() {
    ctx.log.enter_state("ServiceSelection");
}

FsmSimpleState::HandleEventReturnType ServiceSelection::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    const auto variant = ctx.get_request();

    if (const auto req = variant->get_if<message_20::ServiceDetailRequest>()) {
        logf("Requested info about ServiceID: %d\n", req->service);

        const auto res = handle_request(*req, ctx.session, ctx.config);

        ctx.respond(res);

        if (res.response_code >= message_20::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        return sa.HANDLED_INTERNALLY;
    } else if (const auto req = variant->get_if<message_20::ServiceSelectionRequest>()) {
        const auto res = handle_request(*req, ctx.session, ctx.config);

        ctx.respond(res);

        if (res.response_code >= message_20::ResponseCode::FAILED) {
            ctx.session_stopped = true;
            return sa.PASS_ON;
        }

        return sa.create_simple<DC_ChargeParameterDiscovery>(ctx);
    } else {
        ctx.log("expected ServiceDetailReq! But code type id: %d", variant->get_type());
        ctx.session_stopped = true;
        return sa.PASS_ON;
    }
}

} // namespace iso15118::d20::state
