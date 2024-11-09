#include <cstdio>
#include <memory>

#include <iso15118/io/logging.hpp>
#include <iso15118/session/logger.hpp>
#include <iso15118/tbd_controller.hpp>

int main(int, char**) {
    using namespace iso15118;

    std::unique_ptr<TbdController> controller;

    session::logging::set_session_log_callback([](std::size_t, const session::logging::Event& event) {
        if (const auto* simple_event = std::get_if<session::logging::SimpleEvent>(&event)) {
            printf("log(session: simple event): %s\n", simple_event->info.c_str());
        } else {
            printf("log(session): not decoded\n");
        }
    });

    io::set_logging_callback(
        [](LogLevel level, std::string message) { printf("log(%d): %s\n", static_cast<int>(level), message.c_str()); });

    // setup config
    TbdConfig tbd_config{};
    tbd_config.interface_name = "auto";
    tbd_config.tls_negotiation_strategy = config::TlsNegotiationStrategy::ENFORCE_TLS;
    tbd_config.ssl.config_string = "/workspace/libiso15118/test/certs";
    tbd_config.ssl.private_key_password = "123456";

    session::feedback::Callbacks feedback_cbs{};
    feedback_cbs.signal = [&controller](session::feedback::Signal signal) {
        using Signal = session::feedback::Signal;
        if (signal == Signal::REQUIRE_AUTH_EIM) {
            controller->send_control_event(d20::AuthorizationResponse(true));
        } else if (signal == Signal::REQUIRE_AUTH_PNC) {
            controller->send_control_event(d20::AuthorizationResponse(true));
        } else if (signal == Signal::START_CABLE_CHECK) {
            controller->send_control_event(d20::CableCheckFinished(true));
        } else if (signal == Signal::DC_OPEN_CONTACTOR) {
            controller->send_control_event(d20::PresentVoltageCurrent{400, 100});
        }
    };
    feedback_cbs.dc_pre_charge_target_voltage = [](auto) {};
    feedback_cbs.dc_charge_loop_req = [](auto) {};
    feedback_cbs.dc_max_limits = [](auto) {};
    feedback_cbs.v2g_message = [](auto) {};
    feedback_cbs.evccid = [](auto) {};
    feedback_cbs.selected_protocol = [](auto) {};

    feedback_cbs.v2g_message = [](auto) {};

    d20::EvseSetupConfig evse_config{};
    evse_config.supported_energy_services.push_back(message_20::ServiceCategory::DC_BPT);
    evse_config.authorization_services.push_back(message_20::Authorization::PnC);
    evse_config.dc_limits.discharge_limits = []() {
        using RN = message_20::RationalNumber;
        d20::Limits discharge;
        discharge.power.min = RN{0, 0};
        discharge.power.max = RN{150, 3};
        discharge.current.min = RN{0, 0};
        discharge.current.max = RN{300, 0};

        return discharge;
    }();

    controller =
        std::make_unique<TbdController>(std::move(tbd_config), std::move(feedback_cbs), std::move(evse_config));

    controller->loop();

    return 0;
}
