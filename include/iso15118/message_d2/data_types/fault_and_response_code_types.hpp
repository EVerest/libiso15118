// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

namespace iso15118::message_d2::data_types {

enum class fault_code_type {
    ParsingError,
    NoTLSRootCertificatAvailable,
    UnknownError
};

enum class response_code_type {
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
    FAILED_CertificateRevoked
};

} // namespace iso15118::message_d2::data_types