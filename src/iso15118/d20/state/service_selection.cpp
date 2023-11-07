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
                                                    const d20::Session& session, const d20::Config& config) {

    message_20::ServiceSelectionResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    bool energy_service_found = false;
    bool parameter_set_id_found = false;

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

    switch (req.selected_energy_transfer_service.service_id) {
    case message_20::ServiceCategory::DC:
        if (req.selected_energy_transfer_service.parameter_set_id < config.dc_parameter_list.size()) {
            parameter_set_id_found = true;
        }
        break;

    case message_20::ServiceCategory::DC_BPT:
        if (req.selected_energy_transfer_service.parameter_set_id < config.dc_bpt_parameter_list.size()) {
            parameter_set_id_found = true;
        }
        break;

    default:
        // Todo(sl): fill not supported
        break;
    }

    // Todo(sl): check supported_vas_list parameter set id

    if (!parameter_set_id_found) {
        return response_with_code(res, message_20::ResponseCode::FAILED_ServiceSelectionInvalid);
    }

    auto& session_selected_energy_service = const_cast<message_20::ServiceCategory&>(session.selected_energy_service);
    session_selected_energy_service = req.selected_energy_transfer_service.service_id;

    auto& session_selected_energy_parameter_set_id = const_cast<uint16_t&>(session.selected_energy_parameter_set_id);
    session_selected_energy_parameter_set_id = req.selected_energy_transfer_service.parameter_set_id;

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

        return sa.HANDLED_INTERNALLY;
    } else if (const auto req = variant->get_if<message_20::ServiceSelectionRequest>()) {
        const auto res = handle_request(*req, ctx.session, ctx.config);

        ctx.respond(res);

        return sa.create_simple<DC_ChargeParameterDiscovery>(ctx);
    } else {
        ctx.log("expected ServiceDetailReq! But code type id: %d", variant->get_type());
        return sa.PASS_ON;
    }
}

} // namespace iso15118::d20::state