// SPDX-License-Identifier: Apache-2.0
// Copyright 2023 Pionix GmbH and Contributors to EVerest
#include <iso15118/session/iso.hpp>
#include <iso15118/session_d2/iso.hpp>

#include <cassert>
#include <cstring>

#include <iso15118/d2/state/supported_app_protocol.hpp>

#include <iso15118/detail/helper.hpp>

namespace iso15118 {

static constexpr auto SESSION_IDLE_TIMEOUT_MS_2 = 5000;

static void log_packet_from_car(const iso15118::io::SdpPacket& packet, session_2::SessionLogger& logger) {
    logger.exi(static_cast<uint16_t>(packet.get_payload_type()), packet.get_payload_buffer(),
               packet.get_payload_length(), session_2::logging::ExiMessageDirection::FROM_EV);
}

static std::unique_ptr<message_2::Variant> make_variant_from_packet(const iso15118::io::SdpPacket& packet) {
    return std::make_unique<message_2::Variant>(
        packet.get_payload_type(), io::StreamInputView{packet.get_payload_buffer(), packet.get_payload_length()});
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

Session_2::Session_2(std::unique_ptr<io::IConnection> connection_, const d2::SessionConfig& config,
                 const session_2::feedback::Callbacks& callbacks) :
    connection(std::move(connection_)),
    log(this),
    ctx(message_exchange, active_control_event, callbacks, session_stopped, log, config) {

    next_session_event = offset_time_point_by_ms(get_current_time_point(), SESSION_IDLE_TIMEOUT_MS_2);
    connection->set_event_callback([this](io::ConnectionEvent event) { this->handle_connection_event(event); });
    fsm.reset<d2::state::SupportedAppProtocol>(ctx);
}

Session_2::~Session_2() = default;

void Session_2::push_control_event(const d2::ControlEvent& event) {
    control_event_queue.push(event);
}

TimePoint const& Session_2::poll() {
    const auto now = get_current_time_point();

    if (not state.connected) {
        // nothing happened so far, just return
        next_session_event = offset_time_point_by_ms(now, SESSION_IDLE_TIMEOUT_MS_2);
        return next_session_event;
    }

    // check for new data to read
    if (state.new_data) {
        const bool would_block = read_single_sdp_packet(*connection, packet);

        if (would_block) {
            state.new_data = false;
        }
    }

    // send all of our queued control events
    while (active_control_event = control_event_queue.pop()) {
        const auto res = fsm.handle_event(d2::FsmEvent::CONTROL_MESSAGE);
        // FIXME (aw): check result!
    }

    // check for complete sdp packet
    if (packet.is_complete()) {
        // FIXME (aw): this event loop only acts on new packets, seems to be enough for now ...
        log_packet_from_car(packet, log);

        message_exchange.set_request(make_variant_from_packet(packet));

        packet = {}; // reset the packet

        const auto res = fsm.handle_event(d2::FsmEvent::V2GTP_MESSAGE);
    }

    const auto [got_response, payload_size, payload_type] = message_exchange.check_and_clear_response();

    if (got_response) {
        const auto response_size = setup_response_header(response_buffer, payload_type, payload_size);
        connection->write(response_buffer, response_size);

        // FIXME (aw): this is hacky ...
        log.exi(static_cast<uint16_t>(payload_type), response_buffer + io::SdpPacket::V2GTP_HEADER_SIZE, payload_size,
                session_2::logging::ExiMessageDirection::TO_EV);

        if (session_stopped) {
            connection->close();
            session_stopped = false; // reset
            ctx.feedback.signal(session_2::feedback::Signal::DLINK_TERMINATE);
        }
    }

    // FIXME (aw): proper timeout handling!
    next_session_event = offset_time_point_by_ms(now, SESSION_IDLE_TIMEOUT_MS_2);
    return next_session_event;
}

void Session_2::handle_connection_event(io::ConnectionEvent event) {
    using Event = io::ConnectionEvent;
    switch (event) {
    case Event::ACCEPTED:
        assert(state.connected == false);
        state.connected = true;
        log("Accepted connection on port %d", connection->get_public_endpoint().port);
        return;

    case Event::NEW_DATA:
        assert(state.connected);
        state.new_data = true;
        return;

    case Event::OPEN:
        assert(state.connected);
        // NOTE (aw): for now, we don't really need this information ...
        return;

    case Event::CLOSED:
        state.connected = false;
        logf("Connection is closed\n");
        return;
    }
}

} // namespace iso15118
