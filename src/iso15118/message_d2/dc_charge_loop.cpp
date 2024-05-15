// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/dc_charge_loop.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefDatatypes.h>
#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

// RDB - this seems very different in ISO2 vs ISO20.
// RDB TODO

template <> void convert(const struct iso2_CurrentDemandReqType& in, DC_ChargeLoopRequest& out) {
    // convert(in.Header, out.header);
}

template <> void insert_type(VariantAccess& va, const struct iso2_CurrentDemandReqType& in) {
    va.insert_type<DC_ChargeLoopRequest>(in);
}

template <> void convert(const DC_ChargeLoopResponse& in, struct iso2_CurrentDemandResType& out) {
    init_iso2_CurrentDemandResType(&out);

    // convert(in.header, out.Header);
    cb_convert_enum(in.response_code, out.ResponseCode);
    // cb_convert_enum(in.processing, out.EVSEProcessing);

    // RDB Also send send the DC_EVStatus
    out.DC_EVSEStatus.NotificationMaxDelay = 0;
    out.DC_EVSEStatus.EVSENotification = iso2_EVSENotificationType_None;
    out.DC_EVSEStatus.EVSEStatusCode = iso2_DC_EVSEStatusCodeType_EVSE_Ready;
    // RDB TODO - isolation status needs to reflect the IMD state.
    out.DC_EVSEStatus.EVSEIsolationStatus = iso2_isolationLevelType_Valid;
    out.DC_EVSEStatus.EVSEIsolationStatus_isUsed = true;

    // RDB Hand craft a reply for now.
    // RDB TODO do this properly
    // convert(in.present_current, out.EVSEPresentCurrent);
    convert(from_float(20.0), out.EVSEPresentCurrent);
    out.EVSEPresentCurrent.Unit = iso2_unitSymbolType_A;
    // convert(in.present_voltage, out.EVSEPresentVoltage);
    convert(from_float(400.0), out.EVSEPresentVoltage);
    out.EVSEPresentVoltage.Unit = iso2_unitSymbolType_V;

    out.EVSEPowerLimitAchieved = true;   // in.power_limit_achieved;
    out.EVSECurrentLimitAchieved = true; // in.current_limit_achieved;
    out.EVSEVoltageLimitAchieved = true; // in.voltage_limit_achieved;
    out.SAScheduleTupleID = 1;
    CPP2CB_STRING(std::string("+49*DEF*E123ABC"), out.EVSEID);
}

template <> int serialize_to_exi(const DC_ChargeLoopResponse& in, exi_bitstream_t& out) {
    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    // RDB this is new in ISO2
    init_iso2_BodyType(&doc.V2G_Message.Body);

    // RDB Convert the header since it is separate in ISO2.
    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.CurrentDemandRes);

    convert(in, doc.V2G_Message.Body.CurrentDemandRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const DC_ChargeLoopResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
