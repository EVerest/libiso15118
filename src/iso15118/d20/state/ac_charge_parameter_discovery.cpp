// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/ac_charge_parameter_discovery.hpp>
#include <iso15118/d20/state/schedule_exchange.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/d20/state/ac_charge_parameter_discovery.hpp>
#include <iso15118/detail/d20/state/session_stop.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

namespace dt = message_20::datatypes;

using AC_ModeReq = dt::AC_CPDReqEnergyTransferMode;
using BPT_AC_ModeReq = dt::BPT_AC_CPDReqEnergyTransferMode;

using AC_ModeRes = dt::AC_CPDResEnergyTransferMode;
using BPT_AC_ModeRes = dt::BPT_AC_CPDResEnergyTransferMode;

message_20::AC_ChargeParameterDiscoveryResponse
handle_request(const message_20::AC_ChargeParameterDiscoveryRequest& req, const d20::Session& session,
               const d20::SessionConfig& config) {

    message_20::AC_ChargeParameterDiscoveryResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::datatypes::ResponseCode::FAILED_UnknownSession);
    }

    const auto selected_energy_service = session.get_selected_services().selected_energy_service;

    if (std::holds_alternative<AC_ModeReq>(req.transfer_mode)) {
        if (selected_energy_service != message_20::datatypes::ServiceCategory::AC) {
            return response_with_code(res, message_20::datatypes::ResponseCode::FAILED_WrongChargeParameter);
        }

        auto& mode = res.transfer_mode.emplace<AC_ModeRes>();
        
        // TODO(ioan): how to fix this missing params?
        // mode = config.ac_parameter_list;
        // convert(mode, dc_limits);

    } else if (std::holds_alternative<BPT_AC_ModeReq>(req.transfer_mode)) {
        if (selected_energy_service != message_20::datatypes::ServiceCategory::AC_BPT) {
            return response_with_code(res, message_20::datatypes::ResponseCode::FAILED_WrongChargeParameter);
        }
        
        // TODO(ioan): how to fix this missing params?
        // auto& mode = res.transfer_mode.emplace<BPT_AC_ModeRes>();
        // mode = config.evse_ac_bpt_parameter;

    } else {
        return response_with_code(res, message_20::datatypes::ResponseCode::FAILED_WrongChargeParameter);
    }

    return response_with_code(res, message_20::datatypes::ResponseCode::OK);
}

void AC_ChargeParameterDiscovery::enter() {
    m_ctx.log.enter_state("AC_ChargeParameterDiscovery");
}

Result AC_ChargeParameterDiscovery::feed(Event ev) {
    if (ev != Event::V2GTP_MESSAGE) {
        return {};
    }

    const auto variant = m_ctx.pull_request();

    if (const auto req = variant->get_if<message_20::AC_ChargeParameterDiscoveryRequest>()) {

        const auto res = handle_request(*req, m_ctx.session, m_ctx.session_config);

        m_ctx.respond(res);

        if (res.response_code >= message_20::datatypes::ResponseCode::FAILED) {
            m_ctx.session_stopped = true;
            return {};
        }

        return m_ctx.create_state<ScheduleExchange>();

    } else if (const auto req = variant->get_if<message_20::SessionStopRequest>()) {
        const auto res = handle_request(*req, m_ctx.session);

        m_ctx.respond(res);
        m_ctx.session_stopped = true;

        return {};
    } else {
        m_ctx.log("expected AC_ChargeParameterDiscovery! But code type id: %d", variant->get_type());
        m_ctx.session_stopped = true;

        // Sequence Error
        const message_20::Type req_type = variant->get_type();
        send_sequence_error(req_type, m_ctx);

        return {};
    }
}

} // namespace iso15118::d20::state
