// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>
#include <vector>

#include "common.hpp"

namespace iso15118::message_2 {

// RDB Added from v2G.hpp of everest EVSEv2g
#define ServiceScope_CHARACTER_SIZE 65
typedef enum {
    serviceCategoryType_EVCharging = 0,
    serviceCategoryType_Internet = 1,
    serviceCategoryType_ContractCertificate = 2,
    serviceCategoryType_OtherCustom = 3
} serviceCategoryType;

/* ISO 15118 table 105 */
enum v2g_service {
    V2G_SERVICE_ID_CHARGING = 1,
    V2G_SERVICE_ID_CERTIFICATE = 2,
    V2G_SERVICE_ID_INTERNET = 3,
    V2G_SERVICE_ID_USECASEINFORMATION = 4,
};

typedef enum {
    paymentOptionType_Contract = 0,
    paymentOptionType_ExternalPayment = 1
} paymentOptionType;

struct ServiceDiscoveryRequest {
    Header header;
    // RDB ISO2 just ServiceScope and ServiceCategory instead of SupportedServiceIDs for filtering the response
    std::optional<std::vector<uint16_t>> supported_service_ids;
};

struct ServiceDiscoveryResponse {
    struct Service {
        ServiceCategory service_id;
        bool free_service;
    };

    // RDB Add Payment Options for ISO2
    struct PaymentOption {
        paymentOptionType payment_option;
    };

    Header header;
    ResponseCode response_code;
    bool service_renegotiation_supported = false;
    std::vector<Service> energy_transfer_service_list = {{
        ServiceCategory::AC, // service_id
        false                // free_service
    }};
    std::optional<std::vector<Service>> vas_list;

    // RDB Add the ISO2 payment option list
    std::optional<std::vector<PaymentOption>> payment_option_list;
};

} // namespace iso15118::message_2
