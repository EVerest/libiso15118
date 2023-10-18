#include <catch2/catch_test_macros.hpp>

#include <iso15118/message/variant.hpp>
#include <iso15118/message/supported_app_protocol.hpp>

#include <string>

using namespace iso15118;

SCENARIO("App Protocol Ser/Des") {
    GIVEN("A binary representation of an AppProtocolReq document") {

        uint8_t doc_raw[] = "\x80"
                            "\x00\xf3\xab\x93\x71\xd3\x4b\x9b\x79\xd3\x9b\xa3\x21\xd3\x4b\x9b\x79"
                            "\xd1\x89\xa9\x89\x89\xc1\xd1\x69\x91\x81\xd2\x0a\x18\x01\x00\x00\x04"
                            "\x00\x40";

        const io::StreamInputView stream_view {doc_raw, sizeof(doc_raw)};

        message_20::Variant variant(io::v2gtp::PayloadType::SAP, stream_view);
        
        THEN("It should be decoded succussfully") {
            REQUIRE(variant.get_type() == message_20::Type::SupportedAppProtocolReq);
            
            const auto& msg = variant.get<message_20::SupportedAppProtocolRequest>();

            REQUIRE(msg.app_protocol.size() == 1);

            const auto& ap = msg.app_protocol[0];

            REQUIRE(ap.version_number_major == 1);
            REQUIRE(ap.version_number_minor == 0);
            REQUIRE(ap.schema_id == 1);
            REQUIRE(ap.priority == 1);

            REQUIRE(ap.protocol_namespace == "urn:iso:std:iso:15118:-20:AC");
        }
    }

    // 80400040
    // {"supportedAppProtocolRes": {"ResponseCode": "OK_SuccessfulNegotiation", "SchemaID": 1}}

    // GIVEN("A binary representation of an AppProtocolRes document") {
    //     uint8_t doc_raw[] = "\x80\x40\x00\x40";

    //     exi_bitstream_t exi_stream_in;
    //     size_t pos1 = 0;
    //     int errn = 0;

    //     exi_bitstream_init(&exi_stream_in, reinterpret_cast<uint8_t*>(doc_raw), sizeof(doc_raw), pos1, nullptr);

    //     THEN("It should be decoded succussfully") {
    //         appHand_exiDocument response;

    //         REQUIRE(decode_appHand_exiDocument(&exi_stream_in, &response) == 0);
    //         REQUIRE(response.supportedAppProtocolRes_isUsed == 1);

    //         REQUIRE(response.supportedAppProtocolRes.ResponseCode == appHand_responseCodeType_OK_SuccessfulNegotiation);
    //         REQUIRE(response.supportedAppProtocolRes.SchemaID_isUsed == true);
    //         REQUIRE(response.supportedAppProtocolRes.SchemaID == 1);
    //     }
    // }
}
