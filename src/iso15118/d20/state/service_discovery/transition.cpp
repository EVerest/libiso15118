// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/service_discovery.hpp>

#include <iso15118/d20/state/service_detail.hpp>

#include <iso15118/detail/d20/state/service_discovery.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

void ServiceDiscovery::enter() {
    ctx.log.enter_state("ServiceDiscovery");
}

FsmSimpleState::HandleEventReturnType ServiceDiscovery::handle_event(AllocatorType& sa, FsmEvent ev) {
    if (ev == FsmEvent::V2GTP_MESSAGE) {
        auto variant = ctx.get_request();
        if (variant->get_type() != message_20::Type::ServiceDiscoveryReq) {
            ctx.log("expected ServiceDiscoveryReq! But code type id: %d", variant->get_type());
            return sa.PASS_ON;
        }

        const auto& req = variant->get<message_20::ServiceDiscoveryRequest>();

        if (req.supported_service_ids) {
            logf("Possible ids\n");
            for (auto id : req.supported_service_ids.value()) {
                logf("  %d\n", id);
            }
        }

        const auto res = handle_request(req, ctx.session, ctx.config);

        ctx.respond(res);

        return sa.create_simple<ServiceDetail>(ctx);
    }

    return sa.PASS_ON;
}

} // namespace iso15118::d20::state
