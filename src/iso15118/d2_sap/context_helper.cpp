// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <ctime>

#include <iso15118/detail/d2_sap/context_helper.hpp>
#include <iso15118/detail/helper.hpp>

//#include <iso15118/message_d2_sap/authorization.hpp>
//#include <iso15118/message_d2_sap/dc_charge_parameter_discovery.hpp>

namespace iso15118::d2_sap {

static inline void setup_timestamp(message_2_sap::Header& header) {
    header.timestamp = static_cast<uint64_t>(std::time(nullptr));
}

bool validate_and_setup_header(message_2_sap::Header& header, const Session& cur_session,
                               const decltype(message_2_sap::Header::session_id)& req_session_id) {

    setup_header(header, cur_session);

    return (cur_session.get_id() == req_session_id);
}

void setup_header(message_2_sap::Header& header, const Session& cur_session) {
    header.session_id = cur_session.get_id();
    setup_timestamp(header);
}

template <typename Response> Response handle_sequence_error(const d2_sap::Session& session) {
    Response res;
    setup_header(res.header, session);
    return response_with_code(res, message_2_sap::ResponseCode::FAILED_SequenceError);
}

// Todo(sl): Not happy at all. Need refactoring. Only ctx.respond and Session is needed. Not the whole Context.
void send_sequence_error(const message_2_sap::Type req_type, d2_sap::Context& ctx) {

    // if (req_type == message_2_sap::Type::SessionSetupReq) {
    //     const auto res = handle_sequence_error<message_2_sap::SessionSetupResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::AuthorizationSetupReq) {
    //     const auto res = handle_sequence_error<message_2_sap::AuthorizationSetupResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::AuthorizationReq) {
    //     const auto res = handle_sequence_error<message_2_sap::AuthorizationResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::ServiceDiscoveryReq) {
    //     const auto res = handle_sequence_error<message_2_sap::ServiceDiscoveryResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::ServiceDetailReq) {
    //     const auto res = handle_sequence_error<message_2_sap::ServiceDetailResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::ServiceSelectionReq) {
    //     const auto res = handle_sequence_error<message_2_sap::ServiceSelectionResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::DC_ChargeParameterDiscoveryReq) {
    //     const auto res = handle_sequence_error<message_2_sap::DC_ChargeParameterDiscoveryResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::ScheduleExchangeReq) {
    //     const auto res = handle_sequence_error<message_2_sap::ScheduleExchangeResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::DC_CableCheckReq) {
    //     const auto res = handle_sequence_error<message_2_sap::DC_CableCheckResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::PowerDeliveryReq) {
    //     const auto res = handle_sequence_error<message_2_sap::PowerDeliveryResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::DC_PreChargeReq) {
    //     const auto res = handle_sequence_error<message_2_sap::DC_PreChargeResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::DC_ChargeLoopReq) {
    //     const auto res = handle_sequence_error<message_2_sap::DC_ChargeLoopResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::DC_WeldingDetectionReq) {
    //     const auto res = handle_sequence_error<message_2_sap::DC_WeldingDetectionResponse>(ctx.session);
    //     ctx.respond(res);
    // } else if (req_type == message_2_sap::Type::SessionStopReq) {
    //     const auto res = handle_sequence_error<message_2_sap::SessionStopResponse>(ctx.session);
    //     ctx.respond(res);
    // } else {
    //     logf("Unknown code type id: %d ", req_type);
    // }
}

} // namespace iso15118::d2_sap
