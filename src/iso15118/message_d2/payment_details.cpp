// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/payment_details.hpp>

#include <string>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_PaymentDetailsReqType body;
};

template <> void convert(const V2gMessageRequest& in, PaymentDetailsReq& out) {
    convert(in.header, out.header);
    out.emaid = std::string(in.body.eMAID.characters);
    convert(in.body.ContractSignatureCertChain, out.contract_signature_cert_chain);
}

template <> void convert(const PaymentDetailsRes& in, iso2_PaymentDetailsResType& out) {
    init_iso2_PaymentDetailsResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
    std::copy(in.gen_challenge.begin(), in.gen_challenge.end(), out.GenChallenge.bytes);
    out.GenChallenge.bytes[in.gen_challenge.size()] = '\0'; // Ensure null termination
    out.EVSETimeStamp = in.evse_time_stamp;
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_PaymentDetailsReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<PaymentDetailsReq>(v2g_message);
}

template <> int serialize_to_exi(const PaymentDetailsRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.PaymentDetailsRes);
    convert(in, doc.V2G_Message.Body.PaymentDetailsRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const PaymentDetailsRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2