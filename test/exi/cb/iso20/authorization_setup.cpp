#include <catch2/catch_test_macros.hpp>

#include <string>

#include <iso15118/message/authorization_setup.hpp>
#include <iso15118/message/variant.hpp>

#include "helper.hpp"

using namespace iso15118;

SCENARIO("Se/Deserialize authorization setup messages") {

    GIVEN("Deserialize authorization_setup_req") {

        uint8_t doc_raw[] = {0x80, 0x08, 0x04, 0x79, 0x0c, 0x8a, 0xdc, 0xee, 0xee,
                             0x09, 0x68, 0x8d, 0x6c, 0xac, 0x3a, 0x60, 0x62};

        const io::StreamInputView stream_view{doc_raw, sizeof(doc_raw)};

        message_20::Variant variant(io::v2gtp::PayloadType::Part20Main, stream_view);

        THEN("It should be deserialized succussfully") {
            REQUIRE(variant.get_type() == message_20::Type::AuthorizationSetupReq);

            const auto& msg = variant.get<message_20::AuthorizationSetupRequest>();
            const auto& header = msg.header;

            REQUIRE(header.session_id == std::array<uint8_t, 8>{0xF2, 0x19, 0x15, 0xB9, 0xDD, 0xDC, 0x12, 0xD1});
            REQUIRE(header.timestamp == 1691411798);
        }
    }

    GIVEN("Serialize authorization_setup_res") {

        message_20::AuthorizationSetupResponse res;

        res.header = message_20::Header{{0xF2, 0x19, 0x15, 0xB9, 0xDD, 0xDC, 0x12, 0xD1}, 1691411798};
        res.response_code = message_20::ResponseCode::OK;
        res.authorization_services = {{message_20::Authorization::EIM}};
        res.certificate_installation_service = true;
        res.authorization_mode = message_20::AuthorizationSetupResponse::EIM_ASResAuthorizationMode();

        std::vector<uint8_t> expected = {0x80, 0x0c, 0x04, 0x79, 0x0c, 0x8a, 0xdc, 0xee, 0xee, 0x09,
                                         0x68, 0x8d, 0x6c, 0xac, 0x3a, 0x60, 0x62, 0x00, 0x05, 0x00};

        THEN("It should be serialized succussfully") {
            REQUIRE(serialize_helper(res) == expected);
        }
    }

    GIVEN("Serialize authorization_setup_res pnc") {

        message_20::AuthorizationSetupResponse res;

        res.header = message_20::Header{{0xF2, 0x19, 0x15, 0xB9, 0xDD, 0xDC, 0x12, 0xD1}, 1691411798};
        res.response_code = message_20::ResponseCode::OK;
        res.authorization_services = {{message_20::Authorization::EIM}, {message_20::Authorization::PnC}};
        res.certificate_installation_service = true;

        auto& mode =
            res.authorization_mode.emplace<message_20::AuthorizationSetupResponse::PnC_ASResAuthorizationMode>();

        mode.gen_challenge = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

        // FIXME(SL): supported_providers missing

        std::vector<uint8_t> expected = {0x80, 0x0c, 0x04, 0x79, 0x0c, 0x8a, 0xdc, 0xee, 0xee, 0x09, 0x68, 0x8d, 0x6c,
                                         0xac, 0x3a, 0x60, 0x62, 0x00, 0x01, 0x12, 0x08, 0x00, 0x81, 0x01, 0x82, 0x02,
                                         0x83, 0x03, 0x84, 0x04, 0x85, 0x05, 0x86, 0x06, 0x87, 0x07, 0x88, 0x10};

        THEN("It should be serialized succussfully") {
            REQUIRE(serialize_helper(res) == expected);
        }
    }
}