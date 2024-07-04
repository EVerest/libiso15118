// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/common.hpp>

#include <cmath>

#include <iso15118/detail/cb_exi.hpp>
#include <iso15118/message_d2/variant.hpp>

#include <cbv2g/iso_2/iso2_msgDefDatatypes.h>

namespace iso15118::message_2 {

template <> void convert(const iso2_NotificationType& in, Notification& out) {
    cb_convert_enum(in.FaultCode, out.fault_code);

    if (in.FaultMsg_isUsed) {
        out.fault_message = CB2CPP_STRING(in.FaultMsg);
    }
}

template <> void convert(const iso2_MessageHeaderType& in, V2GMessageHeader& out) {

    std::copy(in.SessionID.bytes, in.SessionID.bytes + in.SessionID.bytesLen, out.session_id.begin());

    CB2CPP_CONVERT_IF_USED(in.Notification, out.notification);

    // Todo(sl): missing signature
}

template <> void convert(const Notification& in, iso2_NotificationType& out) {

    cb_convert_enum(in.fault_code, out.FaultCode);

    if (in.fault_message) {
        CPP2CB_STRING(in.fault_message.value(), out.FaultMsg);
        CB_SET_USED(out.FaultMsg);
    }
}

template <> void convert(const V2GMessageHeader& in, iso2_MessageHeaderType& out) {
    init_iso2_MessageHeaderType(&out);

    std::copy(in.session_id.begin(), in.session_id.end(), out.SessionID.bytes);

    // FIXME (aw): this should be fixed 8
    out.SessionID.bytesLen = 8;

    CPP2CB_CONVERT_IF_USED(in.notification, out.Notification);

    // Todo(sl): Missing signature
}

// Todo: Review!
// --------------------------------------------------------

// template <typename cb_RationalNumberType> void convert(const cb_RationalNumberType& in, RationalNumber& out) {
//     out.exponent = in.Exponent;
//     out.value = in.Value;
// }

// template void convert(const struct iso20_dc_RationalNumberType& in, RationalNumber& out);
// template void convert(const struct iso20_RationalNumberType& in, RationalNumber& out);

// template <typename cb_RationalNumberType> void convert(const RationalNumber& in, cb_RationalNumberType& out) {
//     out.Exponent = in.exponent;
//     out.Value = in.value;
// }

// template void convert(const RationalNumber& in, struct iso20_dc_RationalNumberType& out);
// template void convert(const RationalNumber& in, struct iso20_RationalNumberType& out);

// template <> void convert(const EvseStatus& in, struct iso20_dc_EVSEStatusType& out) {
//     out.NotificationMaxDelay = in.notification_max_delay;
//     cb_convert_enum(in.notification, out.EVSENotification);
// }

// /*!
//  * \brief init_physical_value This funcion inits a physicalValue struct.
//  * \param physicalValue is the struct of the physical value.
//  * \param unit is the unit of the physical value.
//  */
// void init_physical_value(struct iso2_PhysicalValueType* const physicalValue, iso2_unitSymbolType unit);

// // RDB Copied from v2gctx.hpp
// /*!
//  * \brief populate_physical_value This function fills all elements of a \c iso1PhysicalValueType struct regarding the
//  * parameter value and unit.
//  * \param pv is pointer to the physical value struct
//  * \param value is the physical value
//  * \param unit is the unit of the physical value
//  * \return Returns \c true if the convertion was succesfull, otherwise \c false.
//  */
// bool populate_physical_value(struct iso2_PhysicalValueType* pv, long long int value, iso2_unitSymbolType unit);

// /*!
//  * \brief populate_physical_value_float This function fills all elements of a \c iso1PhysicalValueType struct from a
//  * json object.
//  * \param pv is pointer to the physical value struct
//  * \param value is the physical value
//  * \param decimal_places is to determine the precision
//  * \param unit is the unit of the physical value
//  */
// void populate_physical_value_float(struct iso2_PhysicalValueType* pv, float value, uint8_t decimal_places,
//                                    iso2_unitSymbolType unit);

// void init_physical_value(struct iso2_PhysicalValueType* const physicalValue, iso2_unitSymbolType unit) {
//     physicalValue->Multiplier = 0;
//     physicalValue->Unit = unit;
//     physicalValue->Value = 0;
// }

// // Only for AC
// bool populate_physical_value(struct iso2_PhysicalValueType* pv, long long int value, iso2_unitSymbolType unit) {
//     struct iso2_PhysicalValueType physic_tmp = {pv->Multiplier, pv->Unit, pv->Value}; // To restore
//     pv->Unit = unit;
//     pv->Multiplier = 0; // with integers, we don't need negative multipliers for precision, so start at 0

//     // if the value is too large to be represented in 16 signed bits, increase the multiplier
//     while ((value > INT16_MAX) || (value < INT16_MIN)) {
//         pv->Multiplier++;
//         value /= 10;
//     }

//     // if ((pv->Multiplier < PHY_VALUE_MULT_MIN) || (pv->Multiplier > PHY_VALUE_MULT_MAX)) {
//     //     memcpy(pv, &physic_tmp, sizeof(struct iso1PhysicalValueType));
//     //     dlog(DLOG_LEVEL_WARNING, "Physical value out of scope. Ignore value");
//     //     return false;
//     // }

//     pv->Value = value;

//     return true;
// }

// void populate_physical_value_float(struct iso2_PhysicalValueType* pv, float value, uint8_t decimal_places,
//                                    iso2_unitSymbolType unit) {
//     if (false == populate_physical_value(pv, (long long int)value, unit)) {
//         return;
//     }

//     if (pv->Multiplier == 0) {
//         for (uint8_t idx = 0; idx < decimal_places; idx++) {
//             if (((long int)(value * 10) < INT16_MAX) && ((long int)(value * 10) > INT16_MIN)) {
//                 pv->Multiplier--;
//                 value *= 10;
//             }
//         }
//     }

//     // if (pv->Multiplier != -decimal_places) {
//     //     dlog(DLOG_LEVEL_WARNING,
//     //          "Possible precision loss while converting to physical value type, requested %i, actual %i (value
//     %f)",
//     //          decimal_places, -pv->Multiplier, value);
//     // }

//     pv->Value = value;
// }

// // RDB Add conversions to and from RationalNumber to and from iso2_PhysicalValueType
// // Not sure what to do about the Unit part or the decimal part
// template <> void convert(const iso2_PhysicalValueType& in, RationalNumber& out) {
//     out = from_float(in.Value * (pow(10, in.Multiplier)));
// }
// // RDB TODO Decimal point set to 6? Units set to hours just for a placekeeper
// template <> void convert(const RationalNumber& in, iso2_PhysicalValueType& out) {
//     populate_physical_value_float(&out, in.value * pow(10, in.exponent), 6, iso2_unitSymbolType_h);
// }

// template <typename cb_MeterInfoType> void convert_meterinfo(const MeterInfo& in, cb_MeterInfoType& out) {

//     CPP2CB_STRING(in.meter_id, out.MeterID);
//     out.ChargedEnergyReadingWh = in.charged_energy_reading_wh;

//     CPP2CB_ASSIGN_IF_USED(in.bpt_discharged_energy_reading_wh, out.BPT_DischargedEnergyReadingWh);
//     CPP2CB_ASSIGN_IF_USED(in.capacitive_energy_reading_varh, out.CapacitiveEnergyReadingVARh);
//     CPP2CB_ASSIGN_IF_USED(in.bpt_inductive_energery_reading_varh, out.BPT_InductiveEnergyReadingVARh);

//     if (in.meter_signature) {
//         CPP2CB_BYTES(in.meter_signature.value(), out.MeterSignature);
//         CB_SET_USED(out.MeterSignature);
//     }

//     CPP2CB_ASSIGN_IF_USED(in.meter_status, out.MeterStatus);
//     CPP2CB_ASSIGN_IF_USED(in.meter_timestamp, out.MeterTimestamp);
// }

// template <> void convert(const MeterInfo& in, iso20_dc_MeterInfoType& out) {
//     init_iso20_dc_MeterInfoType(&out);
//     convert_meterinfo(in, out);
// }

// template <> void convert(const EvseStatus& in, iso20_EVSEStatusType& out) {
//     out.NotificationMaxDelay = in.notification_max_delay;
//     cb_convert_enum(in.notification, out.EVSENotification);
// }

// float from_RationalNumber(const RationalNumber& in) {
//     return in.value * pow(10, in.exponent);
// }

// RationalNumber from_float(float in) {

//     int8_t exponent = 0;

//     if (in - std::floor(in) != 0) {
//         exponent = 2;
//     }

//     for (; exponent > -4; exponent--) {
//         if ((in * pow(10, exponent)) < INT16_MAX) {
//             break;
//         }
//     }

//     RationalNumber out;
//     out.exponent = (int8_t)(-exponent);
//     out.value = (int16_t)(in * pow(10, exponent));
//     return out;
// }

// std::string from_Protocol(const Protocol& in) {

//     switch (in) {
//     case Protocol::Ftp:
//         return std::string("ftp");
//     case Protocol::Http:
//         return std::string("http");
//     case Protocol::Https:
//         return std::string("https");
//     }
//     return "";
// }

} // namespace iso15118::message_2
