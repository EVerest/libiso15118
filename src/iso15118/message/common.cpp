// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <cmath>

#include <iso15118/message/common.hpp>

#include <iso15118/detail/cb_exi.hpp>
#include <iso15118/message/variant.hpp>

#include <cbv2g/iso_20/iso20_AC_Datatypes.h>
#include <cbv2g/iso_20/iso20_CommonMessages_Datatypes.h>
#include <cbv2g/iso_20/iso20_DC_Datatypes.h>

namespace iso15118::message_20 {

template <typename cb_HeaderType> void convert(const cb_HeaderType& in, Header& out) {

    std::copy(in.SessionID.bytes, in.SessionID.bytes + in.SessionID.bytesLen, out.session_id.begin());
    out.timestamp = in.TimeStamp;

    // Todo(sl): missing signature
}

template void convert(const struct iso20_MessageHeaderType& in, Header& out);
template void convert(const struct iso20_dc_MessageHeaderType& in, Header& out);
template void convert(const struct iso20_ac_MessageHeaderType& in, Header& out);

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

template <> void convert(const Header& in, iso20_ac_MessageHeaderType& out) {
    init_iso20_ac_MessageHeaderType(&out);
    convert_header(in, out);
}

template <typename cb_RationalNumberType> void convert(const cb_RationalNumberType& in, RationalNumber& out) {
    out.exponent = in.Exponent;
    out.value = in.Value;
}

template void convert(const struct iso20_ac_RationalNumberType& in, RationalNumber& out);
template void convert(const struct iso20_dc_RationalNumberType& in, RationalNumber& out);
template void convert(const struct iso20_RationalNumberType& in, RationalNumber& out);

template <typename cb_RationalNumberType> void convert(const RationalNumber& in, cb_RationalNumberType& out) {
    out.Exponent = in.exponent;
    out.Value = in.value;
}

template void convert(const RationalNumber& in, struct iso20_ac_RationalNumberType& out);
template void convert(const RationalNumber& in, struct iso20_dc_RationalNumberType& out);
template void convert(const RationalNumber& in, struct iso20_RationalNumberType& out);

template <> void convert(const EvseStatus& in, struct iso20_dc_EVSEStatusType& out) {
    out.NotificationMaxDelay = in.notification_max_delay;
    cb_convert_enum(in.notification, out.EVSENotification);
}

template <> void convert(const EvseStatus& in, struct iso20_ac_EVSEStatusType& out) {
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

template <> void convert(const MeterInfo& in, iso20_ac_MeterInfoType& out) {
    init_iso20_ac_MeterInfoType(&out);
    convert_meterinfo(in, out);
}

template <> void convert(const EvseStatus& in, iso20_EVSEStatusType& out) {
    out.NotificationMaxDelay = in.notification_max_delay;
    cb_convert_enum(in.notification, out.EVSENotification);
}

float from_RationalNumber(const RationalNumber& in) {
    return in.value * pow(10, in.exponent);
}

RationalNumber from_float(float in) {
    RationalNumber out;
    if (in == 0.0) {
        out.exponent = 0;
        out.value = 0;
        return out;
    }
    out.exponent = static_cast<int8_t>(floor(log10(fabs(in))));
    out.exponent -= 3; // add 3 digits of precision
    out.value = static_cast<int16_t>(in * pow(10, -out.exponent));
    return out;
}

std::string from_Protocol(const Protocol& in) {

    switch (in) {
    case Protocol::Ftp:
        return std::string("ftp");
    case Protocol::Http:
        return std::string("http");
    case Protocol::Https:
        return std::string("https");
    }
    return "";
}

ParameterSet::ParameterSet(uint16_t _id) : id(_id) {
    parameters.push_back({"", false});
}

ParameterSet::ParameterSet(uint16_t _id, const AcParameterList& list) : id(_id) {
    parameters.push_back({"Connector", static_cast<int32_t>(list.connector)});
    parameters.push_back({"ControlMode", static_cast<int32_t>(list.control_mode)});
    parameters.push_back({"EVSENominalVoltage", static_cast<int32_t>(list.evse_nominal_voltage)});
    if (list.control_mode == message_20::ControlMode::Scheduled) {
        parameters.push_back(
            {"MobilityNeedsMode", static_cast<int32_t>(message_20::MobilityNeedsMode::ProvidedByEvcc)});
    } else {
        parameters.push_back({"MobilityNeedsMode", static_cast<int32_t>(list.mobility_needs_mode)});
    }
    parameters.push_back({"Pricing", static_cast<int32_t>(list.pricing)});
}

ParameterSet::ParameterSet(uint16_t _id, const AcBptParameterList& list) : id(_id) {
    parameters.push_back({"Connector", static_cast<int32_t>(list.connector)});
    parameters.push_back({"ControlMode", static_cast<int32_t>(list.control_mode)});
    parameters.push_back({"EVSENominalVoltage", static_cast<int32_t>(list.evse_nominal_voltage)});
    if (list.control_mode == message_20::ControlMode::Scheduled) {
        parameters.push_back(
            {"MobilityNeedsMode", static_cast<int32_t>(message_20::MobilityNeedsMode::ProvidedByEvcc)});
    } else {
        parameters.push_back({"MobilityNeedsMode", static_cast<int32_t>(list.mobility_needs_mode)});
    }
    parameters.push_back({"Pricing", static_cast<int32_t>(list.pricing)});
    parameters.push_back({"BPTChannel", static_cast<int32_t>(list.bpt_channel)});
    parameters.push_back({"GeneratorMode", static_cast<int32_t>(list.generator_mode)});
    parameters.push_back({"DetectionMethodGridCodeIslanding", static_cast<int32_t>(list.grid_code_detection_methode)});
}

ParameterSet::ParameterSet(uint16_t _id, const DcParameterList& list) : id(_id) {
    parameters.push_back({"Connector", static_cast<int32_t>(list.connector)});
    parameters.push_back({"ControlMode", static_cast<int32_t>(list.control_mode)});
    if (list.control_mode == message_20::ControlMode::Scheduled) {
        parameters.push_back(
            {"MobilityNeedsMode", static_cast<int32_t>(message_20::MobilityNeedsMode::ProvidedByEvcc)});
    } else {
        parameters.push_back({"MobilityNeedsMode", static_cast<int32_t>(list.mobility_needs_mode)});
    }
    parameters.push_back({"Pricing", static_cast<int32_t>(list.pricing)});
}

ParameterSet::ParameterSet(uint16_t _id, const DcBptParameterList& list) : id(_id) {
    parameters.push_back({"Connector", static_cast<int32_t>(list.connector)});
    parameters.push_back({"ControlMode", static_cast<int32_t>(list.control_mode)});
    if (list.control_mode == message_20::ControlMode::Scheduled) {
        parameters.push_back(
            {"MobilityNeedsMode", static_cast<int32_t>(message_20::MobilityNeedsMode::ProvidedByEvcc)});
    } else {
        parameters.push_back({"MobilityNeedsMode", static_cast<int32_t>(list.mobility_needs_mode)});
    }
    parameters.push_back({"Pricing", static_cast<int32_t>(list.pricing)});
    parameters.push_back({"BPTChannel", static_cast<int32_t>(list.bpt_channel)});
    parameters.push_back({"GeneratorMode", static_cast<int32_t>(list.generator_mode)});
}

ParameterSet::ParameterSet(uint16_t _id, const InternetParameterList& list) : id(_id) {
    parameters.push_back({"Protocol", message_20::from_Protocol(list.protocol)});
    parameters.push_back({"Port", static_cast<int32_t>(list.port)});
}

ParameterSet::ParameterSet(uint16_t _id, const ParkingParameterList& list) : id(_id) {
    parameters.push_back({"IntendedService", static_cast<int32_t>(list.intended_service)});
    parameters.push_back({"ParkingStatusType", static_cast<int32_t>(list.parking_status)});
}

} // namespace iso15118::message_20
