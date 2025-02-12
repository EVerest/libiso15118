// SPDX-License-Identifier: Apache-2.0
// Copyright 2025 Pionix GmbH and Contributors to EVerest
#include <iso15118/d20/state/ac_charge_loop.hpp>

#include <iso15118/detail/d20/context_helper.hpp>
#include <iso15118/detail/d20/state/power_delivery.hpp>
#include <iso15118/detail/helper.hpp>

namespace iso15118::d20::state {

namespace dt = message_20::datatypes;

void AC_ChargeLoop::enter() {
    m_ctx.log.enter_state("AC_ChargeLoop");
}

Result AC_ChargeLoop::feed(Event ev) {

    // TODO(ioan, sl): see if this is required
    if (ev == Event::CONTROL_MESSAGE) {
        /*
        if (const auto* control_data = m_ctx.get_control_event<PresentVoltageCurrent>()) {
        } else if (const auto* control_data = m_ctx.get_control_event<StopCharging>()) {
        } else if (const auto* control_data = m_ctx.get_control_event<UpdateDynamicModeParameters>()) {
        }
        */

        // Ignore control message
        return {};
    }

    if (ev != Event::V2GTP_MESSAGE) {
        return {};
    }

    const auto variant = m_ctx.pull_request();

    if (const auto req = variant->get_if<message_20::PowerDeliveryRequest>()) {
        const auto res = handle_request(*req, m_ctx.session);

        m_ctx.respond(res);

        if (res.response_code >= dt::ResponseCode::FAILED) {
            m_ctx.session_stopped = true;
            return {};
        }

        // TODO(ioan, sl): see what is required here

        return {};
    } else if (const auto req = variant->get_if<message_20::AC_ChargeLoopRequest>()) {
        // TODO(ioan, sl): see what is required here

        /*
        const auto res = handle_request(*req, m_ctx.session, present_voltage, present_current, stop,
                                        m_ctx.session_config.dc_limits, dynamic_parameters);

        m_ctx.respond(res);

        if (res.response_code >= dt::ResponseCode::FAILED) {
            m_ctx.session_stopped = true;
            return {};
        }
        */

        return {};
    } else {
        m_ctx.log("Expected PowerDeliveryReq or AC_ChargeLoopRequest! But code type id: %d", variant->get_type());

        // Sequence Error
        const message_20::Type req_type = variant->get_type();
        send_sequence_error(req_type, m_ctx);

        m_ctx.session_stopped = true;
        return {};
    }
}

} // namespace iso15118::d20::state
