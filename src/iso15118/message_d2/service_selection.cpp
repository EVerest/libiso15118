// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/service_discovery.hpp>
#include <iso15118/message_d2/service_selection.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefDatatypes.h>
#include <cbv2g/iso_2/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

struct V2gMessageRequest {
    iso2_MessageHeaderType header;
    iso2_PaymentServiceSelectionReqType body;
};

template <> void convert(const V2gMessageRequest& in, PaymentServiceSelectionReq& out) {
    convert(in.header, out.header);
    out.selected_payment_option =
        static_cast<data_types::PaymentOption>(in.body.SelectedPaymentOption);
    convert(in.body.SelectedServiceList, out.selected_service_list);
}

template <> void convert(const PaymentServiceSelectionRes& in, iso2_PaymentServiceSelectionResType& out) {
    init_iso2_PaymentServiceSelectionResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);
}

template <>
void insert_type(VariantAccess& va, const struct iso2_MessageHeaderType& header,
                 const struct iso2_PaymentServiceSelectionReqType& in) {

    const auto v2g_message = V2gMessageRequest{header, in};
    va.insert_type<PaymentServiceSelectionReq>(v2g_message);
}

template <> int serialize_to_exi(const PaymentServiceSelectionRes& in, exi_bitstream_t& out) {

    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    convert(in.header, doc.V2G_Message.Header);

    CB_SET_USED(doc.V2G_Message.Body.PaymentServiceSelectionRes);
    convert(in, doc.V2G_Message.Body.PaymentServiceSelectionRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const PaymentServiceSelectionRes& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
