// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/service_detail.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_ServiceDetailReqType body;
};

template <> void convert(const V2gMessageRequest& in, ServiceDetailReq& out) {
    convert(in.header, out.header);
    out.service_id = in.body.ServiceID;
}

template <> void convert(const ServiceDetailRes& in, iso2_ServiceDetailResType& out) {
    init_iso2_ServiceDetailResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
    out.ServiceID = in.service_id;
    if (in.service_parameter_list) {
        convert(*in.service_parameter_list, out.ServiceParameterList);
        CB_SET_USED(out.ServiceParameterList);
    }
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_ServiceDetailReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<ServiceDetailReq>(v2g_message);
}

template <> int serialize_to_exi(const ServiceDetailRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.ServiceDetailRes);
    convert(in, doc.V2G_Message.Body.ServiceDetailRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const ServiceDetailRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
