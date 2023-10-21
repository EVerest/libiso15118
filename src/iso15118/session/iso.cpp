// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/session/iso.hpp>

#include <cassert>
#include <cstring>

#include <iso15118/d20/state/supported_app_protocol.hpp>

#include <iso15118/detail/helper.hpp>

namespace iso15118 {

static constexpr auto SESSION_IDLE_TIMEOUT_MS = 5000;

static void log_sdp_packet(const iso15118::io::SdpPacket& sdp) {
    static constexpr auto ESCAPED_BYTE_CHAR_COUNT = 4;
    auto payload_string_buffer = std::make_unique<char[]>(sdp.get_payload_length() * ESCAPED_BYTE_CHAR_COUNT + 1);
    for (auto i = 0; i < sdp.get_payload_length(); ++i) {
        snprintf(payload_string_buffer.get() + i * ESCAPED_BYTE_CHAR_COUNT, ESCAPED_BYTE_CHAR_COUNT + 1, "\\x%02hx",
                 sdp.get_payload_buffer()[i]);
    }

    iso15118::logf("[SDP Packet in]: Header: %04hx, Payload: %s", sdp.get_payload_type(), payload_string_buffer.get());
}

void raise_invalid_packet_state(const io::SdpPacket& sdp_packet) {
    using PacketState = io::SdpPacket::State;

    auto error = std::string("Error while reading sdp packet: ");
    switch (sdp_packet.get_state()) {
    case PacketState::INVALID_HEADER:
        error += "invalid sdp packet header";
        break;
    case PacketState::PAYLOAD_TO_LONG:
        error += "packet too large for buffer";
        break;
    default:
        assert(false);
    }

    log_and_throw(error.c_str());
}

// NOTE (aw): this function return true, if it would block to read a complete packet
//            if it returns false, the packet is complete
bool read_single_sdp_packet(io::IConnection& connection, io::SdpPacket& sdp_packet) {
    // NOTE (aw): not happy with this function
    //            main problem is, that it combines too much logic of the sdp packet and io related stuff
    using PacketState = io::SdpPacket::State;

    assert(sdp_packet.get_state() == PacketState::EMPTY || sdp_packet.get_state() == PacketState::HEADER_READ);

    // FIXME (aw): proper handling of case, where read returns 0!
    auto result = connection.read(sdp_packet.get_current_buffer_pos(), sdp_packet.get_remaining_bytes_to_read());
    sdp_packet.update_read_bytes(result.bytes_read);

    if (result.would_block) {
        // need more data!
        return true;
    }

    if (sdp_packet.get_state() == PacketState::COMPLETE) {
        // done
        return false;
    }

    // packet not finished
    if (sdp_packet.get_state() != PacketState::HEADER_READ) {
        raise_invalid_packet_state(sdp_packet);
    }

    // header read successfully, try to read the rest
    result = connection.read(sdp_packet.get_current_buffer_pos(), sdp_packet.get_remaining_bytes_to_read());
    sdp_packet.update_read_bytes(result.bytes_read);

    if (result.would_block) {
        // need more data!
        return true;
    }

    // assert finished packet
    if (sdp_packet.get_state() != PacketState::COMPLETE) {
        raise_invalid_packet_state(sdp_packet);
    }

    return false;
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

Session::Session(std::unique_ptr<io::IConnection> connection_, const SessionConfig& config) :
    connection(std::move(connection_)), session_logger(this) {

    next_session_event = offset_time_point_by_ms(get_current_time_point(), SESSION_IDLE_TIMEOUT_MS);
    connection->set_event_callback([this](io::ConnectionEvent event) { this->handle_connection_event(event); });
    fsm.reset<d20::state::SupportedAppProtocol>(ctx);
}

Session::~Session() = default;

TimePoint const& Session::poll() {
    const auto now = get_current_time_point();

    if (not state.connected) {
        // nothing happened so far, just return
        next_session_event = offset_time_point_by_ms(now, SESSION_IDLE_TIMEOUT_MS);
        return next_session_event;
    }

    // check for new data to read
    if (state.new_data) {
        const bool would_block = read_single_sdp_packet(*connection, packet);

        if (would_block) {
            state.new_data = false;
        }
    }

    // check for complete sdp packet
    if (packet.is_complete()) {
        // FIXME (aw): this event loop only acts on new packets, seems to be enough for now ...
        const auto payload_type = packet.get_payload_type();
        const io::StreamInputView exi_input = {packet.get_payload_buffer(), packet.get_payload_length()};

        message_exchange.set_request(payload_type, exi_input);
        fsm.handle_event(d20::FsmEvent::NEW_V2GTP_MESSAGE);

        const auto [got_response, payload_size] = message_exchange.check_and_clear_response();

        if (got_response) {
            const auto response_size = setup_response_header(response_buffer, payload_type, payload_size);
            connection->write(response_buffer, response_size);
        }

        packet = {}; // reset the packet
    }

    // FIXME (aw): proper timeout handling!
    next_session_event = offset_time_point_by_ms(now, SESSION_IDLE_TIMEOUT_MS);
    return next_session_event;
}

void Session::handle_connection_event(io::ConnectionEvent event) {
    using Event = io::ConnectionEvent;
    switch (event) {
    case Event::ACCEPTED:
        assert(state.connected == false);
        state.connected = true;
        session_logger.log_event("Accepted connection");
        return;

    case Event::NEW_DATA:
        assert(state.connected);
        state.new_data = true;
        return;

    case Event::OPEN:
        assert(state.connected);
        // NOTE (aw): for now, we don't really need this information ...
        return;
    }
}

} // namespace iso15118
