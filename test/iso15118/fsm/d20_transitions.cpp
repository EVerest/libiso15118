// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <catch2/catch_test_macros.hpp>

#include "helper.hpp"

#include <iso15118/d20/state/session_setup.hpp>
#include <iso15118/d20/state/supported_app_protocol.hpp>

#include <iso15118/message/supported_app_protocol.hpp>

using namespace iso15118;

namespace iso15118::d20::state {
extern std::tuple<message_20::SupportedAppProtocolResponse, std::optional<std::string>>
handle_request(const message_20::SupportedAppProtocolRequest& req);
}

SCENARIO("ISO15118-20 state transitions") {

    // Move to helper function?
    const auto evse_id = std::string("everest se");
    const std::vector<message_20::datatypes::ServiceCategory> supported_energy_services = {
        message_20::datatypes::ServiceCategory::DC};
    const auto cert_install{false};
    const std::vector<message_20::datatypes::Authorization> auth_services = {message_20::datatypes::Authorization::EIM};
    const d20::DcTransferLimits dc_limits;
    const std::vector<d20::ControlMobilityNeedsModes> control_mobility_modes = {
        {message_20::datatypes::ControlMode::Scheduled, message_20::datatypes::MobilityNeedsMode::ProvidedByEvcc}};

    const d20::EvseSetupConfig evse_setup{evse_id,   supported_energy_services, auth_services, cert_install,
                                          dc_limits, control_mobility_modes};

    auto state_helper = FsmStateHelper(d20::SessionConfig(evse_setup));
    auto ctx = state_helper.get_context();

    fsm::v2::FSM<d20::StateBase> fsm{ctx.create_state<d20::state::SupportedAppProtocol>()};

    message_20::SupportedAppProtocolRequest req;
    auto& ap = req.app_protocol.emplace_back();
    ap.priority = 0;
    ap.protocol_namespace = "Foobar";
    ap.schema_id = 12;
    ap.version_number_major = 2;
    ap.version_number_minor = 11;

    const auto [res, selected_protocol] = iso15118::d20::state::handle_request(req);
    REQUIRE(res.response_code ==
            iso15118::message_20::SupportedAppProtocolResponse::ResponseCode::Failed_NoNegotiation);
    REQUIRE(selected_protocol.has_value() == false);

    state_helper.handle_request(io::v2gtp::PayloadType::SAP, req);
    const auto result = fsm.feed(d20::Event::V2GTP_MESSAGE);

    REQUIRE(result.transitioned() == false);
    REQUIRE(fsm.get_current_state_id() == d20::StateID::SupportedAppProtocol);
}
