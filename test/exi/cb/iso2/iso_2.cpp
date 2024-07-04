#include <catch2/catch_test_macros.hpp>

#include <iso15118/message_d2/authorization.hpp>
#include <iso15118/message_d2/certificate_installation.hpp>
#include <iso15118/message_d2/certificate_update.hpp>
#include <iso15118/message_d2/charge_parameter_discovery.hpp>
#include <iso15118/message_d2/charging_status.hpp>
#include <iso15118/message_d2/dc_cable_check.hpp>
#include <iso15118/message_d2/dc_current_demand.hpp>
#include <iso15118/message_d2/dc_pre_charge.hpp>
#include <iso15118/message_d2/dc_welding_detection.hpp>
#include <iso15118/message_d2/metering_receipt.hpp>
#include <iso15118/message_d2/payment_details.hpp>
#include <iso15118/message_d2/power_delivery.hpp>
#include <iso15118/message_d2/service_discovery.hpp>
#include <iso15118/message_d2/service_selection.hpp>
#include <iso15118/message_d2/session_setup.hpp>
#include <iso15118/message_d2/session_stop.hpp>
#include <iso15118/message_d2/variant.hpp>

#include "catch2/matchers/catch_matchers.hpp"
#include "iso15118/message_d2/data_types/charge_progress_type.hpp"
#include "iso15118/message_d2/data_types/complex_types/charging_profile_type.hpp"
#include "iso15118/message_d2/data_types/complex_types/ev_evse_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/ev_power_delivery_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/evse_ev_charge_parameter_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/header_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/metering_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/security_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/service_related_types.hpp"
#include "iso15118/message_d2/data_types/complex_types/tariff_related_types.hpp"
#include "iso15118/message_d2/data_types/energy_transfer_type.hpp"
#include "iso15118/message_d2/data_types/evcc_id_type.hpp"
#include "iso15118/message_d2/data_types/evse_notification_type.hpp"
#include "iso15118/message_d2/data_types/evse_processing_type.hpp"
#include "iso15118/message_d2/data_types/fault_and_response_code_types.hpp"
#include "iso15118/message_d2/data_types/fault_msg_type.hpp"
#include "iso15118/message_d2/data_types/general_types.hpp"
#include "iso15118/message_d2/data_types/identification_number_types.hpp"
#include "iso15118/message_d2/data_types/multiplier_and_unit_types.hpp"
#include "iso15118/message_d2/data_types/only_dc_related_types.hpp"
#include "iso15118/message_d2/data_types/percent_value_type.hpp"
#include "iso15118/message_d2/data_types/security_types.hpp"
#include "iso15118/message_d2/data_types/session_id_type.hpp"
#include "iso15118/message_d2/data_types/tariffs_and_payment_types.hpp"

#include <vector>

using namespace iso15118;
using namespace iso15118::message_d2;

SCENARIO("PercentValueTypes can be validated.", "[iso15118, message_d2, data_types, PercentValueType]") {
    GIVEN("A valid percent value") {
        const auto value = 50;

        WHEN("A percent value is created") {
            const auto percent_value = data_types::PercentValue::Type{value};

            THEN("It should be comparable.") {
                REQUIRE(percent_value.to_base_type() == value);
            }
            THEN("It should be comparable to itself.") {
                REQUIRE(percent_value == percent_value);
            }
        }
    }
    GIVEN("An invalid percent value (too high)") {
        const auto value = 101;

        WHEN("A percent value is created") {
            THEN("It should throw an exception.") {
                REQUIRE_THROWS_AS(data_types::PercentValue::Type(value), std::invalid_argument);
                REQUIRE_THROWS_WITH(data_types::PercentValue::Type(value), "Percent value must be between 0 and 100.");
            }
        }
    }
    GIVEN("An invalid percent value (too low (but integer underflow))") {
        const auto value = -1;
        WHEN("A percent value is created") {
            THEN("It should throw an exception.") {
                REQUIRE_THROWS_AS(data_types::PercentValue::Type(value), std::invalid_argument);
                REQUIRE_THROWS_WITH(data_types::PercentValue::Type(value), "Percent value must be between 0 and 100.");
            }
        }
    }
}

SCENARIO("FaultMsgTypes can be validated.", "[iso15118, message_d2, data_types, FaultMsgType]") {
    GIVEN("A valid fault message") {
        const auto value = std::string{"This is a valid fault message."};

        WHEN("A fault message is created") {
            const auto fault_msg = data_types::FaultMsg::Type{value};

            THEN("It should be comparable.") {
                REQUIRE(fault_msg.to_base_type() == value);
            }

            THEN("It should be comparable to itself.") {
                REQUIRE(fault_msg == fault_msg);
            }
        }
    }

    GIVEN("An invalid fault message (too long)") {
        const auto value =
            std::string{"This is a fault message that is too long to be valid (I need to artificially make this "
                        "message a lot longer because it needs to be more than 65 characters)."};

        WHEN("A fault message is created") {
            THEN("It should throw an exception.") {
                REQUIRE_THROWS_AS(data_types::FaultMsg::Type(value), std::invalid_argument);
                REQUIRE_THROWS_WITH(data_types::FaultMsg::Type(value),
                                    "Fault message must be at most 64 characters long.");
            }
        }
    }
}

