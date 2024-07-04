// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/dc_current_demand.hpp>

#include <string>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefEncoder.h>
#include <cstring>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_CurrentDemandReqType body;
};

template <> void convert(const V2gMessageRequest& in, DC_CurrentDemandReq& out) {
    convert(in.header, out.header);
    convert(in.body.DC_EVStatus, out.dc_ev_status);
    convert(in.body.EVTargetCurrent, out.ev_target_current);
    if (in.body.EVMaximumVoltageLimit_isUsed) {
        out.ev_maximum_voltage_limit.value() = in.body.EVMaximumVoltageLimit;
    }
    if (in.body.EVMaximumCurrentLimit_isUsed) {
        out.ev_maximum_current_limit.value() = in.body.EVMaximumCurrentLimit;
    }
    if (in.body.EVMaximumPowerLimit_isUsed) {
        out.ev_maximum_power_limit.value() = in.body.EVMaximumPowerLimit;
    }
    if (in.body.BulkChargingComplete_isUsed) {
        out.bulk_charging_complete = in.body.BulkChargingComplete;
    }
    out.charging_complete = in.body.ChargingComplete;
    if (in.body.RemainingTimeToFullSoC_isUsed) {
        out.remaining_time_to_full_soc.value() = in.body.RemainingTimeToFullSoC;
    }
    if (in.body.RemainingTimeToBulkSoC_isUsed) {
        out.remaining_time_to_bulk_soc.value() = in.body.RemainingTimeToBulkSoC;
    }
    convert(in.body.EVTargetVoltage, out.ev_target_voltage);
}

template <> void convert(const DC_CurrentDemandRes& in, iso2_CurrentDemandResType& out) {
    init_iso2_CurrentDemandResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
    convert(in.dc_evse_status, out.DC_EVSEStatus);
    convert(in.evse_present_voltage, out.EVSEPresentVoltage);
    convert(in.evse_present_current, out.EVSEPresentCurrent);
    out.EVSECurrentLimitAchieved = in.evse_current_limit_achieved;
    out.EVSEVoltageLimitAchieved = in.evse_voltage_limit_achieved;
    out.EVSEPowerLimitAchieved = in.evse_power_limit_achieved;
    if (in.evse_maximum_voltage_limit) {
        convert(*in.evse_maximum_voltage_limit, out.EVSEMaximumVoltageLimit);
        CB_SET_USED(out.EVSEMaximumVoltageLimit);
    }
    if (in.evse_maximum_current_limit) {
        convert(*in.evse_maximum_current_limit, out.EVSEMaximumCurrentLimit);
        CB_SET_USED(out.EVSEMaximumCurrentLimit);
    }
    if (in.evse_maximum_power_limit) {
        convert(*in.evse_maximum_power_limit, out.EVSEMaximumPowerLimit);
        CB_SET_USED(out.EVSEMaximumPowerLimit);
    }

    const size_t MAX_SIZE = iso2_EVSEID_CHARACTER_SIZE;
    size_t copyLength = std::min(in.evse_id.size(), MAX_SIZE - 1); // Leave space for null terminator
    strncpy(out.EVSEID.characters, in.evse_id.c_str(), copyLength);
    out.EVSEID.characters[copyLength] = '\0'; // Ensure null termination

    out.SAScheduleTupleID = in.sa_schedule_tuple_id;
    if (in.meter_info) {
        convert(*in.meter_info, out.MeterInfo);
        CB_SET_USED(out.MeterInfo);
    }
    if (in.receipt_required) {
        out.ReceiptRequired = *in.receipt_required;
        CB_SET_USED(out.ReceiptRequired);
    }
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_CurrentDemandReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<DC_CurrentDemandReq>(v2g_message);
}

template <> int serialize_to_exi(const DC_CurrentDemandRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.CurrentDemandRes);
    convert(in, doc.V2G_Message.Body.CurrentDemandRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const DC_CurrentDemandRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
