// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/metering_receipt.hpp>

#include <string>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_MeteringReceiptReqType body;
};

template <> void convert(const V2gMessageRequest& in, MeteringReceiptReq& out) {
    convert(in.header, out.header);
    out.session_id = std::string(reinterpret_cast<const char*>(in.body.SessionID.bytes));
    if (in.body.SAScheduleTupleID_isUsed) {
        out.sa_schedule_tuple_id = in.body.SAScheduleTupleID;
    }
    convert(in.body.MeterInfo, out.meter_info);
    out.id = in.body.Id.characters;
}

template <> void convert(const MeteringReceiptRes& in, iso2_MeteringReceiptResType& out) {
    init_iso2_MeteringReceiptResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
    convert(in.evse_status, out.EVSEStatus);
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_MeteringReceiptReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<MeteringReceiptReq>(v2g_message);
}

template <> int serialize_to_exi(const MeteringReceiptRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.MeteringReceiptRes);
    convert(in, doc.V2G_Message.Body.MeteringReceiptRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const MeteringReceiptRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
