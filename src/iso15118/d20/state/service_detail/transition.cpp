// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/service_detail.hpp>

#include <iso15118/d20/state/service_selection.hpp>

#include <iso15118/detail/d20/state/service_detail.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

void ServiceDetail::enter() {
    ctx.log.enter_state("ServiceDetail");
}

FsmSimpleState::HandleEventReturnType ServiceDetail::handle_event(AllocatorType& sa, FsmEvent ev) {

    if (ev != FsmEvent::NEW_V2GTP_MESSAGE) {
        return sa.PASS_ON;
    }

    auto variant = ctx.get_request();
    if (variant->get_type() != message_20::Type::ServiceDetailReq) {
        ctx.log("expected ServiceDetailReq! But code type id: %d", variant->get_type());
        return sa.PASS_ON;
    }

    const auto& req = variant->get<message_20::ServiceDetailRequest>();

    logf("Requested info about ServiceID: %d\n", req.service);

    const auto& res = handle_request(req, ctx.session, ctx.config);

    ctx.respond(res);

    return sa.create_simple<ServiceSelection>(ctx);
}

} // namespace iso15118::d20::state
