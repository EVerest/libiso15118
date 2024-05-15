// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/dc_charge_parameter_discovery.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefDatatypes.h>
#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

// RDB we only have one way DC, no BPT in ISO2. Leave in the ModeResponseVisitor stuff in case it is useful for AC

using DC_ModeReq = DC_ChargeParameterDiscoveryRequest::DC_CPDReqEnergyTransferMode;

using DC_ModeRes = DC_ChargeParameterDiscoveryResponse::DC_CPDResEnergyTransferMode;

// RDB Note that ISO2 uses PhysicalValueType while ISO20 uses RationalNumber. We will need to have a conversion.
template <> void convert(const struct iso2_ChargeParameterDiscoveryReqType& in, DC_ModeReq& out) {
    if (in.DC_EVChargeParameter.EVMaximumPowerLimit_isUsed) {
        convert(in.DC_EVChargeParameter.EVMaximumPowerLimit, out.max_charge_power);
    }
    // RDB no min power     //convert(in.DC_EVChargeParameter.EVMaximumPowerLimit, out.min_charge_power);
    convert(in.DC_EVChargeParameter.EVMaximumCurrentLimit, out.max_charge_current);

    // RDB No minimum current in iso2     //convert(in.DC_EVChargeParameter.EVMinimumChargeCurrent,
    // out.min_charge_current);
    convert(in.DC_EVChargeParameter.EVMaximumVoltageLimit, out.max_voltage);

    // RDB no minimum voltage    //convert(in.DC_EVChargeParameter.EVMinimumVoltage, out.min_voltage);
    if (in.DC_EVChargeParameter.FullSOC_isUsed) {
        out.target_soc = in.DC_EVChargeParameter.FullSOC;
    }
}

template <>
void convert(const struct iso2_ChargeParameterDiscoveryReqType& in, DC_ChargeParameterDiscoveryRequest& out) {
    // convert(in.Header, out.header);

    // RDB we only have one way DC, not BPT in ISO2
    if (in.DC_EVChargeParameter_isUsed) {
        auto& mode_out = out.transfer_mode.emplace<DC_ModeReq>();
        convert(in, mode_out);
    } else {
        // FIXME (aw): fail, should not happen!
    }
}

template <> void insert_type(VariantAccess& va, const struct iso2_ChargeParameterDiscoveryReqType& in) {
    va.insert_type<DC_ChargeParameterDiscoveryRequest>(in);
}

struct ModeResponseVisitor {
    ModeResponseVisitor(iso2_ChargeParameterDiscoveryResType& res_) : res(res_){};
    void operator()(const DC_ModeRes& in) {
        init_iso2_ChargeParameterDiscoveryResType(&res);
        CB_SET_USED(res.DC_EVSEChargeParameter);

        convert_common(in, res);
    }

    template <typename ModeResTypeIn, typename ModeResTypeOut>
    static void convert_common(const ModeResTypeIn& in, ModeResTypeOut& out) {
        convert(in.max_charge_power, out.DC_EVSEChargeParameter.EVSEMaximumPowerLimit);
        // RDB Also set the ISO2 Unit
        out.DC_EVSEChargeParameter.EVSEMaximumPowerLimit.Unit = iso2_unitSymbolType_W;
        // convert(in.min_charge_power, out.DC_EVSEChargeParameter.EVSEMinimumPowerLimit);
        convert(in.max_charge_current, out.DC_EVSEChargeParameter.EVSEMaximumCurrentLimit);
        // RDB Also set the ISO2 Unit
        out.DC_EVSEChargeParameter.EVSEMaximumCurrentLimit.Unit = iso2_unitSymbolType_A;
        convert(in.min_charge_current, out.DC_EVSEChargeParameter.EVSEMinimumCurrentLimit);
        out.DC_EVSEChargeParameter.EVSEMinimumCurrentLimit.Unit = iso2_unitSymbolType_A;
        convert(in.max_voltage, out.DC_EVSEChargeParameter.EVSEMaximumVoltageLimit);
        // RDB Also set the ISO2 Unit
        out.DC_EVSEChargeParameter.EVSEMaximumVoltageLimit.Unit = iso2_unitSymbolType_V;
        convert(in.min_voltage, out.DC_EVSEChargeParameter.EVSEMinimumVoltageLimit);
        out.DC_EVSEChargeParameter.EVSEMinimumVoltageLimit.Unit = iso2_unitSymbolType_V;

        // out.EVSEPowerRampLimitation_isUsed = in.power_ramp_limit.has_value();
        // if (in.power_ramp_limit) {
        //     convert(*in.power_ramp_limit, out.EVSEPowerRampLimitation);
        // }
    }

private:
    iso2_ChargeParameterDiscoveryResType& res;
};