SCENARIO("EVSEProcessingTypes can be validated.", "[iso15118, message_d2, data_types, EVSEProcessingType]") {
    GIVEN("All valid EVSEProcessingTypes") {
        const auto finished_value = std::string{"Finished"};
        const auto ongoing_value = std::string{"Ongoing"};
        const auto ongoing_waiting_value = std::string{"Ongoing_WaitingForCustomerInteraction"};

        WHEN("The EVSEProcessingTypes are created") {
            const auto evse_processing_type_finished = data_types::EVSEProcessing::Type{finished_value};
            const auto evse_processing_type_ongoing = data_types::EVSEProcessing::Type{ongoing_value};
            const auto evse_processing_type_ongoing_waiting = data_types::EVSEProcessing::Type{ongoing_waiting_value};

            THEN("It should be comparable.") {
                REQUIRE(evse_processing_type_finished.to_base_type() == finished_value);
                REQUIRE(evse_processing_type_ongoing.to_base_type() == ongoing_value);
                REQUIRE(evse_processing_type_ongoing_waiting.to_base_type() == ongoing_waiting_value);
            }

            THEN("It should be comparable to itself.") {
                REQUIRE(evse_processing_type_finished == evse_processing_type_finished);
                REQUIRE(evse_processing_type_ongoing == evse_processing_type_ongoing);
                REQUIRE(evse_processing_type_ongoing_waiting == evse_processing_type_ongoing_waiting);
            }
        }
    }

    GIVEN("An invalid EVSEProcessingType message") {
        const auto invalid_value = std::string{"Something invalid."};

        WHEN("An EVSEProcessingType is created") {
            THEN("It should throw an exception.") {
                REQUIRE_THROWS_AS(data_types::EVSEProcessing::Type(invalid_value), std::invalid_argument);
                REQUIRE_THROWS_WITH(
                    data_types::EVSEProcessing::Type(invalid_value),
                    "Value must be one of the following: Finished, Ongoing, Ongoing_WaitingForCustomerInteraction.");
            }
        }
    }
}

SCENARIO("EVSENotificationTypes can be validated.", "[iso15118, message_d2, data_types, EVSENotifcationType]") {
    GIVEN("All valid EVSENotificationTypes") {
        const auto none_value = std::string{"None"};
        const auto stop_charging_value = std::string{"StopCharging"};
        const auto re_negotiation_value = std::string{"ReNegotiation"};

        WHEN("The EVSENotificationTypes are created") {
            const auto evse_notification_type_none = data_types::EVSENotification::Type{none_value};
            const auto evse_notification_type_stop_charging = data_types::EVSENotification::Type{stop_charging_value};
            const auto evse_notification_type_re_negotiation = data_types::EVSENotification::Type{re_negotiation_value};

            THEN("It should be comparable.") {
                REQUIRE(evse_notification_type_none.to_base_type() == none_value);
                REQUIRE(evse_notification_type_stop_charging.to_base_type() == stop_charging_value);
                REQUIRE(evse_notification_type_re_negotiation.to_base_type() == re_negotiation_value);
            }
        }
    }

    GIVEN("An invalid EVSENotificationType message") {
        const auto invalid_value = std::string{"Something invalid."};

        WHEN("An EVSENotificationType is created") {
            THEN("It should throw an exception.") {
                REQUIRE_THROWS_AS(data_types::EVSENotification::Type(invalid_value), std::invalid_argument);
                REQUIRE_THROWS_WITH(data_types::EVSENotification::Type(invalid_value),
                                    "Value must be one of the following: None, StopCharging, ReNegotiation.");
            }
        }
    }
}

SCENARIO("ChargeProgressTypes can be validated.", "[iso15118, message_d2, data_types, EVSENotifcationType]") {
    GIVEN("All valid ChargeProgressTypes") {
        const auto start_value = std::string{"Start"};
        const auto stop_value = std::string{"Stop"};
        const auto renegotiate_value = std::string{"Renegotiate"};

        WHEN("The ChargeProgressTypes are created") {
            const auto charge_progress_type_type_start = data_types::ChargeProgress::Type{start_value};
            const auto charge_progress_type_type_stop = data_types::ChargeProgress::Type{stop_value};
            const auto charge_progress_type_type_renegotiate = data_types::ChargeProgress::Type{renegotiate_value};

            THEN("It should be comparable.") {
                REQUIRE(charge_progress_type_type_start.to_base_type() == start_value);
                REQUIRE(charge_progress_type_type_stop.to_base_type() == stop_value);
                REQUIRE(charge_progress_type_type_renegotiate.to_base_type() == renegotiate_value);
            }
        }
    }

    GIVEN("An invalid ChargeProgressType message") {
        const auto invalid_value = std::string{"Something invalid."};

        WHEN("An ChargeProgressType is created") {
            THEN("It should throw an exception.") {
                REQUIRE_THROWS_AS(data_types::ChargeProgress::Type(invalid_value), std::invalid_argument);
                REQUIRE_THROWS_WITH(data_types::ChargeProgress::Type(invalid_value),
                                    "Value must be one of the following: Start, Stop, Renegotiate.");
            }
        }
    }
}

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

            for (uint8_t id = 0; id < iso15118::message_d2::data_types::EVCC_ID_LENGTH; id++) {
                REQUIRE(msg.evccid.at(id) == evccid.at(id));
            }
        }
    }
}
