// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/authorization.hpp>

#include <string>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_AuthorizationReqType body;
};

template <> void convert(const V2gMessageRequest& in, AuthorizationReq& out) {
    convert(in.header, out.header);
    if (in.body.GenChallenge_isUsed) {
        out.gen_challenge = std::string(in.body.GenChallenge.bytes,
                                        in.body.GenChallenge.bytes +
                                            sizeof(in.body.GenChallenge.bytes) / sizeof(in.body.GenChallenge.bytes[0]));
    }
    out.id = in.body.Id.characters;
}

template <> void convert(const AuthorizationRes& in, iso2_AuthorizationResType& out) {
    init_iso2_AuthorizationResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
    cb_convert_enum(in.evse_processing, out.EVSEProcessing);
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_AuthorizationReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<AuthorizationReq>(v2g_message);
}

template <> int serialize_to_exi(const AuthorizationRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.AuthorizationRes);
    convert(in, doc.V2G_Message.Body.AuthorizationRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const AuthorizationRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
