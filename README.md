ISO 15118 library suite
=======================

Currently, this is a proof of concept library.  Therefore it is located
in the branch `dash-20-dash-20-poc`.

RB:
This is a branch of the dash-20-poc, using cbexigen and the new framework built on top of cbexigen.

What I did was to take the dash-20-poc tbd_controller for ISO-15118-20 and make two copies of the controller and of the
message handlers and state machine. The first copy simply handles
the SupportAppProtocol message so that the code for either ISO20 or ISO2 will handle the charging session

The other copy implements the rest of the ISO2 messages. The overall idea was to keep most of the ISO20 state machine code the same
as much as possible, but translate the ISO2 messages in the message handlers. This worked reasonably well, but some of the
state code needed major rework as the ISO2 behavior and information was quite different. For example, the ../iso15118/d2/state/dc_cable_check.cpp and .hpp
are identical to ../iso15118/d20/state/dc_cable_check.cpp and .hpp, but the service discovery code is quite different.

The structure is as follows:

There are now three tbd_controllers:

tbd_controller_d2_sap
tbd_controller_d2
tbd_controller_d20 

which are called from the D20EVSE EVerest module like this:

    while (true) {
        try {
            // RDB - switch between the three controllers
            if (SAP_Version == -1) {

                controller_2_sap->loop();
                // RDB At this point, the SDP is handled, and the IConnection is made. Give these to either ISO2 or
                // ISO20 depending on the SAP outcome
                SAP_Version = controller_2_sap->get_SAP_Version();

                // RDB - set up the selected controller to take over
                if (SAP_Version == 20) {
                    controller_20->set_SAP_IConnection(controller_2_sap->get_SAP_IConnection());
                    controller_20->set_PollManager(controller_2_sap->GetPollManager());
                } else if (SAP_Version == 2) {
                    controller_2->set_SAP_IConnection(controller_2_sap->get_SAP_IConnection());
                    controller_2->set_PollManager(controller_2_sap->GetPollManager());
                }
            } else if (SAP_Version == 20) {
                controller_20->loop();
            } else if (SAP_Version == 2) {
                controller_2->loop();
            } else {
                throw("Unsupported SAP version");
            }
        } catch (const std::exception& e) {
            EVLOG_error << "D20Evse crashed: " << e.what();
            publish_dlink_error(nullptr);
        }

Then there are three copies of the state machine, each with their own namespace
namespace iso15118::d2_sap::state
namespace iso15118::d2::state
namespace iso15118::d20::state

and three copies of the message handlers, each with their own namespace
namespace iso15118::message_2_sap
namespace iso15118::message_2
namespace iso15118::message_20

The naming mostly applies to the folder structure as well, but here some improvements could be made.

This is very much a rough draft, and needs a lot of tidying up, for example in the switching between protocols, I've
just put if (false) to force the ISO2 handler, and take this out to force the ISO20 handler. 
I've tried to mark obvious problems with RDB TODO comments.

static auto handle_request(const message_2_sap::SupportedAppProtocolRequest& req) {
    message_2_sap::SupportedAppProtocolResponse res;

    //RDB Decide here which app protocol to use. Send it back in res.SAP_Version
    for (const auto& protocol : req.app_protocol) {
        if (false){//protocol.protocol_namespace.compare("urn:iso:std:iso:15118:-20:DC") == 0) {
            res.schema_id = protocol.schema_id;
            res.SAP_Version = 20;
            return response_with_code(
                res, message_2_sap::SupportedAppProtocolResponse::ResponseCode::OK_SuccessfulNegotiation);
        } 
        else if (protocol.protocol_namespace.compare("urn:iso:15118:2:2013:MsgDef") == 0) {
            res.schema_id = protocol.schema_id;
            res.SAP_Version = 2;
            return response_with_code(
                res, message_2_sap::SupportedAppProtocolResponse::ResponseCode::OK_SuccessfulNegotiation);
        }
    }

    return response_with_code(res, message_2_sap::SupportedAppProtocolResponse::ResponseCode::Failed_NoNegotiation);
}

However both paths mostly work when run with the basic DC Josev car simulator. There are hacks here and there in the ISO2 code to 
make Josev happy for ISO2, but the ISO20 code is the same as the dash-20-poc.