// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/session_stop.hpp>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_SessionStopReqType body;
};

template <> void convert(const V2gMessageRequest& in, SessionStopReq& out) {
    convert(in.header, out.header);
    out.charging_session = static_cast<ChargingSession>(in.body.ChargingSession);
}

template <> void convert(const SessionStopRes& in, iso2_SessionStopResType& out) {
    init_iso2_SessionStopResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_SessionStopReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<SessionStopReq>(v2g_message);
}

template <> int serialize_to_exi(const SessionStopRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.SessionStopRes);
    convert(in, doc.V2G_Message.Body.SessionStopRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const SessionStopRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
