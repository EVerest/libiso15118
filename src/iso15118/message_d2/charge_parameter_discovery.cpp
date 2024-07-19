// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest

#include <iso15118/message_d2/charge_parameter_discovery.hpp>
#include <iso15118/message_d2/message_header.hpp>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_ChargeParameterDiscoveryReqType body;
};

template <> void convert(const V2gMessageRequest& in, ChargeParameterDiscoveryReq& out) {
    convert(in.header, out.header);
    if (in.body.MaxEntriesSAScheduleTuple_isUsed) {
        out.max_entries_sa_schedule_tuple = in.body.MaxEntriesSAScheduleTuple;
    }
    out.requested_energy_transfer_mode =
        static_cast<data_types::EnergyTransferMode>(in.body.RequestedEnergyTransferMode);
    convert(in.body.EVChargeParameter, out.ev_charge_parameter);
}

template <> void convert(const ChargeParameterDiscoveryRes& in, iso2_ChargeParameterDiscoveryResType& out) {
    init_iso2_ChargeParameterDiscoveryResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
    cb_convert_enum(in.evse_processing, out.EVSEProcessing);
    if (in.sa_schedules) {
        convert(*in.sa_schedules, out.SASchedules);
        CB_SET_USED(out.SASchedules);
    }
    convert(in.evse_charge_parameter, out.EVSEChargeParameter);
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_ChargeParameterDiscoveryReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<ChargeParameterDiscoveryReq>(v2g_message);
}

template <> int serialize_to_exi(const ChargeParameterDiscoveryRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.ChargeParameterDiscoveryRes);
    convert(in, doc.V2G_Message.Body.ChargeParameterDiscoveryRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const ChargeParameterDiscoveryRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
