// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message_d2/session_setup.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access_d2.hpp>

#include <exi/cb/iso2_msgDefDatatypes.h>
#include <exi/cb/iso2_msgDefEncoder.h>

namespace iso15118::message_2 {

//
// conversions
//
template <> void convert(const struct iso2_SessionSetupReqType& in, SessionSetupRequest& out) {
    //convert(in.Header, out.header);// RDB no header in message.
    //out.evccid = CPP2CB_BYTES(in.EVCCID);  //RDB iso2 uses bytes not chars, not sure how to do this.
}


template <> void convert(const SessionSetupResponse& in, iso2_SessionSetupResType& out) {
    init_iso2_SessionSetupResType(&out);

    cb_convert_enum(in.response_code, out.ResponseCode);

    CPP2CB_STRING(in.evseid, out.EVSEID);

}

template <> void insert_type(VariantAccess& va, const struct iso2_SessionSetupReqType& in) {
    va.insert_type<SessionSetupRequest>(in);
};

template <> int serialize_to_exi(const SessionSetupResponse& in, exi_bitstream_t& out) {
    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);

    //RDB How do we handle the Header?
    convert(in.header, doc.V2G_Message.Header);
    CB_SET_USED(doc.V2G_Message.Body.SessionSetupRes);

    convert(in, doc.V2G_Message.Body);
    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const SessionSetupResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2
