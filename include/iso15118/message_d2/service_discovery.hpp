// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

namespace data_types {

using service_scope_type = std::string; // max length 64

struct SupportedEnergyTransferMode {
    std::vector<data_types::EnergyTransferMode> energy_transfer_mode; // maxOccurs="6"
};

enum class ServiceCategory {
    EVCharging,
    Internet,
    ContractCertificate,
    OtherCustom
};

struct Service {
    service_id_type service_id;
    std::string service_name; // minOccurs="0"
    ServiceCategory service_category;
    std::string service_scope; // minOccurs="0"
    bool free_service;
};

struct ChargeService : public data_types::Service {
    SupportedEnergyTransferMode supported_energy_transfer_mode;
};

struct PaymentOptionList {
    std::vector<std::string> payment_option; // paymentOptionType, minOccurs=1, maxOccurs=2
};

enum class PaymentOption {
    Contract,
    ExternalPayment
};

struct ServiceList {
    std::vector<data_types::Service> service; // maxOccurs="8"
};

} // namespace data_types

struct ServiceDiscoveryReq {
    V2GMessageHeader header;
    std::optional<data_types::service_scope_type> service_scope;
    std::optional<data_types::ServiceCategory> service_category;
};

struct ServiceDiscoveryRes {
    V2GMessageHeader header;
    data_types::ResponseCode response_code;
    data_types::PaymentOptionList payment_option_list;
    data_types::ChargeService charge_service;
    std::optional<data_types::ServiceList> service_list;
};

} // namespace iso15118::message_2