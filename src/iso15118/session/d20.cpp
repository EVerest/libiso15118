// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/session/d20.hpp>

#include <cassert>
#include <cstring>
#include <memory>
#include <type_traits>

#include <iso15118/detail/helper.hpp>

#include <iso15118/message/supported_app_protocol.hpp>

// FIXME (aw): this should be moved into the controller, not here!
// only for testing now!!
#include <iso15118/d20/state/supported_app_protocol.hpp>

static void log_sdp_packet(const iso15118::io::SdpPacket& sdp) {
    static constexpr auto ESCAPED_BYTE_CHAR_COUNT = 4;
    auto payload_string_buffer = std::make_unique<char[]>(sdp.get_payload_length() * ESCAPED_BYTE_CHAR_COUNT + 1);
    for (auto i = 0; i < sdp.get_payload_length(); ++i) {
        snprintf(payload_string_buffer.get() + i * ESCAPED_BYTE_CHAR_COUNT, ESCAPED_BYTE_CHAR_COUNT + 1, "\\x%02hx",
                 sdp.get_payload_buffer()[i]);
    }

    iso15118::logf("[SDP Packet in]: Header: %04hx, Payload: %s", sdp.get_payload_type(), payload_string_buffer.get());
}

static size_t setup_response_header(uint8_t* buffer, iso15118::io::v2gtp::PayloadType payload_type, size_t size) {
    buffer[0] = iso15118::io::SDP_PROTOCOL_VERSION;
    buffer[1] = iso15118::io::SDP_INVERSE_PROTOCOL_VERSION;

    const uint16_t response_payload_type =
        htobe16(static_cast<std::underlying_type_t<iso15118::io::v2gtp::PayloadType>>(payload_type));

    std::memcpy(buffer + 2, &response_payload_type, sizeof(response_payload_type));

    const uint32_t tmp32 = htobe32(size);

    std::memcpy(buffer + 4, &tmp32, sizeof(tmp32));

    return size + iso15118::io::SdpPacket::V2GTP_HEADER_SIZE;
}

namespace iso15118::session {

D20Session::D20Session(io::SessionSSLServer server_) : server(std::move(server_)) {
    fsm.reset<d20::state::SupportedAppProtocol>(ctx);
}

int D20Session::handle_input() {
    using PacketState = io::SdpPacket::State;
    using ReadState = io::ReadResult::State;

    while (true) {
        const auto result =
            server.read_data(sdp_packet.get_remaining_bytes_to_read(), sdp_packet.get_current_buffer_pos(),
                             sdp_packet.get_remaining_buffer_capacity());

        sdp_packet.update_read_bytes(result.bytes_read);

        if (result.state == ReadState::ACCEPTED_SESSION) {
            int client_fd;
            std::memcpy(&client_fd, sdp_packet.get_buffer(), sizeof(int));

            // reset packet
            sdp_packet = io::SdpPacket();

            return client_fd;
        } else if (result.state == ReadState::WOULD_BLOCK) {
            // need more data!
            return -1;
        }

        // fall-through: result.state should be ReadResult::State::READ_COMPLETE
        assert(result.state == ReadState::READ_COMPLETE);

        // check packet!
        if (sdp_packet.get_state() == PacketState::HEADER_READ) {
            // logf("Read complete header!\n");

            // try again, to read the rest
            // FIXME (aw): the ssl layer probably already reads the whole packet, so poll won't notify us again
            // this might also be an issue because it might happen that we get multiple packets in this loop, which is
            // probably not exactly what we want
            continue;
        } else if (sdp_packet.get_state() == PacketState::FINISHED) {
            handle_v2g_payload();

            sdp_packet = {};
            continue;
        }

        return -1;
    }
}

void D20Session::handle_v2g_payload() {
    assert(sdp_packet.get_state() == io::SdpPacket::State::FINISHED);

    // tmp. logging
    log_sdp_packet(sdp_packet);

    const auto payload_type = sdp_packet.get_payload_type();
    const iso15118::io::StreamInputView exi_input = {sdp_packet.get_payload_buffer(), sdp_packet.get_payload_length()};

    message_exchange.set_request(payload_type, exi_input);
    fsm.handle_event(d20::FsmEvent::NEW_V2GTP_MESSAGE);

    const auto [got_response, payload_size] = message_exchange.check_and_clear_response();

    if (not got_response) {
        logf("Note: no response was created!\n");
        return;
    }

    const auto response_size = setup_response_header(response_buffer, payload_type, payload_size);
    server.write_data(response_buffer, response_size);
}

} // namespace iso15118::session
