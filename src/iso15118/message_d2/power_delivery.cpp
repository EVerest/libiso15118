// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/power_delivery.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access_d2.hpp>

#include <exi/cb/iso2_msgDefDatatypes.h>
#include <exi/cb/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {


template <> void convert(const struct iso2_PowerDeliveryReqType& in, PowerDeliveryRequest& out) {
    //convert(in.Header, out.header);

    //cb_convert_enum(in. EVProcessing, out.processing);
    cb_convert_enum(in.ChargeProgress, out.charge_progress);

    //RDB TODO handle the rest of the incoming parameters, esp the SessionID

}

template <> void convert(const PowerDeliveryResponse& in, iso2_PowerDeliveryResType& out) {
    init_iso2_PowerDeliveryResType(&out);

    //convert(in.header, out.Header);
    cb_convert_enum(in.response_code, out.ResponseCode);
    
    //CPP2CB_CONVERT_IF_USED(in.status, out.EVSEStatus);
    
    //RDB Also send send the DC_EVStatus
    out.DC_EVSEStatus_isUsed=true;
    out.DC_EVSEStatus.NotificationMaxDelay=0;
    out.DC_EVSEStatus.EVSENotification=iso2_EVSENotificationType_None;
    out.DC_EVSEStatus.EVSEStatusCode=iso2_DC_EVSEStatusCodeType_EVSE_Ready;
    //RDB TODO - isolation status needs to reflect the IMD state.
    out.DC_EVSEStatus.EVSEIsolationStatus=iso2_isolationLevelType_Valid;
    out.DC_EVSEStatus.EVSEIsolationStatus_isUsed=true;

}

template <> void insert_type(VariantAccess& va, const struct iso2_PowerDeliveryReqType& in) {
    va.insert_type<PowerDeliveryRequest>(in);
};

template <> int serialize_to_exi(const PowerDeliveryResponse& in, exi_bitstream_t& out) {
    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    //RDB this is new in ISO2
    init_iso2_BodyType(&doc.V2G_Message.Body);

    //RDB Convert the header since it is separate in ISO2.
    convert(in.header, doc.V2G_Message.Header);


    CB_SET_USED(doc.V2G_Message.Body.PowerDeliveryRes);

    convert(in, doc.V2G_Message.Body.PowerDeliveryRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const PowerDeliveryResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
