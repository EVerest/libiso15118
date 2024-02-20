// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include "helper.hpp"

iso15118::states::Context& FsmStateHelper::get_context() {
    return ctx;
}
