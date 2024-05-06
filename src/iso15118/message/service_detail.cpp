// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/message/service_detail.hpp>

#include <type_traits>

#include <iso15118/detail/variant_access.hpp>

#include <cbv2g/iso_20/iso20_CommonMessages_Encoder.h>

namespace iso15118::message_20 {

template <> void convert(const struct iso20_ServiceDetailReqType& in, ServiceDetailRequest& out) {
    convert(in.Header, out.header);
    out.service = static_cast<ServiceCategory>(in.ServiceID);
}

struct ParamterValueVisitor {
    ParamterValueVisitor(iso20_ParameterType& parameter_) : parameter(parameter_){};
    void operator()(const bool& in) {
        CB_SET_USED(parameter.boolValue);
        parameter.boolValue = in;
    }
    void operator()(const int8_t& in) {
        CB_SET_USED(parameter.byteValue);
        parameter.byteValue = in;
    }
    void operator()(const int16_t& in) {
        CB_SET_USED(parameter.shortValue);
        parameter.shortValue = in;
    }
    void operator()(const int32_t& in) {
        CB_SET_USED(parameter.intValue);
        parameter.intValue = in;
    }
    void operator()(const std::string& in) {
        CB_SET_USED(parameter.finiteString);
        CPP2CB_STRING(in, parameter.finiteString);
    }
    void operator()(const message_20::RationalNumber& in) {
        CB_SET_USED(parameter.rationalNumber);
        parameter.rationalNumber.Exponent = in.exponent;
        parameter.rationalNumber.Value = in.value;
    }

private:
    iso20_ParameterType& parameter;
};

template <> void convert(const ServiceDetailResponse& in, iso20_ServiceDetailResType& out) {
    init_iso20_ServiceDetailResType(&out);

    convert(in.header, out.Header);

    cb_convert_enum(in.response_code, out.ResponseCode);

    cb_convert_enum(in.service, out.ServiceID);

    uint8_t index = 0;
    for (auto const& in_parameter_set : in.service_parameter_list) {
        auto& out_paramater_set = out.ServiceParameterList.ParameterSet.array[index++];
        out_paramater_set.ParameterSetID = in_parameter_set.id;

        uint8_t t = 0;
        for (auto const in_parameter : in_parameter_set.parameters) {
            auto& out_parameter = out_paramater_set.Parameter.array[t++];
            CPP2CB_STRING(in_parameter.name, out_parameter.Name);
            std::visit(ParamterValueVisitor(out_parameter), in_parameter.value);
        }
        out_paramater_set.Parameter.arrayLen = in_parameter_set.parameters.size();
    }

    out.ServiceParameterList.ParameterSet.arrayLen = in.service_parameter_list.size();
}

template <> void insert_type(VariantAccess& va, const struct iso20_ServiceDetailReqType& in) {
    va.insert_type<ServiceDetailRequest>(in);
}

template <> int serialize_to_exi(const ServiceDetailResponse& in, exi_bitstream_t& out) {
    iso20_exiDocument doc;
    init_iso20_exiDocument(&doc);

    CB_SET_USED(doc.ServiceDetailRes);

    convert(in, doc.ServiceDetailRes);

    return encode_iso20_exiDocument(&out, &doc);
}

template <> size_t serialize(const ServiceDetailResponse& in, const io::StreamOutputView& out) {
    return serialize_helper(in, out);
}

} // namespace iso15118::message_20
