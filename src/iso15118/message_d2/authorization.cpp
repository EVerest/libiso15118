// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/authorization.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access_d2.hpp>

#include <exi/cb/iso2_msgDefDatatypes.h>
#include <exi/cb/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

template <> void convert(const struct iso2_AuthorizationReqType& in, AuthorizationRequest& out) {
    // RDB header is different in iso2
    //convert(in.Header, out.header);

    //RDB ISO2 Id and Genchallenge are optional
    //RDB TODO allow id and genchallenge

    // out.selected_authorization_service = static_cast<Authorization>(in.SelectedAuthorizationService);
    // if (in.EIM_AReqAuthorizationMode_isUsed) {
    //     out.eim_as_req_authorization_mode.emplace();
    // } else if (in.PnC_AReqAuthorizationMode_isUsed) {

    //     auto& pnc_out = out.pnc_as_req_authorization_mode.emplace();

    //     pnc_out.id = CB2CPP_STRING(in.PnC_AReqAuthorizationMode.Id);
    //     pnc_out.gen_challenge.reserve(in.PnC_AReqAuthorizationMode.GenChallenge.bytesLen);
    //     pnc_out.gen_challenge.insert(
    //         pnc_out.gen_challenge.end(), &in.PnC_AReqAuthorizationMode.GenChallenge.bytes[0],
    //         &in.PnC_AReqAuthorizationMode.GenChallenge.bytes[in.PnC_AReqAuthorizationMode.GenChallenge.bytesLen]);
    //     // Todo(sl): Adding certificate
    // }
}

template <> void convert(const AuthorizationResponse& in, iso2_AuthorizationResType& out) {
    init_iso2_AuthorizationResType(&out);

    out.ResponseCode = static_cast<iso2_responseCodeType>(in.response_code);
    out.EVSEProcessing = static_cast<iso2_EVSEProcessingType>(in.evse_processing);

    //RDB - ISO2 separates the header and the body, so we don't convert the header here, do it in the serialize_to_exi instead.
    //convert(in.header, out.Header);
}

template <> void insert_type(VariantAccess& va, const struct iso2_AuthorizationReqType& in) {
    va.insert_type<AuthorizationRequest>(in);
};

template <> int serialize_to_exi(const AuthorizationResponse& in, exi_bitstream_t& out) {
    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    //RDB this is new in ISO2
    init_iso2_BodyType(&doc.V2G_Message.Body);

    //RDB Convert the header since it is separate in ISO2.
    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.AuthorizationRes);

    convert(in, doc.V2G_Message.Body.AuthorizationRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const AuthorizationResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
