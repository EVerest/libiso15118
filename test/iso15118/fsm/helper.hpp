// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <optional>

#include <iso15118/detail/cb_exi.hpp>
#include <iso15118/io/sdp.hpp>
#include <iso15118/io/stream_view.hpp>
#include <iso15118/message_d20/variant.hpp>
#include <iso15118/session/feedback.hpp>
#include <iso15118/states/config.hpp>
#include <iso15118/states/control_event.hpp>
#include <iso15118/states/fsm.hpp>

using namespace iso15118;

class FsmStateHelper {
public:
    FsmStateHelper(const states::SessionConfig& config) :
        log(this), ctx(msg_exch, active_control_event, callbacks, session_stopped, log, config, active_protocol){};

    states::Context& get_context();

    template <typename RequestType, typename StateType>
    fsm::states::HandleEventResult handle_request(StateType& state, io::v2gtp::PayloadType payload_type,
                                                  const RequestType& request) {
        const auto encoded_size = message_20::serialize_helper(request, output_stream_view);

        msg_exch.set_request(std::make_unique<message_20::Variant>(payload_type, output_stream_view));

        return state.handle_event(state_allocator, states::FsmEvent::V2GTP_MESSAGE);
    }

    template <typename StateType> bool next_simple_state_is() {
        auto new_state_ptr = state_allocator_impl.pull_simple_state<states::FsmSimpleState>();

        return (nullptr != dynamic_cast<StateType*>(new_state_ptr));
    }

    template <typename StateType>
    fsm::states::HandleEventResult handle_control_event(StateType& state, const states::ControlEvent& event) {
        active_control_event = event;

        return state.handle_event(state_allocator, states::FsmEvent::CONTROL_MESSAGE);
    }

private:
    uint8_t output_buffer[1024];
    io::StreamOutputView output_stream_view{output_buffer, sizeof(output_buffer)};

    states::MessageExchange msg_exch{output_stream_view};
    std::optional<states::ControlEvent> active_control_event;

    session::feedback::Callbacks callbacks;
    session::SessionLogger log;
    bool session_stopped{false};

    states::SessionProtocol active_protocol{states::SessionProtocol::ISO15118_20};

    states::Context ctx;

    fsm::_impl::DynamicStateAllocator state_allocator_impl;
    fsm::states::StateAllocator<void> state_allocator{state_allocator_impl};
};
