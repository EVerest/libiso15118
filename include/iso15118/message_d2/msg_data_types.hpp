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

// Simple types

// general types
using percent_value_type = uint8_t; // range 0-100

using fault_msg_type = std::string; // max length 64

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

using service_name_type = std::string; // max length 32

using service_scope_type = std::string; // max length 64

using max_num_phases_type = uint8_t; // range 1-3

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
using tariff_description_type = std::string; // max length 32

enum class CostKind {
    relative_price_percentage,
    renewable_generation_percentage,
    carbon_dioxide_emission
};

struct PaymentOptionList {
    std::vector<std::string> payment_option; // paymentOptionType, minOccurs=1, maxOccurs=2
};

enum class PaymentOption {
    Contract,
    ExternalPayment
};

// fault and response code types
enum class FaultCode {
    ParsingError,
    NoTLSRootCertificatAvailable,
    UnknownError
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
    FAILED_CertificateRevoked
};

// identification_number types
using session_id_type = std::string; // hexBinary, max length 8

constexpr auto EVCC_ID_LENGTH = 6;

using evcc_id_type = std::array<uint8_t, EVCC_ID_LENGTH>; // hexBinary, max length 6

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

// charging profile types
struct ProfileEntry {
    uint64_t charging_profile_entry_start;
    PhysicalValue charging_profile_entry_max_power;
    std::optional<max_num_phases_type> charging_profile_entry_max_number_of_phases_in_use; // minOccurs="0"
};

struct ChargingProfile {
    std::vector<ProfileEntry> profile_entry; // maxOccurs="24"
};

// ev evse related types
struct EvseStatus {
    uint16_t notification_max_delay;
    EvseNotification evse_notification;
    virtual ~EvseStatus() = default; // To ensure polymorphic behavior
};

struct AcEvseStatus : public EvseStatus {
    bool rcd;
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

// ev power delivery related types
struct EvPowerDeliveryParameter {
    virtual ~EvPowerDeliveryParameter() = default; // To ensure polymorphic behavior
};

struct DcEvPowerDeliveryParameter : public EvPowerDeliveryParameter {
    DcEvStatus dc_ev_status;
    std::optional<bool> bulk_charging_complete; // minOccurs="0"
    bool charging_complete;
};

// evse ev charge paramter related types
struct EvChargeParameter {
    std::optional<uint64_t> departure_time; // minOccurs="0"
    virtual ~EvChargeParameter() = default; // To ensure polymorphic behavior
};

struct AcEvChargeParameter : public EvChargeParameter {
    PhysicalValue e_amount;
    PhysicalValue ev_max_voltage;
    PhysicalValue ev_max_current;
    PhysicalValue ev_min_current;
};

struct DcEvChargeParameter : public EvChargeParameter {
    DcEvStatus dc_ev_status;
    PhysicalValue ev_maximum_current_limit;
    std::optional<PhysicalValue> ev_maximum_power_limit; // minOccurs="0"
    PhysicalValue ev_maximum_voltage_limit;
    std::optional<PhysicalValue> ev_energy_capacity; // minOccurs="0"
    std::optional<PhysicalValue> ev_energy_request;  // minOccurs="0"
    std::optional<percent_value_type> full_soc;      // minOccurs="0"
    std::optional<percent_value_type> bulk_soc;      // minOccurs="0"
};

struct EvseChargeParameter {
    virtual ~EvseChargeParameter() = default; // To ensure polymorphic behavior
};

struct AcEvseChargeParameter : public EvseChargeParameter {
    AcEvseStatus ac_evse_status;
    PhysicalValue evse_nominal_voltage;
    PhysicalValue evse_max_current;
};

struct DcEvseChargeParameter : public EvseChargeParameter {
    DcEvseStatus dc_evse_status;
    PhysicalValue evse_maximum_current_limit;
    PhysicalValue evse_maximum_power_limit;
    PhysicalValue evse_maximum_voltage_limit;
    PhysicalValue evse_minimum_current_limit;
    PhysicalValue evse_minimum_voltage_limit;
    std::optional<PhysicalValue> evse_current_regulation_tolerance; // minOccurs="0"
    PhysicalValue evse_peak_current_ripple;
    std::optional<PhysicalValue> evse_energy_to_be_delivered; // minOccurs="0"
};

// header related types
struct Notification {
    FaultCode fault_code;
    std::optional<fault_msg_type> fault_msg;
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
using emaid_type = id_type;

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

// service related types
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

struct ServiceList {
    std::vector<data_types::Service> service; // maxOccurs="8"
};

// tariff related types
struct Entry {
    virtual ~Entry() = default; // To ensure polymorphic behavior
};

struct SaSchedules {
    virtual ~SaSchedules() = default; // To ensure polymorphic behavior
};

struct Cost {
    CostKind cost_kind;
    uint64_t amount;
    std::optional<unit_multiplier_type> amount_multiplier; // minOccurs="0"
};

struct ConsumptionCost {
    PhysicalValue start_value;
    std::vector<Cost> cost; // maxOccurs="3"
};

struct SalesTariffEntry : public Entry {
    std::optional<uint8_t> e_price_level;          // minOccurs="0"
    std::vector<ConsumptionCost> consumption_cost; // minOccurs="0", maxOccurs="3"
};

struct PmaxScheduleEntry : public Entry {
    PhysicalValue pmax;
};

struct PmaxSchedule {
    std::vector<PmaxScheduleEntry> pmax_schedule_entry; // maxOccurs="1024"
};

struct SalesTariff {
    sa_id_type sales_tariff_id;
    std::optional<tariff_description_type> sales_tariff_description; // minOccurs="0"
    std::optional<uint8_t> num_e_price_levels;                       // minOccurs="0"
    std::vector<SalesTariffEntry> sales_tariff_entry;                // maxOccurs="1024"
    id_type id;
};

struct SaScheduleTuple {
    sa_id_type sa_schedule_tuple_id;
    PmaxSchedule pmax_schedule;
    std::optional<SalesTariff> sales_tariff; // minOccurs="0"
};

struct SaScheduleList : public SaSchedules {
    std::vector<SaScheduleTuple> sa_schedule_tuple; // maxOccurs="3"
};

struct Interval {
    virtual ~Interval() = default; // To ensure polymorphic behavior
};

struct RelativeTimeInterval : public Interval {
    uint64_t start;
    std::optional<uint64_t> duration; // minOccurs="0"
};
} // namespace iso15118::message_2::data_types