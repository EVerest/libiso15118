// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/service_discovery.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access_d2.hpp>

#include <exi/cb/iso2_msgDefDatatypes.h>
#include <exi/cb/iso2_msgDefEncoder.h>


namespace iso15118::message_2 {

template <> void convert(const struct iso2_ServiceDiscoveryReqType& in, ServiceDiscoveryRequest& out) {
    //convert(in.Header, out.header);

    // if (in.SupportedServiceIDs_isUsed == true) {
    //     auto& temp = out.supported_service_ids.emplace();
    //     temp.insert(temp.end(), in.SupportedServiceIDs.ServiceID.array,
    //                 in.SupportedServiceIDs.ServiceID.array + in.SupportedServiceIDs.ServiceID.arrayLen);
    // }

    //RDB ISO2 is somewhat different than ISO2, with just ServiceScope and ServiceCategory instead of SupportedServiceIDs 
    //for filtering the response, though maybe they can be mapped so we can use the iso20 code in the state handler? 
    //RDB TODO ignored for the moment
    // if(in.ServiceScope_isUsed==true){
    //     out.ServiceScope = CB2CPP_STRING(in.ServiceScope);
    //     out.ServiceScope_isUsed=true;
    // }
    // if(in.ServiceCategory_isUsed == true){
    //     cb_convert_enum(in.ServiceCategory, out.ServiceCategory);
    //     out.ServiceCategory_isUsed=in.ServiceCategory_isUsed;
    // }
}

template <> void convert(const ServiceDiscoveryResponse& in, iso2_ServiceDiscoveryResType& out) {
    init_iso2_ServiceDiscoveryResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
    //RDB No service renegotiation in ISO2
    //out.ServiceRenegotiationSupported = in.service_renegotiation_supported;

    uint8_t index = 0;

    //RDB ISO2 needs PaymentOptionList which doesn't exist in ISO20
    //RDB TODO - this is hard coded, needs to be fixed properly.
    auto& out_payment_option = out.PaymentOptionList.PaymentOption.array[0];
    out_payment_option=iso2_paymentOptionType_ExternalPayment;
    out.PaymentOptionList.PaymentOption.arrayLen=1;
    

    //RDB ISO2 is different than ISO20, though maybe they can be mapped?
    //For ISO2, there is a single charge service, with a list of supported energy transfer modes.
    //For ISO20 there is a list of energy_transfer_services which has ServiceCategory and FreeService in each one
    //RDB TODO for right now, we only handle DC charging on CCS extended.
    for (auto const& service : in.energy_transfer_service_list) {
        if(service.service_id==ServiceCategory::DC){
            auto& out_service = out.ChargeService;
            out_service.ServiceCategory = iso2_serviceCategoryType_EVCharging;
            out_service.ServiceID=V2G_SERVICE_ID_CHARGING;
            out_service.FreeService = service.free_service;
            auto& out_etm = out_service.SupportedEnergyTransferMode.EnergyTransferMode.arrayLen=1;
            out_service.SupportedEnergyTransferMode.EnergyTransferMode.array[0]=iso2_EnergyTransferModeType_DC_extended;
        }
    }

    if (in.vas_list) {
        index = 0;
        for (auto const& service : *in.vas_list) {
            auto& out_service = out.ServiceList.Service.array[index++];
            cb_convert_enum(service.service_id, out_service.ServiceID);
            out_service.FreeService = service.free_service;
        }
        out.ServiceList.Service.arrayLen = in.vas_list.value().size();
        CB_SET_USED(out.ServiceList);
    }

    //RDB - ISO2 separates the header and the body, so we don't convert the header here, do it in the serialize_to_exi instead.
    //convert(in.header, out.Header);
}

template <> void insert_type(VariantAccess& va, const struct iso2_ServiceDiscoveryReqType& in) {
    va.insert_type<ServiceDiscoveryRequest>(in);
};

template <> int serialize_to_exi(const ServiceDiscoveryResponse& in, exi_bitstream_t& out) {
    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    //RDB this is new in ISO2
    init_iso2_BodyType(&doc.V2G_Message.Body);

    //RDB Convert the header since it is separate in ISO2.
    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.ServiceDiscoveryRes);

    convert(in, doc.V2G_Message.Body.ServiceDiscoveryRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const ServiceDiscoveryResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
