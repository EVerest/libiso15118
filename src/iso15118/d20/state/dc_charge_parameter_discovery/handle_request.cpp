// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/detail/d20/state/dc_charge_parameter_discovery.hpp>

#include <iso15118/detail/d20/context_helper.hpp>

namespace iso15118::d20::state {

using DC_ModeReq = message_20::DC_ChargeParameterDiscoveryRequest::DC_CPDReqEnergyTransferMode;
using BPT_DC_ModeReq = message_20::DC_ChargeParameterDiscoveryRequest::BPT_DC_CPDReqEnergyTransferMode;

using DC_ModeRes = message_20::DC_ChargeParameterDiscoveryResponse::DC_CPDResEnergyTransferMode;
using BPT_DC_ModeRes = message_20::DC_ChargeParameterDiscoveryResponse::BPT_DC_CPDResEnergyTransferMode;

message_20::DC_ChargeParameterDiscoveryResponse
handle_request(const message_20::DC_ChargeParameterDiscoveryRequest& req, const d20::Session& session,
               const d20::Config& config) {

    message_20::DC_ChargeParameterDiscoveryResponse res;

    if (validate_and_setup_header(res.header, session, req.header.session_id) == false) {
        return response_with_code(res, message_20::ResponseCode::FAILED_UnknownSession);
    }

    if (std::holds_alternative<DC_ModeReq>(req.transfer_mode)) {
        if (session.selected_energy_service != message_20::ServiceCategory::DC) {
            return response_with_code(res, message_20::ResponseCode::FAILED_WrongChargeParameter);
        }

        auto& mode = res.transfer_mode.emplace<DC_ModeRes>();
        mode = config.evse_dc_parameter;

    } else if (std::holds_alternative<BPT_DC_ModeReq>(req.transfer_mode)) {
        if (session.selected_energy_service != message_20::ServiceCategory::DC_BPT) {
            return response_with_code(res, message_20::ResponseCode::FAILED_WrongChargeParameter);
        }

        auto& mode = res.transfer_mode.emplace<BPT_DC_ModeRes>();
        mode = config.evse_dc_bpt_parameter;

    } else {
        // Not supported transfer_mode
        return response_with_code(res, message_20::ResponseCode::FAILED_WrongChargeParameter);
    }

    return response_with_code(res, message_20::ResponseCode::OK);
}

} // namespace iso15118::d20::state
