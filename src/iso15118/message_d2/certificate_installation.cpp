// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/certificate_installation.hpp>

#include <string>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefEncoder.h>
#include <cstring>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_CertificateInstallationReqType body;
};

template <> void convert(const V2gMessageRequest& in, CertificateInstallationReq& out) {
    convert(in.header, out.header);
    out.oem_provisioning_cert = std::string(reinterpret_cast<const char*>(in.body.OEMProvisioningCert.bytes));
    convert(in.body.ListOfRootCertificateIDs, out.list_of_root_certificate_ids);
    out.id = in.body.Id.characters;
}

template <> void convert(const CertificateInstallationRes& in, iso2_CertificateInstallationResType& out) {
    init_iso2_CertificateInstallationResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
    convert(in.sa_provisioning_certificate_chain, out.SAProvisioningCertificateChain);
    convert(in.contract_signature_cert_chain, out.ContractSignatureCertChain);
    convert(in.contract_signature_encrypted_private_key, out.ContractSignatureEncryptedPrivateKey);
    convert(in.dh_publickey, out.DHpublickey);

    const size_t MAX_SIZE = iso2_CONTENT_CHARACTER_SIZE;
    size_t copyLength = std::min(in.emaid.size(), MAX_SIZE - 1); // Leave space for null terminator
    strncpy(out.eMAID.CONTENT.characters, in.emaid.c_str(), copyLength);
    out.eMAID.CONTENT.characters[copyLength] = '\0'; // Ensure null termination
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_CertificateInstallationReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<CertificateInstallationReq>(v2g_message);
}

template <> int serialize_to_exi(const CertificateInstallationRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.CertificateInstallationRes);
    convert(in, doc.V2G_Message.Body.CertificateInstallationRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const CertificateInstallationRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
