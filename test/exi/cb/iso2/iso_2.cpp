#include <catch2/catch_test_macros.hpp>

#include <iso15118/message_d2/session_setup.hpp>
#include <iso15118/message_d2/variant.hpp>

#include <vector>

using namespace iso15118;

SCENARIO("ISO15118-2 Ser/Des") {

    // 809802000000000000000011d0184b88f8434d2000
    // <ns7:V2G_Message xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    // xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:ns4="http://www.w3.org/2000/09/xmldsig#"
    // xmlns:ns5="urn:iso:15118:2:2013:MsgBody" xmlns:ns6="urn:iso:15118:2:2013:MsgDataTypes"
    // xmlns:ns7="urn:iso:15118:2:2013:MsgDef" xmlns:ns8="urn:iso:15118:2:2013:MsgHeader">
    //     <ns7:Header>
    //         <ns8:SessionID>0000000000000000</ns8:SessionID>
    //     </ns7:Header>
    //     <ns7:Body>
    //         <ns5:SessionSetupReq>
    //             <ns5:EVCCID>12E23E10D348</ns5:EVCCID>
    //         </ns5:SessionSetupReq>
    //     </ns7:Body>
    // </ns7:V2G_Message>

    GIVEN("A binary representation of an SessionSetupReq document") {
        uint8_t doc_raw[] = "\x80"
                            "\x98\x02\x00\x00\x00\x00\x00\x00\x00\x00\x11\xd0"
                            "\x18\x4b\x88\xf8\x43\x4d\x20\x00";

        const io::StreamInputView stream_view{doc_raw, sizeof(doc_raw)};

        message_2::Variant variant(io::v2gtp::PayloadType::SAP, stream_view);

        THEN("It should be decoded succussfully") {
            REQUIRE(variant.get_type() == message_2::Type::SessionSetupReq);

            const auto& msg = variant.get<message_2::SessionSetupRequest>();
            const auto& header = msg.header;

            for (auto& id : header.session_id) {
                REQUIRE(id == 0);
            }

            std::vector<uint8_t> evccid = {0x12, 0xE2, 0x3E, 0x10, 0xD3, 0x48};

            for (uint8_t id = 0; id < message_2::EVCC_ID_LENGTH; id++) {
                REQUIRE(msg.evccid.at(id) == evccid.at(id));
            }

        }
    }
}
