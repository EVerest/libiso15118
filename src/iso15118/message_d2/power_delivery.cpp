// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/power_delivery.hpp>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_PowerDeliveryReqType body;
};

const auto convertChargingProfile = [](const iso2_ChargingProfileType& in) {
    if (in.ProfileEntry.arrayLen > 0) {
        data_types::ChargingProfile chargingProfile;
        for (uint16_t i = 0; i < in.ProfileEntry.arrayLen; ++i) {
            data_types::ProfileEntry entry;
            entry.charging_profile_entry_start =
                static_cast<uint64_t>(in.ProfileEntry.array[i].ChargingProfileEntryStart);
            convert(in.ProfileEntry.array[i].ChargingProfileEntryMaxPower, entry.charging_profile_entry_max_power);
            if (in.ProfileEntry.array[i].ChargingProfileEntryMaxNumberOfPhasesInUse_isUsed) {
                entry.charging_profile_entry_max_number_of_phases_in_use =
                    static_cast<data_types::max_num_phases_type>(
                        in.ProfileEntry.array[i].ChargingProfileEntryMaxNumberOfPhasesInUse);
            }
            chargingProfile.profile_entry.push_back(entry);
        }
        return chargingProfile;
    } else {
        return data_types::ChargingProfile{};
    }
};

template <> void convert(const V2gMessageRequest& in, PowerDeliveryReq& out) {
    convert(in.header, out.header);
    out.charge_progress = static_cast<data_types::ChargeProgress>(in.body.ChargeProgress);
    out.sa_schedule_tuple_id = in.body.SAScheduleTupleID;
    if (in.body.ChargingProfile_isUsed) {
        out.charging_profile = convertChargingProfile(in.body.ChargingProfile);
    }
    if (in.body.EVPowerDeliveryParameter_isUsed) {
        // TODO (tm): not sure what should happen here
        //        out.ev_power_delivery_parameter = in.body.EVPowerDeliveryParameter._unused;
    }
}

template <> void convert(const PowerDeliveryRes& in, iso2_PowerDeliveryResType& out) {
    init_iso2_PowerDeliveryResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
    convert(in.evse_status, out.EVSEStatus);
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_PowerDeliveryReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<PowerDeliveryReq>(v2g_message);
}

template <> int serialize_to_exi(const PowerDeliveryRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.PowerDeliveryRes);
    convert(in, doc.V2G_Message.Body.PowerDeliveryRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const PowerDeliveryRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
