// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <array>
#include <cstdint>
#include <optional>
#include <string>
#include <variant>
#include <vector>

namespace iso15118::message_20 {

template <typename InType, typename OutType> void convert(const InType&, OutType&);

template <typename T> constexpr auto to_underlying_value(T t) {
    return static_cast<std::underlying_type_t<T>>(t);
}

namespace datatypes {

using PercentValue = uint8_t;    // [0 - 100]
using NumericId = uint32_t;      // [1 - 4294967295]
using Identifier = std::string;  // MaxLength: 255
using Name = std::string;        // MaxLength: 80
using Description = std::string; // MaxLength: 160

static constexpr auto SESSION_ID_LENGTH = 8;
using SessionId = std::array<uint8_t, SESSION_ID_LENGTH>;

using MeterId = std::string;        // MaxLength: 32
using MeterSignature = std::string; // Base64 encoded, MaxLength: 64

static constexpr auto GEN_CHALLENGE_LENGTH = 16;
using GenChallenge = std::array<uint8_t, GEN_CHALLENGE_LENGTH>; // Base64 encoded, MaxLength: 16

using Certificate = std::string;                 // Base64 encoded, MaxLength: 1600
using SubCertificate = std::vector<Certificate>; // Max: 3

enum class ResponseCode {
    OK = 0,
    OK_CertificateExpiresSoon = 1,
    OK_NewSessionEstablished = 2,
    OK_OldSessionJoined = 3,
    OK_PowerToleranceConfirmed = 4,
    WARNING_AuthorizationSelectionInvalid = 5,
    WARNING_CertificateExpired = 6,
    WARNING_CertificateNotYetValid = 7,
    WARNING_CertificateRevoked = 8,
    WARNING_CertificateValidationError = 9,
    WARNING_ChallengeInvalid = 10,
    WARNING_EIMAuthorizationFailure = 11,
    WARNING_eMSPUnknown = 12,
    WARNING_EVPowerProfileViolation = 13,
    WARNING_GeneralPnCAuthorizationError = 14,
    WARNING_NoCertificateAvailable = 15,
    WARNING_NoContractMatchingPCIDFound = 16,
    WARNING_PowerToleranceNotConfirmed = 17,
    WARNING_ScheduleRenegotiationFailed = 18,
    WARNING_StandbyNotAllowed = 19,
    WARNING_WPT = 20,
    FAILED = 21,
    FAILED_AssociationError = 22,
    FAILED_ContactorError = 23,
    FAILED_EVPowerProfileInvalid = 24,
    FAILED_EVPowerProfileViolation = 25,
    FAILED_MeteringSignatureNotValid = 26,
    FAILED_NoEnergyTransferServiceSelected = 27,
    FAILED_NoServiceRenegotiationSupported = 28,
    FAILED_PauseNotAllowed = 29,
    FAILED_PowerDeliveryNotApplied = 30,
    FAILED_PowerToleranceNotConfirmed = 31,
    FAILED_ScheduleRenegotiation = 32,
    FAILED_ScheduleSelectionInvalid = 33,
    FAILED_SequenceError = 34,
    FAILED_ServiceIDInvalid = 35,
    FAILED_ServiceSelectionInvalid = 36,
    FAILED_SignatureError = 37,
    FAILED_UnknownSession = 38,
    FAILED_WrongChargeParameter = 39
};

enum class Processing {
    Finished = 0,
    Ongoing = 1,
    Ongoing_WaitingForCustomerInteraction = 2,
};

enum class Authorization {
    EIM = 0,
    PnC = 1,
};

enum class ServiceCategory : uint16_t {
    AC = 1,
    DC = 2,
    WPT = 3,
    DC_ACDP = 4,
    AC_BPT = 5,
    DC_BPT = 6,
    DC_ACDP_BPT = 7,
    MCS = 8,
    MCS_BPT = 9,
    AC_DER = 10,
    Internet = 65,
    ParkingStatus = 66,
};

enum class EvseNotification {
    Pause,
    ExitStandby,
    Terminate,
    ScheduleRenegotiation,
    ServiceRenegotiation,
    MeteringConfirmation,
};

enum class ChargingSession {
    Pause,
    Terminate,
    ServiceRenegotiation,
};

enum class AcConnector {
    SinglePhase = 1,
    ThreePhase = 3,
};
enum class DcConnector {
    Core = 1,
    Extended = 2,
    Dual2 = 3,
    Dual4 = 4,
};
enum class McsConnector {
    Mcs = 1,
    Chaoji = 2,
    UltraChaoji = 3,
    rMcs = 4,
    xMcs = 5,
    Aviation = 6,
    Marine = 7,
};

enum class ControlMode {
    Scheduled = 1,
    Dynamic = 2,
};
enum class MobilityNeedsMode {
    ProvidedByEvcc = 1,
    ProvidedBySecc = 2,
};
enum class Pricing {
    NoPricing = 0,
    AbsolutePricing = 1,
    PriceLevels = 2,
};

enum class BptChannel {
    Unified = 1,
    Separated = 2,
};

enum class GeneratorMode {
    GridFollowing = 1,
    GridForming = 2,
};

enum class GridCodeIslandingDetectionMethod {
    Active = 1,
    Passive = 2,
};

enum class Protocol {
    Ftp,
    Http,
    Https,
};

enum class Port {
    Port20 = 20,
    Port21 = 21,
    Port80 = 80,
    Port443 = 443,
};

enum class IntendedService {
    VehicleCheckIn = 1,
    VehicleCheckOut = 2,
};

enum class ParkingStatus {
    AutoInternal = 1,
    AutoExternal = 2,
    ManualInternal = 3,
    ManualExternal = 4,
};

enum class PowerDuringCessation {
    ActivePower,
    ReactivePower,
};

enum class CurveDataPointsUnit {
    V,
    Hz,
    W,
    s,
    var,
    PercentageMaximumConfiguredDischargePower,
    PercentageMaximumConfiguredDischargeReactivePower,
    PercentageMaximumAvailableChargePower,
    PercentageMaximumConfiguredChargeReactivePower,
    PercentageMaximumAvailableDischargePower,
    PercentageMaximumAvailableDischargeReactivePower,
};

enum class LockValueUnit {
    V,
    Hz,
    W,
    s,
    var,
};

enum class PowerFactorExcitation {
    OverExcited,
    UnderExcited
};

enum class PowerReference {
    MaximumDischargePower,
    PresentActivePower
};

struct RationalNumber {
    int16_t value{0};
    int8_t exponent{0};
};

struct EvseStatus {
    uint16_t notification_max_delay;
    EvseNotification notification;
};

struct AcParameterList {
    AcConnector connector;
    ControlMode control_mode;
    MobilityNeedsMode mobility_needs_mode;
    uint32_t evse_nominal_voltage;
    Pricing pricing;
};

struct AcBptParameterList : AcParameterList {
    BptChannel bpt_channel;
    GeneratorMode generator_mode;
    GridCodeIslandingDetectionMethod grid_code_detection_method;
};

struct DcParameterList {
    DcConnector connector;
    ControlMode control_mode;
    MobilityNeedsMode mobility_needs_mode;
    Pricing pricing;
};

struct DcBptParameterList : DcParameterList {
    BptChannel bpt_channel;
    GeneratorMode generator_mode;
};

struct McsParameterList {
    McsConnector connector;
    ControlMode control_mode;
    MobilityNeedsMode mobility_needs_mode;
    Pricing pricing;
};

struct McsBptParameterList : McsParameterList {
    BptChannel bpt_channel;
    GeneratorMode generator_mode;
};

struct InternetParameterList {
    Protocol protocol;
    Port port;
};

struct ParkingParameterList {
    IntendedService intended_service;
    ParkingStatus parking_status;
};

struct Scheduled_CLReqControlMode {
    std::optional<RationalNumber> target_energy_request;
    std::optional<RationalNumber> max_energy_request;
    std::optional<RationalNumber> min_energy_request;
};

struct Dynamic_CLReqControlMode {
    std::optional<uint32_t> departure_time;
    RationalNumber target_energy_request;
    RationalNumber max_energy_request;
    RationalNumber min_energy_request;
};

struct Scheduled_CLResControlMode {};

struct Dynamic_CLResControlMode {
    std::optional<uint32_t> departure_time;
    std::optional<uint8_t> minimum_soc;
    std::optional<uint8_t> target_soc;
    std::optional<uint16_t> ack_max_delay;
};

struct PowerScheduleEntry {
    uint32_t duration;
    RationalNumber power;
    std::optional<RationalNumber> power_l2;
    std::optional<RationalNumber> power_l3;
};

struct MeterInfo {
    MeterId meter_id;
    uint64_t charged_energy_reading_wh;
    std::optional<uint64_t> bpt_discharged_energy_reading_wh;
    std::optional<uint64_t> capacitive_energy_reading_varh;
    std::optional<uint64_t> bpt_inductive_energy_reading_varh;
    std::optional<MeterSignature> meter_signature;
    std::optional<int16_t> meter_status;
    std::optional<uint64_t> meter_timestamp;
};

struct DisplayParameters {
    std::optional<PercentValue> present_soc;
    std::optional<PercentValue> min_soc;
    std::optional<PercentValue> target_soc;
    std::optional<PercentValue> max_soc;
    std::optional<uint32_t> remaining_time_to_min_soc;
    std::optional<uint32_t> remaining_time_to_target_soc;
    std::optional<uint32_t> remaining_time_to_max_soc;
    std::optional<bool> charging_complete;
    std::optional<RationalNumber> battery_energy_capacity;
    std::optional<bool> inlet_hot;
};

struct DetailedCost {
    RationalNumber amount;
    RationalNumber cost_per_unit;
};

struct DetailedTax {
    NumericId tax_rule_id;
    RationalNumber amount;
};

struct Receipt {
    uint64_t time_anchor;
    std::optional<DetailedCost> energy_costs;
    std::optional<DetailedCost> occupancy_costs;
    std::optional<DetailedCost> additional_service_costs;
    std::optional<DetailedCost> overstay_costs;
    std::vector<DetailedTax> tax_costs; // 0 to 10 elements! // FIXME(sl): optional?
};

struct X509IssuerSerial {
    std::string issuer_name;
    int64_t serial_number;
};

struct ListOfRootCertificateIDs {
    std::vector<X509IssuerSerial> root_certificate_id;
};

// TODO(sl): Adding content to following structs
struct SignedInfo {};
struct SignatureValue {};
struct KeyInfo {};
struct Object {};

struct Signature {
    SignedInfo signed_info;
    SignatureValue signature;
    std::optional<KeyInfo> key_info;
    std::optional<Object> object;
    std::optional<std::string> id;
};

struct ContractCertificateChain {
    Certificate certificate;
    SubCertificate sub_certificates;
};

struct ThreePhase {
    RationalNumber phase_l1;
    RationalNumber phase_l2;
    RationalNumber phase_l3;
};

struct Phase {
    RationalNumber any_phase;
    ThreePhase three_phase;
};

struct DataTuple {
    RationalNumber x;
    RationalNumber y;
};

struct DERCurve {
    std::optional<bool> enable;
    std::optional<uint16_t> priority;
    CurveDataPointsUnit x_unit;
    CurveDataPointsUnit y_unit;
    std::vector<DataTuple> curve_data_points;
    std::optional<LockValueUnit> lock_in_value;
    std::optional<LockValueUnit> lock_out_value;
    std::optional<RationalNumber> open_loop_response_time;
    std::optional<int32_t> time_constant_pt1;
    std::optional<RationalNumber> intentional_delay;
};

struct VoltageTrip {
    DERCurve over_voltage_must_trip_curve;
    DERCurve under_voltage_must_trip_curve;
    DERCurve over_voltage_momentary_cessation_trip_curve;
    DERCurve under_voltage_momentary_cessation_trip_curve;
    std::optional<DERCurve> over_voltage_may_trip_curve;
    std::optional<DERCurve> under_voltage_max_trip_curve;
    std::optional<RationalNumber> over_voltage_mean_value_10min;
    std::optional<RationalNumber> over_voltage_10_min_mean_triple_delay;
    std::optional<PowerDuringCessation> power_during_cessation;
};

struct FrequencyTrip {
    DERCurve over_frequency_must_trip_curve;
    DERCurve under_frequency_must_trip_curve;
    std::optional<DERCurve> over_frequency_may_trip_curve;
    std::optional<DERCurve> under_frequency_may_trip_curve;
};

struct DeadBand {
    RationalNumber mid_low;
    RationalNumber mid_high;
    std::optional<RationalNumber> low;
    std::optional<RationalNumber> high;
};

struct FaultRideThrough {
    std::optional<RationalNumber> over_voltage_ride_through_positive_curve_k_factor;
    std::optional<RationalNumber> oder_voltage_ride_through_negative_curve_k_factor;
    std::optional<RationalNumber> under_voltage_ride_through_positive_curve_k_factor;
    std::optional<RationalNumber> under_voltage_ride_through_negative_curve_k_factor;
    std::optional<DeadBand> dead_band;
};

struct EnterService {
    std::optional<bool> permit_service;
    RationalNumber voltage_high;
    RationalNumber voltage_low;
    RationalNumber frequency_high;
    RationalNumber frequency_low;
    RationalNumber delay;
    RationalNumber randomized_delay;
    RationalNumber ramp_time;
    std::optional<RationalNumber> gradient;
};

struct ConstantPowerFactor {
    std::optional<bool> enable;
    std::optional<uint16_t> priority;
    RationalNumber power_factor_value;
    PowerFactorExcitation power_factor_excitation;
};

struct ConstantVar {
    std::optional<bool> enable;
    std::optional<uint16_t> priority;
    RationalNumber set_point;
    CurveDataPointsUnit unit;
};

struct ReactivePowerSupport {
    std::optional<ConstantPowerFactor> constant_power_factor;
    std::optional<DERCurve> volt_var;
    std::optional<DERCurve> watt_var;
    std::optional<ConstantVar> constant_var;
    std::optional<DERCurve> watt_cos_phi;
};

struct HysteresisControl {
    RationalNumber f_stop;
    uint16_t power_up_ramp;
    std::optional<RationalNumber> intentional_delay_f_stop;
};

struct EuFrequencyDroopSettings {
    RationalNumber f_start;
    RationalNumber s;
    std::optional<RationalNumber> deactivation_time;
    std::optional<RationalNumber> intentional_delay_power_control;
    PowerReference power_reference;
    std::optional<HysteresisControl> hysteresis_control;
    std::optional<RationalNumber> max_reaction_time;
};

struct UsFrequencyDroopSettings {
    RationalNumber db;
    RationalNumber k;
    PowerReference power_reference;
    std::optional<RationalNumber> open_loop_response_time;
};

struct FrequencyDroop {
    std::optional<bool> enable;
    std::optional<uint16_t> priority;
};

struct EuFrequencyDroop : FrequencyDroop {
    std::optional<EuFrequencyDroopSettings> over_frequency_droop;
    std::optional<EuFrequencyDroopSettings> under_frequency_droop;
};

struct UsFrequencyDroop : FrequencyDroop {
    std::optional<UsFrequencyDroopSettings> over_frequency_droop;
    std::optional<UsFrequencyDroopSettings> under_frequency_droop;
};

struct FrequencyWattCurve {
    std::optional<bool> enable;
    std::optional<uint16_t> priority;
    CurveDataPointsUnit x_unit;
    CurveDataPointsUnit y_unit;
    std::vector<DataTuple> curve_data_points;
    std::optional<RationalNumber> open_loop_response_time;
    std::optional<RationalNumber> hysteresis_high;
    std::optional<RationalNumber> hysteresis_low;
    std::optional<RationalNumber> hysteresis_delay;
    std::optional<RationalNumber> hysteresis_gradient;
};

struct LimitMaxDischargePower {
    std::optional<bool> enable;
    std::optional<uint16_t> priority;
    uint16_t percentage_value;
    std::optional<DERCurve> power_monitoring_must_trip_curve;
};

struct ActivePowerSupport {
    std::optional<std::variant<EuFrequencyDroop, UsFrequencyDroop>> frequency_droop;
    std::optional<FrequencyWattCurve> frequency_watt;
    std::optional<DERCurve> volt_watt;
    std::optional<LimitMaxDischargePower> limit_max_discharge_power;
};

struct DERControl {
    std::optional<VoltageTrip> voltage_trip;
    std::optional<FrequencyTrip> frequency_trip;
    std::optional<FaultRideThrough> fault_ride_through;
    std::optional<EnterService> enter_service;
    std::optional<ReactivePowerSupport> reactive_power_support;
    std::optional<ActivePowerSupport> active_power_support;
    std::optional<RationalNumber> max_level_1_dc_injection;
    std::optional<RationalNumber> max_level_2_dc_injection;
    std::optional<RationalNumber> sc_rat_poc;
};

float from_RationalNumber(const RationalNumber& in);
RationalNumber from_float(float in);

std::string from_Protocol(const Protocol& in);

std::string from_control_mode(const ControlMode& in);
std::string from_mobility_needs_mode(const MobilityNeedsMode& in);

} // namespace datatypes

struct Header {
    datatypes::SessionId session_id{};
    uint64_t timestamp;
    // std::optional<datatypes::Signature> signature;
};

template <typename cb_HeaderType> void convert(const cb_HeaderType& in, Header& out);

template <typename cb_RationalNumberType> void convert(const cb_RationalNumberType& in, datatypes::RationalNumber& out);
template <typename cb_RationalNumberType> void convert(const datatypes::RationalNumber& in, cb_RationalNumberType& out);

} // namespace iso15118::message_20
