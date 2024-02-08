// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

// FIXME (aw): how to streamline this with type.hpp?

#include <iso15118/io/sdp.hpp>

namespace iso15118::message_2 {

template <typename T> struct PayloadTypeTrait;

//
// definitions of type traits
//
#ifdef CREATE_TYPE_TRAIT
#define CREATE_TYPE_TRAIT_PUSHED CREATE_TYPE_TRAIT
#endif

#define CREATE_TYPE_TRAIT(struct_name, payload_type)                                                                   \
    struct struct_name;                                                                                                \
    template <> struct PayloadTypeTrait<struct_name> {                                                                 \
        static const io::v2gtp::PayloadType type = io::v2gtp::PayloadType::payload_type;                                  \
    }

CREATE_TYPE_TRAIT(SupportedAppProtocolResponse, SAP);
//RDB ISO2 only uses 0x8001
CREATE_TYPE_TRAIT(SessionSetupResponse, SAP);
CREATE_TYPE_TRAIT(AuthorizationSetupResponse, Part20Main);
CREATE_TYPE_TRAIT(AuthorizationResponse, SAP);
CREATE_TYPE_TRAIT(ServiceDiscoveryResponse, SAP);
CREATE_TYPE_TRAIT(ServiceDetailResponse, Part20Main);
CREATE_TYPE_TRAIT(ServiceSelectionResponse, SAP);
CREATE_TYPE_TRAIT(DC_ChargeParameterDiscoveryResponse, SAP);
CREATE_TYPE_TRAIT(ScheduleExchangeResponse, Part20Main);
CREATE_TYPE_TRAIT(DC_CableCheckResponse, SAP);
CREATE_TYPE_TRAIT(DC_PreChargeResponse, SAP);
CREATE_TYPE_TRAIT(PowerDeliveryResponse, SAP);
CREATE_TYPE_TRAIT(DC_ChargeLoopResponse, SAP);
CREATE_TYPE_TRAIT(DC_WeldingDetectionResponse, SAP);
CREATE_TYPE_TRAIT(SessionStopResponse, SAP);

#ifdef CREATE_TYPE_TRAIT_PUSHED
#define CREATE_TYPE_TRAIT CREATE_TYPE_TRAIT_PUSHED
#else
#undef CREATE_TYPE_TRAIT
#endif

} // namespace iso15118::message_2
