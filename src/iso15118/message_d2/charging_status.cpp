// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/charging_status.hpp>

#include <string>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefEncoder.h>
#include <cstring>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_ChargingStatusReqType body;
};

template <> void convert(const V2gMessageRequest& in, ChargingStatusReq& out) {
    convert(in.header, out.header);
}

template <> void convert(const ChargingStatusRes& in, iso2_ChargingStatusResType& out) {
    init_iso2_ChargingStatusResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);

    const size_t MAX_SIZE = iso2_EVSEID_CHARACTER_SIZE;
    size_t copyLength = std::min(in.evse_id.size(), MAX_SIZE - 1); // Leave space for null terminator
    strncpy(out.EVSEID.characters, in.evse_id.c_str(), copyLength);
    out.EVSEID.characters[copyLength] = '\0'; // Ensure null termination

    out.SAScheduleTupleID = in.sa_schedule_tuple_id;
    if (in.evse_max_current) {
        convert(*in.evse_max_current, out.EVSEMaxCurrent);
        CB_SET_USED(out.EVSEMaxCurrent);
    }
    if (in.meter_info) {
        convert(*in.meter_info, out.MeterInfo);
        CB_SET_USED(out.MeterInfo);
    }
    if (in.receipt_required) {
        out.ReceiptRequired = *in.receipt_required;
        CB_SET_USED(out.ReceiptRequired);
    }
    convert(in.ac_evse_status, out.AC_EVSEStatus);
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_ChargingStatusReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<ChargingStatusReq>(v2g_message);
}

template <> int serialize_to_exi(const ChargingStatusRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.ChargingStatusRes);
    convert(in, doc.V2G_Message.Body.ChargingStatusRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const ChargingStatusRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
