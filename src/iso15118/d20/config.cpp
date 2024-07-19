// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/config.hpp>

namespace iso15118::d20 {

SessionConfig::SessionConfig() {

    dc_parameter_list = {{
        message_20::DcConnector::Extended,
        message_20::ControlMode::Scheduled,
        message_20::MobilityNeedsMode::ProvidedByEvcc,
        message_20::Pricing::NoPricing,
    }};

    dc_bpt_parameter_list = {{{
                                  message_20::DcConnector::Extended,
                                  message_20::ControlMode::Scheduled,
                                  message_20::MobilityNeedsMode::ProvidedByEvcc,
                                  message_20::Pricing::NoPricing,
                              },
                              message_20::BptChannel::Unified,
                              message_20::GeneratorMode::GridFollowing}};
}

} // namespace iso15118::d20
