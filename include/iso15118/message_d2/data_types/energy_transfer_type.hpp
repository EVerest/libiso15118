// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#pragma once

namespace iso15118::message_d2::data_types {

enum class energy_transfer_mode_type {
    AC_single_phase_core,
    AC_three_phase_core,
    DC_core,
    DC_extended,
    DC_combo_core,
    DC_unique
};

}