template <>
void convert(const DC_ChargeParameterDiscoveryResponse& in, struct iso2_ChargeParameterDiscoveryResType& out) {
    init_iso2_ChargeParameterDiscoveryResType(&out);
    // RDB not done here convert(in.header, out.Header);
    cb_convert_enum(in.response_code, out.ResponseCode);
    std::visit(ModeResponseVisitor(out), in.transfer_mode);

    // RDB set up the DC EVSE Status and other ISO2 stuff.
    // RDB TODO - Improve this
    //  we get this exception from Josev, even when exactly duplicating the values that are sent by EVSEV2G
    // iso15118_car    pybind11_init_everestpy(pybind11::module_&)::<lambda(const string&)> :: EXIDecodingError
    // (Exception): Exception: javax.xml.bind.UnmarshalException    //RDB From Josev, we are getting a
    out.ResponseCode = iso2_responseCodeType_OK;
    out.EVSEProcessing = iso2_EVSEProcessingType_Finished;

    out.SASchedules_isUsed = false;
    out.AC_EVSEChargeParameter_isUsed = false;
    out.EVSEChargeParameter_isUsed = false;

    // RDB apparently to keep Josev happy, we also need a SASScheduleList
    out.SAScheduleList_isUsed = true;
    out.SAScheduleList.SAScheduleTuple.arrayLen = 1;
    out.SAScheduleList.SAScheduleTuple.array[0].SAScheduleTupleID = 1;
    out.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].RelativeTimeInterval.start = 0;
    out.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].RelativeTimeInterval.duration =
        86400;
    out.SAScheduleList.SAScheduleTuple.array[0]
        .PMaxSchedule.PMaxScheduleEntry.array[0]
        .RelativeTimeInterval.duration_isUsed = true;
    out.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].RelativeTimeInterval_isUsed =
        true;
    out.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].TimeInterval_isUsed = false;
    out.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Multiplier = 0;
    out.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Unit =
        iso2_unitSymbolType_W;
    out.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.array[0].PMax.Value = 22080;
    out.SAScheduleList.SAScheduleTuple.array[0].PMaxSchedule.PMaxScheduleEntry.arrayLen = 1;
    out.SAScheduleList.SAScheduleTuple.array[0].SalesTariff_isUsed = false;

    out.DC_EVSEChargeParameter.DC_EVSEStatus.NotificationMaxDelay = 0;
    out.DC_EVSEChargeParameter.DC_EVSEStatus.EVSENotification = iso2_EVSENotificationType_None;
    out.DC_EVSEChargeParameter.DC_EVSEStatus.EVSEIsolationStatus = iso2_isolationLevelType_Invalid;
    out.DC_EVSEChargeParameter.DC_EVSEStatus.EVSEStatusCode = iso2_DC_EVSEStatusCodeType_EVSE_Ready;
    out.DC_EVSEChargeParameter.DC_EVSEStatus.EVSEIsolationStatus_isUsed = true;

    // RDB For some reason Josev doesn't like the EXI produced. Match the values from the EVSEV2G version exactly, since
    // it works.
    //  we get this exception from Josev
    // iso15118_car    pybind11_init_everestpy(pybind11::module_&)::<lambda(const string&)> :: EXIDecodingError
    // (Exception): Exception: javax.xml.bind.UnmarshalException
    out.DC_EVSEChargeParameter.EVSEMaximumCurrentLimit.Multiplier = -2;
    out.DC_EVSEChargeParameter.EVSEMaximumCurrentLimit.Unit = iso2_unitSymbolType_A;
    out.DC_EVSEChargeParameter.EVSEMaximumCurrentLimit.Value = 20000;

    out.DC_EVSEChargeParameter.EVSEMaximumPowerLimit.Multiplier = 0;
    out.DC_EVSEChargeParameter.EVSEMaximumPowerLimit.Unit = iso2_unitSymbolType_W;
    out.DC_EVSEChargeParameter.EVSEMaximumPowerLimit.Value = 22080;

    out.DC_EVSEChargeParameter.EVSEMaximumVoltageLimit.Multiplier = -1;
    out.DC_EVSEChargeParameter.EVSEMaximumVoltageLimit.Unit = iso2_unitSymbolType_V;
    out.DC_EVSEChargeParameter.EVSEMaximumVoltageLimit.Value = 9000;

    out.DC_EVSEChargeParameter.EVSEMinimumCurrentLimit.Multiplier = -1;
    out.DC_EVSEChargeParameter.EVSEMinimumCurrentLimit.Unit = iso2_unitSymbolType_A;
    out.DC_EVSEChargeParameter.EVSEMinimumCurrentLimit.Value = 10;

    out.DC_EVSEChargeParameter.EVSEMinimumVoltageLimit.Multiplier = -1;
    out.DC_EVSEChargeParameter.EVSEMinimumVoltageLimit.Unit = iso2_unitSymbolType_V;
    out.DC_EVSEChargeParameter.EVSEMinimumVoltageLimit.Value = 2000;

    out.DC_EVSEChargeParameter.EVSECurrentRegulationTolerance.Multiplier = -1;
    out.DC_EVSEChargeParameter.EVSECurrentRegulationTolerance.Unit = iso2_unitSymbolType_A;
    out.DC_EVSEChargeParameter.EVSECurrentRegulationTolerance.Value = 20;
    out.DC_EVSEChargeParameter.EVSECurrentRegulationTolerance_isUsed = true;

    out.DC_EVSEChargeParameter.EVSEPeakCurrentRipple.Multiplier = -1;
    out.DC_EVSEChargeParameter.EVSEPeakCurrentRipple.Unit = iso2_unitSymbolType_A;
    out.DC_EVSEChargeParameter.EVSEPeakCurrentRipple.Value = 20;

    out.DC_EVSEChargeParameter.EVSEEnergyToBeDelivered.Multiplier = 0;
    out.DC_EVSEChargeParameter.EVSEEnergyToBeDelivered.Unit = iso2_unitSymbolType_Wh;
    out.DC_EVSEChargeParameter.EVSEEnergyToBeDelivered.Value = 10000;
    out.DC_EVSEChargeParameter.EVSEEnergyToBeDelivered_isUsed = true;
}

template <> int serialize_to_exi(const DC_ChargeParameterDiscoveryResponse& in, exi_bitstream_t& out) {
    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    // RDB this is new in ISO2
    init_iso2_BodyType(&doc.V2G_Message.Body);

    // RDB Convert the header since it is separate in ISO2.
    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.ChargeParameterDiscoveryRes);

    convert(in, doc.V2G_Message.Body.ChargeParameterDiscoveryRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const DC_ChargeParameterDiscoveryResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
