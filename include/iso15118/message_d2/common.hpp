// SPDX-License-Identifier: Apache-2.0
// Copyright 2024 Pionix GmbH and Contributors to EVerest
#pragma once

#include <array>
#include <cstdint>
#include <optional>
#include <string>

namespace iso15118::message_2 {

const uint8_t SESSION_ID_LENGTH = 8;

enum class FaultCode {
    ParsingError,
    NoTLSRootCertificatAvailable,
    UnknownError,
};

struct Notification {
    FaultCode fault_code;
    std::optional<std::string> fault_message;
};

struct Header {
    std::array<uint8_t, SESSION_ID_LENGTH> session_id{};
    std::optional<Notification> notification;
    // std::optional<> signature; // Todo(sl)
};

enum class ResponseCode {
    OK,
    OK_NewSessionEstablished,
    OK_OldSessionJoined,
    OK_CertificateExpiresSoon,
    FAILED,
    FAILED_SequenceError,
    FAILED_ServiceIDInvalid,
    FAILED_UnknownSession,
    FAILED_ServiceSelectionInvalid,
    FAILED_PaymentSelectionInvalid,
    FAILED_CertificateExpired,
    FAILED_SignatureError,
    FAILED_NoCertificateAvailable,
    FAILED_CertChainError,
    FAILED_ChallengeInvalid,
    FAILED_ContractCanceled,
    FAILED_WrongChargeParameter,
    FAILED_PowerDeliveryNotApplied,
    FAILED_TariffSelectionInvalid,
    FAILED_ChargingProfileInvalid,
    FAILED_MeteringSignatureNotValid,
    FAILED_NoChargeServiceSelected,
    FAILED_WrongEnergyTransferMode,
    FAILED_ContactorError,
    FAILED_CertificateNotAllowedAtThisEVSE,
    FAILED_CertificateRevoked,
};

} // namespace iso15118::message_2
