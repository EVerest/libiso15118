#pragma once

#include <iso15118/message/common_types.hpp>

#include "cb_exi.hpp"

namespace iso15118::message_20 {

template <typename cb_HeaderType> void convert(const cb_HeaderType& in, Header& out);

template <typename cb_RationalNumberType> void convert(const cb_RationalNumberType& in, RationalNumber& out);
template <typename cb_RationalNumberType> void convert(const RationalNumber& in, cb_RationalNumberType& out);

float from_RationalNumber(const RationalNumber& in);
RationalNumber from_float(float in);

std::string from_Protocol(const Protocol& in);

} // namespace iso15118::message_20