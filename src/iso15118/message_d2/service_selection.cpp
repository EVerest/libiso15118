// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/service_selection.hpp>
#include <iso15118/message_d2/service_discovery.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access_d2.hpp>

#include <exi/cb/iso2_msgDefDatatypes.h>
#include <exi/cb/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

template <> void convert(const struct iso2_PaymentServiceSelectionReqType& in, ServiceSelectionRequest& out) {
    //convert(in.Header, out.header);

    //RDB TODO Ignore the payment service selection for now.

    //RDB this message is substantially different in ISO2 than ISO20. There is no 
    //SelectedEnergyTransferService, instead, the selected charge service is in the SelectedServiceList.

    for (size_t i = 0; i < in.SelectedServiceList.SelectedService.arrayLen; i++) {
        const auto& item_in = in.SelectedServiceList.SelectedService.array[i];

        // RDB In ISO2 ParameterSetID is optional, in ISO20 it is mandatory
        if (item_in.ServiceID == V2G_SERVICE_ID_CHARGING) {
            if (item_in.ParameterSetID_isUsed == 1) {
                out.selected_energy_transfer_service.parameter_set_id = item_in.ParameterSetID;
            }
            // RDB ServiceID is different in ISO2 (table 105) and ISO20 (table 204)
            // RDB TODO handle more than DC
            out.selected_energy_transfer_service.service_id = ServiceCategory::DC;
        }

        //RDB TODO handle VAS

    }


    // if (in.SelectedVASList_isUsed == true) {
    //     out.selected_vas_list.value().reserve(in.SelectedVASList.SelectedService.arrayLen);
    //     auto& vas_list_out = *out.selected_vas_list;

    //     for (size_t i = 0; i < in.SelectedVASList.SelectedService.arrayLen; i++) {
    //         const auto& item_in = in.SelectedVASList.SelectedService.array[i];
    //         auto& item_out = vas_list_out.emplace_back();

    //         cb_convert_enum(item_in.ServiceID, item_out.service_id);
    //         item_out.parameter_set_id = item_in.ParameterSetID;
    //     }
    // }
}

template <> void convert(const ServiceSelectionResponse& in, iso2_PaymentServiceSelectionResType& out) {
    init_iso2_PaymentServiceSelectionResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);

    //RDB - ISO2 separates the header and the body, so we don't convert the header here, do it in the serialize_to_exi instead.
    //convert(in.header, out.Header);
}

//RDB ISO2 is called PaymentServiceSelection and ISO20 is called ServiceSelection.
template <> void insert_type(VariantAccess& va, const struct iso2_PaymentServiceSelectionReqType& in) {
    va.insert_type<ServiceSelectionRequest>(in);
}

template <> int serialize_to_exi(const ServiceSelectionResponse& in, exi_bitstream_t& out) {
    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    //RDB this is new in ISO2
    init_iso2_BodyType(&doc.V2G_Message.Body);

    //RDB Convert the header since it is separate in ISO2.
    convert(in.header, doc.V2G_Message.Header);
    
    CB_SET_USED(doc.V2G_Message.Body.PaymentServiceSelectionRes);

    convert(in, doc.V2G_Message.Body.PaymentServiceSelectionRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const ServiceSelectionResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
