// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message/common.hpp>

#include <iso15118/detail/cb_exi.hpp>
#include <iso15118/message/variant.hpp>

#include <exi/cb/iso20_CommonMessages_Datatypes.h>
#include <exi/cb/iso20_DC_Datatypes.h>

namespace iso15118::message_20 {

template <typename cb_HeaderType> void convert(const cb_HeaderType& in, Header& out) {

    std::copy(in.SessionID.bytes, in.SessionID.bytes + in.SessionID.bytesLen, out.session_id.begin());
    out.timestamp = in.TimeStamp;

    // Todo(sl): missing signature
}

template void convert(const struct iso20_MessageHeaderType& in, Header& out);
template void convert(const struct iso20_dc_MessageHeaderType& in, Header& out);

template <typename cb_HeaderType> void convert_header(const Header& in, cb_HeaderType& out) {
    out.TimeStamp = in.timestamp;
    std::copy(in.session_id.begin(), in.session_id.end(), out.SessionID.bytes);

    // FIXME (aw): this should be fixed 8
    out.SessionID.bytesLen = 8;
}

template <> void convert(const Header& in, iso20_MessageHeaderType& out) {
    init_iso20_MessageHeaderType(&out);
    convert_header(in, out);
}

template <> void convert(const Header& in, iso20_dc_MessageHeaderType& out) {
    init_iso20_dc_MessageHeaderType(&out);
    convert_header(in, out);
}

template <typename cb_RationalNumberType> void convert(const cb_RationalNumberType& in, RationalNumber& out) {
    out.exponent = in.Exponent;
    out.value = in.Value;
}

template void convert(const struct iso20_dc_RationalNumberType& in, RationalNumber& out);
template void convert(const struct iso20_RationalNumberType& in, RationalNumber& out);

template <typename cb_RationalNumberType> void convert(const RationalNumber& in, cb_RationalNumberType& out) {
    out.Exponent = in.exponent;
    out.Value = in.value;
}

template void convert(const RationalNumber& in, struct iso20_dc_RationalNumberType& out);
template void convert(const RationalNumber& in, struct iso20_RationalNumberType& out);

template <> void convert(const EvseStatus& in, struct iso20_dc_EVSEStatusType& out) {
    out.NotificationMaxDelay = in.notification_max_delay;
    cb_convert_enum(in.notification, out.EVSENotification);
}

template <typename cb_MeterInfoType> void convert_meterinfo(const MeterInfo& in, cb_MeterInfoType& out) {

    CPP2CB_STRING(in.meter_id, out.MeterID);
    out.ChargedEnergyReadingWh = in.charged_energy_reading_wh;

    CPP2CB_ASSIGN_IF_USED(in.bpt_discharged_energy_reading_wh, out.BPT_DischargedEnergyReadingWh);
    CPP2CB_ASSIGN_IF_USED(in.capacitive_energy_reading_varh, out.CapacitiveEnergyReadingVARh);
    CPP2CB_ASSIGN_IF_USED(in.bpt_inductive_energery_reading_varh, out.BPT_InductiveEnergyReadingVARh);

    if (in.meter_signature) {
        CPP2CB_BYTES(in.meter_signature.value(), out.MeterSignature);
        CB_SET_USED(out.MeterSignature);
    }

    CPP2CB_ASSIGN_IF_USED(in.meter_status, out.MeterStatus);
    CPP2CB_ASSIGN_IF_USED(in.meter_timestamp, out.MeterTimestamp);
}

template <> void convert(const MeterInfo& in, iso20_dc_MeterInfoType& out) {
    init_iso20_dc_MeterInfoType(&out);
    convert_meterinfo(in, out);
}

template <> void convert(const EvseStatus& in, iso20_EVSEStatusType& out) {
    out.NotificationMaxDelay = in.notification_max_delay;
    cb_convert_enum(in.notification, out.EVSENotification);
}

} // namespace iso15118::message_20