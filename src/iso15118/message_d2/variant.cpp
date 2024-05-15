// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/variant.hpp>

#include <cassert>
#include <string>

#include <iso15118/detail/helper.hpp>
#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_2/iso2_msgDefDatatypes.h>
#include <cbv2g/iso_2/iso2_msgDefDecoder.h>

using PayloadType = iso15118::io::v2gtp::PayloadType;

namespace iso15118::message_2 {

static void handle_v2g(VariantAccess& va) {
    // Todo(sl)!!!
    iso2_exiDocument doc;

    const auto decode_status = decode_iso2_exiDocument(&va.input_stream, &doc);

    if (decode_status != 0) {
        va.error = "decode_iso2_exiDocument failed with " + std::to_string(decode_status);
        return;
    }

    // RDB adapt to ISO2 structure of the document.
    if (doc.V2G_Message.Body.SessionSetupReq_isUsed) {
        insert_type(va, doc.V2G_Message.Body.SessionSetupReq);
        // RDB bring over the header into the full struct.
        va.insert_header(doc.V2G_Message.Header);
        // } else if (doc.V2G_Message.Body.AuthorizationSetupReq_isUsed) {
        //     insert_type(va, doc.V2G_Message.Body.AuthorizationSetupReq);
    } else if (doc.V2G_Message.Body.AuthorizationReq_isUsed) {
        insert_type(va, doc.V2G_Message.Body.AuthorizationReq);
        // RDB bring over the header into the full struct.
        va.insert_header(doc.V2G_Message.Header);
    } else if (doc.V2G_Message.Body.ServiceDiscoveryReq_isUsed) {
        insert_type(va, doc.V2G_Message.Body.ServiceDiscoveryReq);
        // RDB bring over the header into the full struct.
        va.insert_header(doc.V2G_Message.Header);
        // } else if (doc.V2G_Message.Body.ServiceDetailReq_isUsed) {
        //     insert_type(va, doc.V2G_Message.Body.ServiceDetailReq);
    } else if (doc.V2G_Message.Body.PaymentServiceSelectionReq_isUsed) {
        insert_type(va, doc.V2G_Message.Body.PaymentServiceSelectionReq);
        // RDB bring over the header into the full struct.
        va.insert_header(doc.V2G_Message.Header);
    } else if (doc.V2G_Message.Body.ChargeParameterDiscoveryReq_isUsed) {
        insert_type(va, doc.V2G_Message.Body.ChargeParameterDiscoveryReq);
        // RDB bring over the header into the full struct.
        va.insert_header(doc.V2G_Message.Header);
    } else if (doc.V2G_Message.Body.CableCheckReq_isUsed) {
        insert_type(va, doc.V2G_Message.Body.CableCheckReq);
        // RDB bring over the header into the full struct.
        va.insert_header(doc.V2G_Message.Header);
    } else if (doc.V2G_Message.Body.PreChargeReq_isUsed) {
        insert_type(va, doc.V2G_Message.Body.PreChargeReq);
        // RDB bring over the header into the full struct.
        va.insert_header(doc.V2G_Message.Header);
        // } else if (doc.V2G_Message.Body.ScheduleExchangeReq_isUsed) {
        //     insert_type(va, doc.V2G_Message.Body.ScheduleExchangeReq);
    } else if (doc.V2G_Message.Body.PowerDeliveryReq_isUsed) {
        insert_type(va, doc.V2G_Message.Body.PowerDeliveryReq);
        // RDB bring over the header into the full struct.
        va.insert_header(doc.V2G_Message.Header);
    } else if (doc.V2G_Message.Body.CurrentDemandReq_isUsed) {
        insert_type(va, doc.V2G_Message.Body.CurrentDemandReq);
        // RDB bring over the header into the full struct.
        va.insert_header(doc.V2G_Message.Header);
    } else if (doc.V2G_Message.Body.WeldingDetectionReq_isUsed) {
        insert_type(va, doc.V2G_Message.Body.WeldingDetectionReq);
        // RDB bring over the header into the full struct.
        va.insert_header(doc.V2G_Message.Header);
    } else if (doc.V2G_Message.Body.SessionStopReq_isUsed) {
        insert_type(va, doc.V2G_Message.Body.SessionStopReq);
        // RDB bring over the header into the full struct.
        va.insert_header(doc.V2G_Message.Header);
    } else {
        va.error = "chosen message type unhandled";
    }
}

Variant::Variant(io::v2gtp::PayloadType payload_type, const io::StreamInputView& buffer_view) {

    VariantAccess va{
        get_exi_input_stream(buffer_view), this->data, this->type, this->custom_deleter, this->error,
    };

    if (payload_type == PayloadType::SAP) {
        handle_v2g(va);
    } else {
        logf("Unknown type\n");
    }

    if (data) {
        // in case data was set, make sure the custom deleter and the type were set!
        assert(custom_deleter != nullptr);
        assert(type != Type::None);
    } else {
        logf("Failed due to: %s\n", error.c_str());
    }
}

Variant::~Variant() {
    if (data) {
        custom_deleter(data);
    }
}

Type Variant::get_type() const {
    return type;
}

const std::string& Variant::get_error() const {
    return error;
}

} // namespace iso15118::message_2
