// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#pragma once

#include <iso15118/d20/fsm.hpp>
#include <iso15118/detail/cb_exi.hpp>
#include <iso15118/io/sdp.hpp>
#include <iso15118/io/stream_view.hpp>

class FsmStateHelper {
public:
    iso15118::d20::Context& get_context();

    template <typename RequestType, typename StateType>
    fsm::states::HandleEventResult handle_request(StateType& state, iso15118::io::v2gtp::PayloadType payload_type,
                                                  const RequestType& request) {
        const auto encoded_size = iso15118::message_20::serialize_helper(request, output_stream_view);

        msg_exch.set_request(payload_type, {output_buffer, encoded_size});

        return state.handle_event(state_allocator, iso15118::d20::FsmEvent::NEW_V2GTP_MESSAGE);
    }

    template <typename StateType> bool next_simple_state_is() {
        auto new_state_ptr = state_allocator_impl.pull_simple_state<iso15118::d20::FsmSimpleState>();

        return (nullptr != dynamic_cast<StateType*>(new_state_ptr));
    }

private:
    uint8_t output_buffer[1024];
    iso15118::io::StreamOutputView output_stream_view{output_buffer, sizeof(output_buffer)};

    iso15118::d20::MessageExchange msg_exch{output_stream_view};

    iso15118::d20::Context ctx{msg_exch};

    fsm::_impl::DynamicStateAllocator state_allocator_impl;
    fsm::states::StateAllocator<void> state_allocator{state_allocator_impl};
};
