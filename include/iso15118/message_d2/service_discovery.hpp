// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>

#include "iso15118/message_d2/msg_data_types.hpp"
#include "message_header.hpp"

namespace iso15118::message_2 {

namespace data_types {

struct SupportedEnergyTransferMode {
    std::vector<data_types::EnergyTransferMode> energy_transfer_mode; // maxOccurs="6"
};

struct ChargeService : public data_types::Service {
    SupportedEnergyTransferMode supported_energy_transfer_mode;
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