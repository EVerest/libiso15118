// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <cassert>

#include <iso15118/message_d2/session_setup.hpp>
#include <iso15118/message_d2/variant.hpp>

#include <exi/cb/iso2_msgDefDatatypes.h>


#include "cb_exi.hpp"

namespace iso15118::message_2 {

struct VariantAccess {
    // input
    exi_bitstream_t input_stream;

    // output
    void*& data;
    iso15118::message_2::Type& type;
    iso15118::message_2::Variant::CustomDeleter& custom_deleter;
    std::string& error;

    template <typename MessageType, typename CbExiMessageType> void insert_type(const CbExiMessageType& in) {
        assert(data == nullptr);

        data = new MessageType;
        type = iso15118::message_2::TypeTrait<MessageType>::type;
        custom_deleter = [](void* ptr) { delete static_cast<MessageType*>(ptr); };

        convert(in, *static_cast<MessageType*>(data));
    };

    //RDB All headers are in the same place in all MessageTypes, so use any one as a template.
    void insert_header(const iso2_MessageHeaderType& in) {
        
        std::copy(in.SessionID.bytes, in.SessionID.bytes + in.SessionID.bytesLen, static_cast<SessionSetupRequest*>(data)->header.session_id.begin());
    
    };


};

template <typename CbExiMessageType> void insert_type(VariantAccess& va, const CbExiMessageType&);

} // namespace iso15118::message_2
