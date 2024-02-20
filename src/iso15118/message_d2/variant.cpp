// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/variant.hpp>

#include <cassert>
#include <string>

#include <iso15118/detail/helper.hpp>
#include <iso15118/detail/variant_access.hpp>

using PayloadType = iso15118::io::v2gtp::PayloadType;

namespace iso15118::message_2 {

static void handle_v2g(VariantAccess& va) {
    // Todo(sl)!!!
    // appHand_exiDocument doc;

    // const auto decode_status = decode_appHand_exiDocument(&va.input_stream, &doc);

    // if (decode_status != 0) {
    //     va.error = "decode_appHand_exiDocument failed with " + std::to_string(decode_status);
    //     return;
    // }

    // if (doc.supportedAppProtocolReq_isUsed) {
    //     insert_type(va, doc.supportedAppProtocolReq);
    // } else {
    //     va.error = "chosen message type unhandled";
    // }
}

Variant::Variant(io::v2gtp::PayloadType payload_type, const io::StreamInputView& buffer_view) {

    VariantAccess va{
        get_exi_input_stream(buffer_view), this->data, this->type, this->custom_deleter, this->error,
    };

    if (payload_type == PayloadType::SAP) {
        handle_v2g(va); // Todo(sl): Umbennen....
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
