include(Catch)

add_executable(test_exi_session_setup session_setup.cpp)

target_link_libraries(test_exi_session_setup
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_session_setup)

add_executable(test_exi_authorization_setup authorization_setup.cpp)

target_link_libraries(test_exi_authorization_setup
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_authorization_setup)

add_executable(test_exi_authorization authorization.cpp)

target_link_libraries(test_exi_authorization
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_authorization)

add_executable(test_exi_service_discovery service_discovery.cpp)

target_link_libraries(test_exi_service_discovery
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_service_discovery)

add_executable(test_exi_service_detail service_detail.cpp)

target_link_libraries(test_exi_service_detail
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_service_detail)

add_executable(test_exi_service_selection service_selection.cpp)

target_link_libraries(test_exi_service_selection
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_service_selection)

add_executable(test_exi_dc_charge_parameter dc_charge_parameter_discovery.cpp)

target_link_libraries(test_exi_dc_charge_parameter
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_dc_charge_parameter)

# add_executable(test_exi_schedule_exchange schedule_exchange.cpp)

# target_link_libraries(test_exi_schedule_exchange
#     PRIVATE
#         iso15118
#         Catch2::Catch2WithMain
# )

# catch_discover_tests(test_exi_schedule_exchange)

add_executable(test_exi_dc_cable_check dc_cable_check.cpp)

target_link_libraries(test_exi_dc_cable_check
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_dc_cable_check)

add_executable(test_exi_dc_pre_charge dc_pre_charge.cpp)

target_link_libraries(test_exi_dc_pre_charge
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_dc_pre_charge)

add_executable(test_exi_power_delivery power_delivery.cpp)

target_link_libraries(test_exi_power_delivery
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_power_delivery)

add_executable(test_exi_dc_charge_loop dc_charge_loop.cpp)

target_link_libraries(test_exi_dc_charge_loop
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_dc_charge_loop)

add_executable(test_exi_dc_welding_detection dc_welding_detection.cpp)

target_link_libraries(test_exi_dc_welding_detection
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_dc_welding_detection)

add_executable(test_exi_session_stop session_stop.cpp)

target_link_libraries(test_exi_session_stop
    PRIVATE
        iso15118
        Catch2::Catch2WithMain
)

catch_discover_tests(test_exi_session_stop)
