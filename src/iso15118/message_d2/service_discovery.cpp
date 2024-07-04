// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/service_discovery.hpp>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefDatatypes.h>
#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

// Todo: structure for ServiceDiscoveryReq
struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_ServiceDiscoveryReqType body;
};

template <> void convert(const V2gMessageRequest& in, ServiceDiscoveryReq& out) {
    convert(in.header, out.header);
    if (in.body.ServiceScope_isUsed) {
        out.service_scope = in.body.ServiceScope.characters;
    }
    if (in.body.ServiceCategory_isUsed) {
        out.service_category =
            static_cast<iso15118::message_d2::data_types::service_category_type>(in.body.ServiceCategory);
    }
}

template <> void convert(const ServiceDiscoveryRes& in, iso2_ServiceDiscoveryResType& out) {
    init_iso2_ServiceDiscoveryResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
    convert(in.payment_option_list, out.PaymentOptionList);
    convert(in.charge_service, out.ChargeService);
    if (in.service_list) {
        convert(*in.service_list, out.ServiceList);
        CB_SET_USED(out.ServiceList);
    }
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_ServiceDiscoveryReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<ServiceDiscoveryReq>(v2g_message);
}

template <> int serialize_to_exi(const ServiceDiscoveryRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.ServiceDiscoveryRes);
    convert(in, doc.V2G_Message.Body.ServiceDiscoveryRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const ServiceDiscoveryRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
