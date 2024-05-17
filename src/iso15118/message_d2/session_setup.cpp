// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/session_setup.hpp>

#include <string>
#include <type_traits>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

// Todo(sl): Not happy with this
struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_SessionSetupReqType body;
};

template <> void convert(const V2gMessageRequest& in, SessionSetupRequest& out) {
    convert(in.header, out.header);

    std::copy(in.body.EVCCID.bytes, in.body.EVCCID.bytes + in.body.EVCCID.bytesLen, out.evccid.begin());
};

template <> void convert(const SessionSetupResponse& in, iso2_SessionSetupResType& out) {
    init_iso2_SessionSetupResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);

    CPP2CB_STRING(in.evseid, out.EVSEID);

    CPP2CB_ASSIGN_IF_USED(in.timestamp, out.EVSETimeStamp);
};

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_SessionSetupReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<SessionSetupRequest>(v2g_message);
}

template <> int serialize_to_exi(const SessionSetupResponse& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.SessionSetupRes);
    convert(in, doc.V2G_Message.Body.SessionSetupRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const SessionSetupResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2