// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cassert>

#include <iso15118/message_d2_sap/variant.hpp>

#include "cb_exi.hpp"

namespace iso15118::message_2_sap {

struct VariantAccess {
    // input
    exi_bitstream_t input_stream;

    // output
    void*& data;
    iso15118::message_2_sap::Type& type;
    iso15118::message_2_sap::Variant::CustomDeleter& custom_deleter;
    std::string& error;

    template <typename MessageType, typename CbExiMessageType> void insert_type(const CbExiMessageType& in) {
        assert(data == nullptr);

        data = new MessageType;
        type = iso15118::message_2_sap::TypeTrait<MessageType>::type;
        custom_deleter = [](void* ptr) { delete static_cast<MessageType*>(ptr); };

        convert(in, *static_cast<MessageType*>(data));
    };
};

template <typename CbExiMessageType> void insert_type(VariantAccess& va, const CbExiMessageType&);

} // namespace iso15118::message_2_sap
