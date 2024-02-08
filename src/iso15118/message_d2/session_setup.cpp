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
    //RDB - ISO2 separates the header and the body, so we don't have the header here.
    //convert(in.Header, out.header);
    //RDB - ISO2 is a 6 byte hex binary holding the MAC address of the EVCC. ISO20 is an alphanumeric string between 20 and 255 characters.
    //RBL So, this conversion needs to be changed. 
    /* format EVCC ID (from old ISO2 code)*/
    char buffer[8 * 3 - 1 + 1]; /* format: (%02x:) * n - (1x ':') + (1x NULL) */
    int i;

    for (i = 0; i < in.EVCCID.bytesLen; i++) {
        sprintf(&buffer[i * 3], "%02" "X" ":", in.EVCCID.bytes[i]);
    }
    if (i)
        buffer[i * 3 - 1] = '\0';
    else
        buffer[0] = '\0';

    out.evccid = std::string(buffer).size() ? buffer : "(zero length provided)";

}

template <> void convert(const SessionSetupResponse& in, iso2_SessionSetupResType& out) {
    init_iso2_SessionSetupResType(&out);

    //RDB - The response codes apparently have changed completely between iso2 and iso20
    cb_convert_enum(in.response_code, out.ResponseCode);

    CPP2CB_STRING(in.evseid, out.EVSEID);

    //RDB - ISO2 separates the header and the body, so we don't convert the header here, do it in the serialize_to_exi instead.
    //convert(in.header, out.Header);
}


template <> void insert_type(VariantAccess& va, const struct iso2_SessionSetupReqType& in) {
    va.insert_type<SessionSetupRequest>(in);
};


template <> int serialize_to_exi(const SessionSetupResponse& in, exi_bitstream_t& out) {
    iso2_exiDocument doc;
    init_iso2_exiDocument(&doc);
    
    //RDB this is new in ISO2
    init_iso2_BodyType(&doc.V2G_Message.Body);

    //RDB Convert the header since it is separate in ISO2.
    convert(in.header, doc.V2G_Message.Header);

    //RDB now the body.
    CB_SET_USED(doc.V2G_Message.Body.SessionSetupRes);
    convert(in, doc.V2G_Message.Body.SessionSetupRes);

    return encode_iso2_exiDocument(&out, &doc);
}

template <> size_t serialize(const SessionSetupResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_2