// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/dc_welding_detection.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefDatatypes.h>
#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

template <> void convert(const struct iso2_WeldingDetectionReqType& in, DC_WeldingDetectionRequest& out) {
    // convert(in.Header, out.header);

    // cb_convert_enum(in.EVProcessing, out.processing);
}

template <> void insert_type(VariantAccess& va, const struct iso2_WeldingDetectionReqType& in) {
    va.insert_type<DC_WeldingDetectionRequest>(in);
}

template <> void convert(const DC_WeldingDetectionResponse& in, struct iso2_WeldingDetectionResType& out) {
    init_iso2_WeldingDetectionResType(&out);
    // convert(in.header, out.Header);

    cb_convert_enum(in.response_code, out.ResponseCode);

    convert(in.present_voltage, out.EVSEPresentVoltage);
    out.EVSEPresentVoltage.Unit = iso2_unitSymbolType_V;

    // RDB Also send send the DC_EVStatus
    out.DC_EVSEStatus.NotificationMaxDelay = 0;
    out.DC_EVSEStatus.EVSENotification = iso2_EVSENotificationType_None;
    out.DC_EVSEStatus.EVSEStatusCode = iso2_DC_EVSEStatusCodeType_EVSE_Ready;
    // RDB TODO - isolation status needs to reflect the IMD state.
    out.DC_EVSEStatus.EVSEIsolationStatus = iso2_isolationLevelType_Valid;
    out.DC_EVSEStatus.EVSEIsolationStatus_isUsed = true;
}

template <> int serialize_to_exi(const DC_WeldingDetectionResponse& in, exi_bitstream_t& out) {
    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    // RDB this is new in ISO2
    init_iso2_BodyType(&doc.V2G_Message.Body);

    // RDB Convert the header since it is separate in ISO2.
    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.WeldingDetectionRes);

    convert(in, doc.V2G_Message.Body.WeldingDetectionRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const DC_WeldingDetectionResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2