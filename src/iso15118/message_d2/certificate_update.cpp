// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/certificate_update.hpp>

#include <string>

#include <iso15118/detail/variant_access.hpp>

#include <algorithm>
#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_CertificateUpdateReqType body;
};

template <> void convert(const V2gMessageRequest& in, CertificateUpdateReq& out) {
    convert(in.header, out.header);
    convert(in.body.ContractSignatureCertChain, out.contract_signature_cert_chain);
    out.emaid = in.body.eMAID.characters;
    convert(in.body.ListOfRootCertificateIDs, out.list_of_root_certificate_ids);
    out.id = in.body.Id.characters;
}

template <> void convert(const CertificateUpdateRes& in, iso2_CertificateUpdateResType& out) {
    init_iso2_CertificateUpdateResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
    convert(in.sa_provisioning_certificate_chain, out.SAProvisioningCertificateChain);
    convert(in.contract_signature_cert_chain, out.ContractSignatureCertChain);
    convert(in.contract_signature_encrypted_private_key, out.ContractSignatureEncryptedPrivateKey);
    convert(in.dh_publickey, out.DHpublickey);

    const size_t MAX_EMAID_SIZE = iso2_CONTENT_CHARACTER_SIZE;
    size_t copyLength = std::min(in.emaid.size(), MAX_EMAID_SIZE - 1); // Leave space for null terminator
    std::copy_n(in.emaid.begin(), copyLength, out.eMAID.CONTENT.characters);
    out.eMAID.CONTENT.characters[copyLength] = '\0'; // Ensure null termination

    if (in.retry_counter) {
        out.RetryCounter = *in.retry_counter;
        CB_SET_USED(out.RetryCounter);
    }
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_CertificateUpdateReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<CertificateUpdateReq>(v2g_message);
}

template <> int serialize_to_exi(const CertificateUpdateRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.CertificateUpdateRes);
    convert(in, doc.V2G_Message.Body.CertificateUpdateRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const CertificateUpdateRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
