#include <catch2/catch_test_macros.hpp>

#include <iso15118/message_d20/authorization.hpp>
#include <iso15118/message_d20/authorization_setup.hpp>
#include <iso15118/message_d20/schedule_exchange.hpp>
#include <iso15118/message_d20/service_detail.hpp>
#include <iso15118/message_d20/service_discovery.hpp>
#include <iso15118/message_d20/service_selection.hpp>
#include <iso15118/message_d20/session_setup.hpp>
#include <iso15118/message_d20/variant.hpp>

#include <string>

using namespace iso15118;

SCENARIO("ISO15118-20 Ser/Des") {

    // 808c00800d6cac3a60620b2ba6a4ab1899199a1a9b1b9c1c9820a121a222ac00
    // {"SessionSetupReq":
    // {"Header":{"SessionID":"00","TimeStamp":1691411798},
    // "EVCCID":"WMIV1234567890ABCDEX"}}

    GIVEN("A binary representation of an SessionSetupReq document") {

        uint8_t doc_raw[] = "\x80"
                            "\x8c\x00\x80\x0d\x6c\xac\x3a\x60\x62\x0b\x2b\xa6\xa4\xab\x18"
                            "\x99\x19\x9a\x1a\x9b\x1b\x9c\x1c\x98\x20\xa1\x21\xa2\x22\xac\x00";

        const io::StreamInputView stream_view{doc_raw, sizeof(doc_raw)};

        message_20::Variant variant(io::v2gtp::PayloadType::Part20Main, stream_view);

        THEN("It should be decoded succussfully") {
            REQUIRE(variant.get_type() == message_20::Type::SessionSetupReq);

            const auto& msg = variant.get<message_20::SessionSetupRequest>();
            const auto& header = msg.header;

            for (auto& id : header.session_id) {
                REQUIRE(id == 0);
            }
            REQUIRE(header.timestamp == 1691411798);

            REQUIRE(msg.evccid == "WMIV1234567890ABCDEX");
        }
    }

    // 809004790c8adceeee09688d6cac3a606204031552cc4c8cd14c4c8ccd00
    // {"SessionSetupRes":
    // {   "Header": {"SessionID": "F21915B9DDDC12D1", "TimeStamp": 1691411798},
    //     "ResponseCode": "OK_NewSessionEstablished",
    //     "EVSEID": "UK123E1234"
    // }}

    // GIVEN("A binary representation of an SessionSetupRes document") {

    //     uint8_t doc_raw[] = "\x80\x90\x04\x79\x0c\x8a\xdc\xee\xee\x09\x68\x8d\x6c"
    //                         "\xac\x3a\x60\x62\x04\x03\x15\x52\xcc\x4c\x8c\xd1\x4c"
    //                         "\x4c\x8c\xcd\x00";

    //     exi_bitstream_t exi_stream_in;
    //     size_t pos1 = 0;
    //     int errn = 0;

    //     exi_bitstream_init(&exi_stream_in, reinterpret_cast<uint8_t*>(doc_raw), sizeof(doc_raw), pos1, nullptr);

    //     THEN("It should be decoded succussfully") {

    //         iso20_exiDocument response;
    //         init_iso20_exiDocument(&response);
    //         REQUIRE(decode_iso20_exiDocument(&exi_stream_in, &response) == 0);
    //         REQUIRE(response.SessionSetupRes_isUsed == true);

    //         iso20_SessionSetupResType session_setup_res = response.SessionSetupRes;
    //         iso20_MessageHeaderType header = session_setup_res.Header;

    //         REQUIRE(header.SessionID.bytesLen == 8);
    //         REQUIRE(header.SessionID.bytes[0] == 0xF2);
    //         REQUIRE(header.SessionID.bytes[7] == 0xD1);
    //         REQUIRE(header.TimeStamp == 1691411798);
    //         REQUIRE(header.Signature_isUsed == false);

    //         REQUIRE(session_setup_res.ResponseCode == iso20_responseCodeType_OK_NewSessionEstablished);
    //         REQUIRE(std::string(session_setup_res.EVSEID.characters) == "UK123E1234");
    //     }
    // }

    // 800804790c8adceeee09688d6cac3a6062
    // {"AuthorizationSetupReq":{
    //     "Header":{"SessionID":"F21915B9DDDC12D1","TimeStamp":1691411798}
    // }}

    GIVEN("A binary representation of an AuthorizationSetupReq document") {

        uint8_t doc_raw[] = "\x80\x08\x04\x79\x0c\x8a\xdc\xee\xee\x09\x68\x8d\x6c\xac\x3a\x60\x62";

        const io::StreamInputView stream_view{doc_raw, sizeof(doc_raw)};

        message_20::Variant variant(io::v2gtp::PayloadType::Part20Main, stream_view);

        THEN("It should be decoded succussfully") {

            REQUIRE(variant.get_type() == message_20::Type::AuthorizationSetupReq);

            const auto& msg = variant.get<message_20::AuthorizationSetupRequest>();
            const auto& header = msg.header;

            REQUIRE(header.session_id[0] == 0xF2);
            REQUIRE(header.session_id[7] == 0xD1);
            REQUIRE(header.timestamp == 1691411798);
        }
    }

    // // 800c04790c8adceeee09688d6cac3a6062000500
    // // {"AuthorizationSetupRes":
    // //     {"Header": {"SessionID": "F21915B9DDDC12D1", "TimeStamp": 1691411798},
    // //     "ResponseCode": "OK",
    // //     "AuthorizationServices": ["EIM"],
    // //     "CertificateInstallationService": true,
    // //     "EIM_ASResAuthorizationMode": {}
    // // }}

    // GIVEN("A binary representation of an AuthorizationSetupRes document") {

    //     uint8_t doc_raw[] = "\x80\x0c\x04\x79\x0c\x8a\xdc\xee\xee\x09\x68\x8d\x6c\xac\x3a\x60\x62\x00\x05\x00";

    //     exi_bitstream_t exi_stream_in;
    //     size_t pos1 = 0;
    //     int errn = 0;

    //     exi_bitstream_init(&exi_stream_in, reinterpret_cast<uint8_t*>(doc_raw), sizeof(doc_raw), pos1, nullptr);

    //     THEN("It should be decoded succussfully") {

    //         iso20_exiDocument response;
    //         init_iso20_exiDocument(&response);
    //         REQUIRE(decode_iso20_exiDocument(&exi_stream_in, &response) == 0);
    //         REQUIRE(response.AuthorizationSetupRes_isUsed == true);

    //         iso20_AuthorizationSetupResType auth_setup_res = response.AuthorizationSetupRes;
    //         iso20_MessageHeaderType header = auth_setup_res.Header;

    //         REQUIRE(header.SessionID.bytesLen == 8);
    //         REQUIRE(header.SessionID.bytes[0] == 0xF2);
    //         REQUIRE(header.SessionID.bytes[7] == 0xD1);
    //         REQUIRE(header.TimeStamp == 1691411798);
    //         REQUIRE(header.Signature_isUsed == false);
    //     }
    // }

    // // 800004790c8adceeee09688d6cac3a606200
    // // {"AuthorizationReq":
    // //     {"Header":{"SessionID":"F21915B9DDDC12D1","TimeStamp":1691411798},
    // //     "SelectedAuthorizationService":"EIM",
    // //     "EIM_AReqAuthorizationMode":{}
    // // }}

    GIVEN("A binary representation of an AuthorizationReq document") {

        uint8_t doc_raw[] = "\x80\x00\x04\x79\x0c\x8a\xdc\xee\xee\x09\x68\x8d\x6c\xac\x3a\x60\x62\x00";

        const io::StreamInputView stream_view{doc_raw, sizeof(doc_raw)};

        message_20::Variant variant(io::v2gtp::PayloadType::Part20Main, stream_view);

        THEN("It should be decoded succussfully") {

            REQUIRE(variant.get_type() == message_20::Type::AuthorizationReq);

            const auto& msg = variant.get<message_20::AuthorizationRequest>();
            const auto& header = msg.header;

            REQUIRE(header.session_id[0] == 0xF2);
            REQUIRE(header.session_id[7] == 0xD1);
            REQUIRE(header.timestamp == 1691411798);

            REQUIRE(msg.selected_authorization_service == message_20::Authorization::EIM);
            REQUIRE(msg.eim_as_req_authorization_mode.has_value() == true);
        }
    }

    // // 800404790c8adceeee09688d6cac3a60620000
    // // {"AuthorizationRes":
    // //     {"Header": {"SessionID": "F21915B9DDDC12D1", "TimeStamp": 1691411798},
    // //     "ResponseCode": "OK",
    // //     "EVSEProcessing": "Finished"
    // // }}

    // GIVEN("A binary representation of an AuthorizationRes document") {

    //     uint8_t doc_raw[] = "\x80\x04\x04\x79\x0c\x8a\xdc\xee\xee\x09\x68\x8d\x6c\xac\x3a\x60\x62\x00\x00";

    //     exi_bitstream_t exi_stream_in;
    //     size_t pos1 = 0;
    //     int errn = 0;

    //     exi_bitstream_init(&exi_stream_in, reinterpret_cast<uint8_t*>(doc_raw), sizeof(doc_raw), pos1, nullptr);

    //     THEN("It should be decoded succussfully") {

    //         iso20_exiDocument response;
    //         init_iso20_exiDocument(&response);
    //         REQUIRE(decode_iso20_exiDocument(&exi_stream_in, &response) == 0);
    //         REQUIRE(response.AuthorizationRes_isUsed == true);

    //         iso20_AuthorizationResType auth_res = response.AuthorizationRes;
    //         iso20_MessageHeaderType header = auth_res.Header;

    //         REQUIRE(header.SessionID.bytesLen == 8);
    //         REQUIRE(header.SessionID.bytes[0] == 0xF2);
    //         REQUIRE(header.SessionID.bytes[7] == 0xD1);
    //         REQUIRE(header.TimeStamp == 1691411798);
    //         REQUIRE(header.Signature_isUsed == false);

    //         REQUIRE(auth_res.ResponseCode == iso20_responseCodeType_OK);
    //         REQUIRE(auth_res.EVSEProcessing == iso20_processingType_Finished);
    //     }
    // }

    // 807c040275ff964a2ceda10e387e8a606280
    // {"ServiceDiscoveryReq":{"Header":{"SessionID":"04EBFF2C9459DB42","TimeStamp":1692009443}}}

    GIVEN("A binary representation of an ServiceDiscoveryReq document") {

        uint8_t doc_raw[] = "\x80\x7c\x04\x02\x75\xff\x96\x4a\x2c\xed\xa1\x0e\x38\x7e\x8a\x60\x62\x80";

        const io::StreamInputView stream_view{doc_raw, sizeof(doc_raw)};

        message_20::Variant variant(io::v2gtp::PayloadType::Part20Main, stream_view);

        THEN("It should be decoded succussfully") {

            REQUIRE(variant.get_type() == message_20::Type::ServiceDiscoveryReq);

            const auto& msg = variant.get<message_20::ServiceDiscoveryRequest>();
            const auto& header = msg.header;

            REQUIRE(header.session_id[0] == 0x04);
            REQUIRE(header.session_id[7] == 0x42);
            REQUIRE(header.timestamp == 1692009443);
        }
    }

    // 8074040275ff964a2ceda10e387e8a60620280
    // {"ServiceDetailReq":{"Header":{"SessionID":"04EBFF2C9459DB42","TimeStamp":1692009443},"ServiceID":5}}

    GIVEN("A binary representation of an ServiceDetailReq document") {

        uint8_t doc_raw[] = "\x80\x74\x04\x02\x75\xff\x96\x4a\x2c\xed\xa1\x0e\x38\x7e\x8a\x60\x62\x02\x80";

        const io::StreamInputView stream_view{doc_raw, sizeof(doc_raw)};

        message_20::Variant variant(io::v2gtp::PayloadType::Part20Main, stream_view);

        THEN("It should be decoded succussfully") {

            REQUIRE(variant.get_type() == message_20::Type::ServiceDetailReq);

            const auto& msg = variant.get<message_20::ServiceDetailRequest>();
            const auto& header = msg.header;

            REQUIRE(header.session_id[0] == 0x04);
            REQUIRE(header.session_id[7] == 0x42);
            REQUIRE(header.timestamp == 1692009443);

            REQUIRE(msg.service == message_20::ServiceCategory::AC_BPT);
        }
    }

    // 8084040275ff964a2ceda10e387e8a606201400880
    // {"ServiceSelectionReq":{"Header":{"SessionID":"04EBFF2C9459DB42","TimeStamp":1692009443},"SelectedEnergyTransferService":{"ServiceID":5,"ParameterSetID":1}}}

    GIVEN("A binary representation of an ServiceSelectionReq document") {

        uint8_t doc_raw[] = "\x80\x84\x04\x02\x75\xff\x96\x4a\x2c\xed\xa1\x0e\x38\x7e\x8a\x60\x62\x01\x40\x08\x80";

        const io::StreamInputView stream_view{doc_raw, sizeof(doc_raw)};

        message_20::Variant variant(io::v2gtp::PayloadType::Part20Main, stream_view);

        THEN("It should be decoded succussfully") {

            REQUIRE(variant.get_type() == message_20::Type::ServiceSelectionReq);

            const auto& msg = variant.get<message_20::ServiceSelectionRequest>();
            const auto& header = msg.header;

            REQUIRE(header.session_id[0] == 0x04);
            REQUIRE(header.session_id[7] == 0x42);
            REQUIRE(header.timestamp == 1692009443);

            REQUIRE(msg.selected_energy_transfer_service.service_id == message_20::ServiceCategory::AC_BPT);
            REQUIRE(msg.selected_energy_transfer_service.parameter_set_id == 1);
        }
    }

    GIVEN("A binary representation of an ChargeScheduleRequest document") {

        uint8_t doc_raw[] =
            "\x80\x6c\x04\x36\x9c\x31\xd9\xf9\xa6\x24\x16\x8b\xa9\x0f\x3a\x60\x62\x7e\x84\x28\x0e\x00\x83\x00\xa0\x10"
            "\x60\x28\x03\xf0\x02\x80\x00\x04\x80\xe0\x41\x88\x48\x40\x00\x02\xa2\xaa\xa9\x03\x27\x57\x26\xe3\xa6\x97"
            "\x36\xf3\xa7\x37\x46\x43\xa6\x97\x36\xf3\xa3\x13\x53\x13\x13\x83\xa2\xd3\x23\x03\xa5\x07\x26\x96\x36\x54"
            "\x16\xc6\x76\xf7\x26\x97\x46\x86\xd3\xa3\x12\xd5\x06\xf7\x76\x57\x20\x00\x02\x00\x00\x01\x00\x00\x01\x40";

        const io::StreamInputView stream_view{doc_raw, sizeof(doc_raw)};

        message_20::Variant variant(io::v2gtp::PayloadType::Part20Main, stream_view);

        THEN("It should be decoded succussfully") {
            REQUIRE(variant.get_type() == message_20::Type::ScheduleExchangeReq);
        }
    }

    GIVEN("A ScheduleExchangeResponse") {
        message_20::ScheduleExchangeResponse res;
        res.header.session_id = {0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23};
        res.response_code = message_20::ResponseCode::OK;

        uint8_t serialization_buffer[1024];
        io::StreamOutputView out({serialization_buffer, sizeof(serialization_buffer)});

        const auto size = message_20::serialize(res, out);
    }

    // // 801004790c8adceeee09688d6cac3a606288300b220019088300b220019080
    // // {"AC_ChargeParameterDiscoveryReq":
    // //     {"Header":{"SessionID":"F21915B9DDDC12D1","TimeStamp":1691411798},
    // //     "BPT_AC_CPDReqEnergyTransferMode":
    // //         {"EVMaximumChargePower":{"Exponent":3,"Value":11},
    // //         "EVMinimumChargePower":{"Exponent":0,"Value":100},
    // //         "EVMaximumDischargePower":{"Exponent":3,"Value":11},
    // //         "EVMinimumDischargePower":{"Exponent":0,"Value":100}
    // //         }
    // //     }
    // // }

    // GIVEN("A binary representation of an AC_ChargeParameterDiscoveryReq document") {

    //     uint8_t doc_raw[] = "\x80\x10\x04\x79\x0c\x8a\xdc\xee\xee\x09\x68\x8d\x6c\xac"
    //                         "\x3a\x60\x62\x88\x30\x0b\x22\x00\x19\x08\x83\x00\xb2\x20"
    //                         "\x01\x90\x80";

    //     exi_bitstream_t exi_stream_in;
    //     size_t pos1 = 0;
    //     int errn = 0;

    //     exi_bitstream_init(&exi_stream_in, reinterpret_cast<uint8_t*>(doc_raw), sizeof(doc_raw), pos1, nullptr);

    //     THEN("It should be decoded succussfully") {

    //         iso20_ac_exiDocument request;
    //         init_iso20_ac_exiDocument(&request);
    //         REQUIRE(decode_iso20_ac_exiDocument(&exi_stream_in, &request) == 0);
    //         REQUIRE(request.AC_ChargeParameterDiscoveryReq_isUsed == true);

    //         iso20_ac_AC_ChargeParameterDiscoveryReqType charge_param_req = request.AC_ChargeParameterDiscoveryReq;
    //         iso20_ac_MessageHeaderType header = charge_param_req.Header;

    //         REQUIRE(header.SessionID.bytesLen == 8);
    //         REQUIRE(header.SessionID.bytes[0] == 0xF2);
    //         REQUIRE(header.SessionID.bytes[7] == 0xD1);
    //         REQUIRE(header.TimeStamp == 1691411798);
    //         REQUIRE(header.Signature_isUsed == false);

    //         REQUIRE(charge_param_req.BPT_AC_CPDReqEnergyTransferMode_isUsed == true);

    //         iso20_ac_BPT_AC_CPDReqEnergyTransferModeType ac_bpt_param =
    //             charge_param_req.BPT_AC_CPDReqEnergyTransferMode;

    //         REQUIRE(ac_bpt_param.EVMaximumChargePower.Value == 11);
    //         REQUIRE(ac_bpt_param.EVMaximumChargePower.Exponent == 3);

    //         REQUIRE(ac_bpt_param.EVMinimumChargePower.Value == 100);
    //         REQUIRE(ac_bpt_param.EVMinimumChargePower.Exponent == 0);

    //         REQUIRE(ac_bpt_param.EVMaximumDischargePower.Value == 11);
    //         REQUIRE(ac_bpt_param.EVMaximumDischargePower.Exponent == 3);

    //         REQUIRE(ac_bpt_param.EVMinimumDischargePower.Value == 100);
    //         REQUIRE(ac_bpt_param.EVMinimumDischargePower.Exponent == 0);
    //     }
    // }
}
