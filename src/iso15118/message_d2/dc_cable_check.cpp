// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/dc_cable_check.hpp>

#include <string>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_CableCheckReqType body;
};

template <> void convert(const V2gMessageRequest& in, DC_CableCheckRequest& out) {
    convert(in.header, out.header);
    convert(in.body.DC_EVStatus, out.dc_ev_status);
}

template <> void convert(const DC_CableCheckResponse& in, iso2_CableCheckResType& out) {
    init_iso2_CableCheckResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
    convert(in.dc_evse_status, out.DC_EVSEStatus);
    cb_convert_enum(in.evse_processing, out.EVSEProcessing);
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_CableCheckReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<DC_CableCheckRequest>(v2g_message);
}

template <> int serialize_to_exi(const DC_CableCheckResponse& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.CableCheckRes);
    convert(in, doc.V2G_Message.Body.CableCheckRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const DC_CableCheckResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
