// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/dc_pre_charge.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefDatatypes.h>
#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

template <> void convert(const struct iso2_PreChargeReqType& in, DC_PreChargeRequest& out) {
    // convert(in.Header, out.header);

    // RDB TODO this is probably not correct.
    // cb_convert_enum(in.EVProcessing, out.processing);
    convert(in.EVTargetVoltage, out.present_voltage);
    // convert(in.EVTargetCurrent, out.);
}

template <> void insert_type(VariantAccess& va, const struct iso2_PreChargeReqType& in) {
    va.insert_type<DC_PreChargeRequest>(in);
}

template <> void convert(const DC_PreChargeResponse& in, struct iso2_PreChargeResType& out) {
    init_iso2_PreChargeResType(&out);
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

template <> int serialize_to_exi(const DC_PreChargeResponse& in, exi_bitstream_t& out) {
    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    // RDB this is new in ISO2
    init_iso2_BodyType(&doc.V2G_Message.Body);

    // RDB Convert the header since it is separate in ISO2.
    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.PreChargeRes);

    convert(in, doc.V2G_Message.Body.PreChargeRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const DC_PreChargeResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
