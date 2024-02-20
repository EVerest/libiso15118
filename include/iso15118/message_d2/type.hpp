// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/io/stream_view.hpp>

namespace iso15118::message_2 {

enum class Type {
    None,
    SessionSetupReq,
    SessionSetupRes,
};

template <typename T> struct TypeTrait {
    static const Type type = Type::None;
};

template <typename InType, typename OutType> void convert(const InType&, OutType&);

template <typename MessageType> size_t serialize(const MessageType&, const io::StreamOutputView&);

//
// definitions of type traits
//
#ifdef CREATE_TYPE_TRAIT
#define CREATE_TYPE_TRAIT_PUSHED CREATE_TYPE_TRAIT
#endif

#define CREATE_TYPE_TRAIT(struct_name, enum_name)                                                                      \
    struct struct_name;                                                                                                \
    template <> struct TypeTrait<struct_name> {                                                                        \
        static const Type type = Type::enum_name;                                                                      \
    }

CREATE_TYPE_TRAIT(SessionSetupRequest, SessionSetupReq);

#ifdef CREATE_TYPE_TRAIT_PUSHED
#define CREATE_TYPE_TRAIT CREATE_TYPE_TRAIT_PUSHED
#else
#undef CREATE_TYPE_TRAIT
#endif

} // namespace iso15118::message_2
