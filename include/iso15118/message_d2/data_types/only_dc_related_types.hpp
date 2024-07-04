// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

namespace iso15118::message_d2::data_types {

enum class dc_evse_status_code_type {
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

enum class isolation_level_type {
    Invalid,
    Valid,
    Warning,
    Fault,
    No_IMD
};

enum class dc_ev_error_code_type {
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

} // namespace iso15118::message_d2::data_types