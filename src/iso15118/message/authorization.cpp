// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message/authorization.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_20/iso20_CommonMessages_Encoder.h>

namespace iso15118::message_20 {

// FIXME (aw): this template should be commonly reused
template <typename T, typename SourceType> void copy_bytes_to_vector(std::vector<T>& out, const SourceType& in) {
    static_assert(std::is_same_v<T, std::remove_all_extents_t<decltype(in.bytes)>>);
    out.reserve(in.bytesLen);
    std::copy(in.bytes, in.bytes + in.bytesLen, std::back_inserter(out));
}

template <>
void convert(const struct iso20_PnC_AReqAuthorizationModeType& in,
             AuthorizationRequest::PnC_ASReqAuthorizationMode& out) {
    out.id = CB2CPP_STRING(in.Id);

    copy_bytes_to_vector(out.gen_challenge, in.GenChallenge);
    copy_bytes_to_vector(out.contract_certificate_chain.certificate, in.ContractCertificateChain.Certificate);

    for (std::size_t i = 0; i < in.ContractCertificateChain.SubCertificates.Certificate.arrayLen; ++i) {
        const auto& sub_certificate_in = in.ContractCertificateChain.SubCertificates.Certificate.array[i];
        auto& sub_certificate_out = out.contract_certificate_chain.sub_certificates.emplace_back();
        copy_bytes_to_vector(sub_certificate_out, sub_certificate_in);
    }
}

template <> void convert(const struct iso20_AuthorizationReqType& in, AuthorizationRequest& out) {
    convert(in.Header, out.header);

    out.selected_authorization_service = static_cast<Authorization>(in.SelectedAuthorizationService);
    if (in.EIM_AReqAuthorizationMode_isUsed) {
        out.authorization_mode = AuthorizationRequest::EIM_ASReqAuthorizationMode{};
    } else if (in.PnC_AReqAuthorizationMode_isUsed) {
        auto& pnc_out = out.authorization_mode.emplace<AuthorizationRequest::PnC_ASReqAuthorizationMode>();
        convert(in.PnC_AReqAuthorizationMode, pnc_out);
    }
}

template <> void convert(const AuthorizationResponse& in, iso20_AuthorizationResType& out) {
    init_iso20_AuthorizationResType(&out);

    out.ResponseCode = static_cast<iso20_responseCodeType>(in.response_code);
    out.EVSEProcessing = static_cast<iso20_processingType>(in.evse_processing);

    convert(in.header, out.Header);
}

template <> void insert_type(VariantAccess& va, const struct iso20_AuthorizationReqType& in) {
    va.insert_type<AuthorizationRequest>(in);
};

template <> int serialize_to_exi(const AuthorizationResponse& in, exi_bitstream_t& out) {
    iso20_exiDocument doc;
    init_iso20_exiDocument(&doc);

    CB_SET_USED(doc.AuthorizationRes);

    convert(in, doc.AuthorizationRes);

    return encode_iso20_exiDocument(&out, &doc);
}

template <> size_t serialize(const AuthorizationResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_20
