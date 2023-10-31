// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/service_selection.hpp>

#include <iso15118/d20/state/dc_charge_parameter_discovery.hpp>

#include <iso15118/detail/d20/state/service_detail.hpp>
#include <iso15118/detail/d20/state/service_selection.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

void ServiceSelection::enter() {
    ctx.log.enter_state("ServiceSelection");
}

FsmSimpleState::HandleEventReturnType ServiceSelection::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev != FsmEvent::V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    auto variant = ctx.get_request();

    if (variant->get_type() == message_20::Type::ServiceDetailReq) {

        const auto& req = variant->get<message_20::ServiceDetailRequest>();

        logf("Requested info about ServiceID: %d\n", req.service);

        const auto res = handle_request(req, ctx.session, ctx.config);

        ctx.respond(res);

        return sa.HANDLED_INTERNALLY;

    } else if (variant->get_type() == message_20::Type::ServiceSelectionReq) {

        const auto& req = variant->get<message_20::ServiceSelectionRequest>();

        const auto res = handle_request(req, ctx.session, ctx.config);

        ctx.respond(res);

        return sa.create_simple<DC_ChargeParameterDiscovery>(ctx);

    } else {
        ctx.log("expected ServiceDetailReq! But code type id: %d", variant->get_type());
        return sa.PASS_ON;
    }
}

} // namespace iso15118::d20::state
