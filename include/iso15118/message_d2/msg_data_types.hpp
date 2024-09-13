// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once
#include <array>
#include <cbv2g/iso_2/iso2_msgDefEncoder.h>
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace iso15118::message_2::data_types {

// general types
using percent_value_type = uint8_t; // range 0-100

enum class EvseProcessing {
    Finished,
    Ongoing,
    Ongoing_WaitingForCustomerInteraction
};

enum class EvseNotification {
    None,
    StopCharging,
    ReNegotiation
};

using meter_status_type = int16_t;

// energy transfer types
enum class EnergyTransferMode {
    AC_single_phase_core,
    AC_three_phase_core,
    DC_core,
    DC_extended,
    DC_combo_core,
    DC_unique
};

// tariffs and payment types
using sa_id_type = uint8_t;                  // unsignedByte, range 1-255

// response code types
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
    FAILED_CertificateRevoked
};

// identification_number types

using evse_id_type = std::string; // string, min length 7 max length 37

using service_id_type = uint16_t;  // unsignedShort
using emaid_type = std::string;    // string, min length 14, max length 15
using meter_id_type = std::string; // string, max length 32

// multiplier and unit types
using unit_multiplier_type = int8_t; // byte, range -3 to 3

enum class UnitSymbol {
    h, // Time in hours
    m, // Time in minutes
    s, // Time in seconds
    A, // Current in Ampere
    V, // Voltage in Volt
    W, // Active power in Watt
    Wh // Real energy in Watt hours
};

// only dc related types
enum class DcEvseStatusCode {
    EVSE_NotReady,
    EVSE_Ready,
    EVSE_Shutdown,
    EVSE_UtilityInterruptEvent,
    EVSE_IsolationMonitoringActive,
    EVSE_EmergencyShutdown,
    EVSE_Malfunction,
    Reserved_8,
    Reserved_9,
    Reserved_A,
    Reserved_B,
    Reserved_C
};

enum class IsolationLevel {
    Invalid,
    Valid,
    Warning,
    Fault,
    No_IMD
};

enum class DcEvErrorCode {
    NO_ERROR,
    FAILED_RESSTemperatureInhibit,
    FAILED_EVShiftPosition,
    FAILED_ChargerConnectorLockFault,
    FAILED_EVRESSMalfunction,
    FAILED_ChargingCurrentdifferential,
    FAILED_ChargingVoltageOutOfRange,
    Reserved_A,
    Reserved_B,
    Reserved_C,
    FAILED_ChargingSystemIncompatibility,
    NoData
};

// security types
using gen_challenge_type = std::string;     // base64Binary, length 16
using certificate_type = std::string;       // base64Binary, max length 800
using dh_publickey_type = std::string;      // base64Binary, max length 65
using private_key_type = std::string;       // base64Binary, max length 48
using sig_meter_reading_type = std::string; // base64Binary, max length 64

// complex types

// physical value types
inline const auto convertUnitSymbol = [](iso2_unitSymbolType iso2Unit) {
    switch (iso2Unit) {
    case iso2_unitSymbolType_h:
        return UnitSymbol::h;
    case iso2_unitSymbolType_m:
        return UnitSymbol::m;
    case iso2_unitSymbolType_s:
        return UnitSymbol::s;
    case iso2_unitSymbolType_A:
        return UnitSymbol::A;
    case iso2_unitSymbolType_V:
        return UnitSymbol::V;
    case iso2_unitSymbolType_W:
        return UnitSymbol::W;
    case iso2_unitSymbolType_Wh:
        return UnitSymbol::Wh;
    default:
        throw std::runtime_error("Unsupported unit symbol");
    }
};

struct PhysicalValue {
    unit_multiplier_type multiplier;
    UnitSymbol unit;
    short value;

    inline PhysicalValue& operator=(const iso2_PhysicalValueType& rhs) {
        multiplier = rhs.Multiplier;
        value = rhs.Value;
        unit = convertUnitSymbol(rhs.Unit);
        return *this;
    };
};

// ev evse related types
struct EvseStatus {
    uint16_t notification_max_delay;
    EvseNotification evse_notification;
    virtual ~EvseStatus() = default; // To ensure polymorphic behavior
};

struct EvStatus {
    virtual ~EvStatus() = default; // To ensure polymorphic behavior
};

struct DcEvseStatus : public EvseStatus {
    std::optional<IsolationLevel> evse_isolation_status; // minOccurs="0"
    DcEvseStatusCode evse_status_code;
};

struct DcEvStatus : public EvStatus {
    bool ev_ready;
    DcEvErrorCode ev_error_code;
    percent_value_type ev_ress_soc;
};

// metering related types
struct MeterInfo {
    meter_id_type meter_id;
    std::optional<uint64_t> meter_reading;
    std::optional<sig_meter_reading_type> sig_meter_reading;
    std::optional<meter_status_type> meter_status;
    std::optional<int64_t> t_meter;
};

// security related types
using id_type = std::string;

struct X509IssuerSerial {
    std::string x509_issuer_name;
    int64_t x509_serial_number;
};

struct ContractSignatureEncryptedPrivateKey {
    private_key_type value;
    id_type id;
};

struct DiffieHellmanPublickey {
    dh_publickey_type value;
    id_type id;
};

struct SubCertificates {
    std::vector<certificate_type> certificate; // maxOccurs="4"
};

struct CertificateChain {
    certificate_type certificate;
    std::optional<SubCertificates> sub_certificates; // minOccurs="0"
    id_type id;
};

struct ListOfRootCertificateIds {
    std::vector<X509IssuerSerial> root_certificate_id; // maxOccurs="20"
};

} // namespace iso15118::message_2::data_types