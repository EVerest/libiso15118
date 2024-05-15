// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/session_stop.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefDatatypes.h>
#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

template <> void convert(const struct iso2_SessionStopReqType& in, SessionStopRequest& out) {
    // convert(in.Header, out.header);

    cb_convert_enum(in.ChargingSession, out.charging_session);
    // if (in.EVTerminationCode_isUsed) {
    //     out.ev_termination_code = CB2CPP_STRING(in.EVTerminationCode);
    // }
    // if (in.EVTerminationExplanation_isUsed) {
    //     out.ev_termination_explanation = CB2CPP_STRING(in.EVTerminationExplanation);
    // }
}

template <> void insert_type(VariantAccess& va, const struct iso2_SessionStopReqType& in) {
    va.insert_type<SessionStopRequest>(in);
}

template <> void convert(const SessionStopResponse& in, struct iso2_SessionStopResType& out) {
    init_iso2_SessionStopResType(&out);
    // convert(in.header, out.Header);
    cb_convert_enum(in.response_code, out.ResponseCode);
}

template <> int serialize_to_exi(const SessionStopResponse& in, exi_bitstream_t& out) {
    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    // RDB this is new in ISO2
    init_iso2_BodyType(&doc.V2G_Message.Body);

    // RDB Convert the header since it is separate in ISO2.
    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.SessionStopRes);

    convert(in, doc.V2G_Message.Body.SessionStopRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const SessionStopResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2