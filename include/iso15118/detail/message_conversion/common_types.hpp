#pragma once

#include <iso15118/message/common_types.hpp>

#include "cb_exi.hpp"

namespace iso15118::message_20 {

template <typename cb_HeaderType> void convert(const cb_HeaderType& in, Header& out);

template <typename cb_RationalNumberType> void convert(const cb_RationalNumberType& in, RationalNumber& out);
template <typename cb_RationalNumberType> void convert(const RationalNumber& in, cb_RationalNumberType& out);

template <typename InType> void convert(const InType& in, Dynamic_CLReqControlMode& out);
template <typename InType> void convert(const InType& in, Scheduled_CLReqControlMode& out);

template <typename cb_Type> void convert(const Dynamic_CLResControlMode& in, cb_Type& out);

template <typename T> struct ConversionVisitor;
template <typename T> ConversionVisitor(T&) -> ConversionVisitor<T>;

float from_RationalNumber(const RationalNumber& in);
RationalNumber from_float(float in);

std::string from_Protocol(const Protocol& in);

} // namespace iso15118::message_20