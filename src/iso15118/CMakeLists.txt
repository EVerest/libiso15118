if (TARGET fsm)
    # FIXME (aw): need to get proper way to deal with dependencies out of edm ...
else()
    message(STATUS "Target for libfsm not found, trying sibling folder ../libfsm")
    add_subdirectory(${PROJECT_SOURCE_DIR}/../libfsm ${CMAKE_CURRENT_BINARY_DIR}/libfsm)
endif()

find_package(Threads REQUIRED)

add_library(iso15118)
add_library(iso15118::iso15118 ALIAS iso15118)
target_include_directories(iso15118
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_sources(iso15118
    PRIVATE
        misc/helper.cpp
        misc/cb_exi.cpp

        io/connection_ssl.cpp
        io/connection_plain.cpp
        io/logging.cpp
        io/poll_manager.cpp
        io/sdp_packet.cpp
        io/sdp_server.cpp
        io/socket_helper.cpp

        session/feedback.cpp
        session/iso.cpp
        session/logger.cpp
        
        states/fsm.cpp
        states/context.cpp
        states/context_helper.cpp
        states/control_event_queue.cpp
        states/session.cpp
        states/config.cpp

        states/d20/supported_app_protocol.cpp
        states/d20/session_setup.cpp
        states/d20/authorization_setup.cpp
        states/d20/authorization.cpp
        states/d20/service_discovery.cpp
        states/d20/service_detail.cpp
        states/d20/service_selection.cpp
        states/d20/dc_charge_parameter_discovery.cpp
        states/d20/schedule_exchange.cpp
        states/d20/dc_cable_check.cpp
        states/d20/dc_pre_charge.cpp
        states/d20/power_delivery.cpp
        states/d20/dc_charge_loop.cpp
        states/d20/dc_welding_detection.cpp
        states/d20/session_stop.cpp

        states/d2/session_setup.cpp
        states/d2/authorization_setup.cpp
        states/d2/authorization.cpp
        states/d2/service_discovery.cpp
        states/d2/service_detail.cpp
        states/d2/service_selection.cpp
        states/d2/dc_charge_parameter_discovery.cpp
        states/d2/schedule_exchange.cpp
        states/d2/dc_cable_check.cpp
        states/d2/dc_pre_charge.cpp
        states/d2/power_delivery.cpp
        states/d2/dc_charge_loop.cpp
        states/d2/dc_welding_detection.cpp
        states/d2/session_stop.cpp

        message_d2/variant.cpp
        message_d2/session_setup.cpp
        message_d2/common.cpp
        message_d2/authorization_setup.cpp
        message_d2/authorization.cpp
        message_d2/service_discovery.cpp
        message_d2/service_detail.cpp
        message_d2/service_selection.cpp
        message_d2/dc_charge_parameter_discovery.cpp
        message_d2/schedule_exchange.cpp
        message_d2/dc_cable_check.cpp
        message_d2/dc_pre_charge.cpp
        message_d2/power_delivery.cpp
        message_d2/dc_charge_loop.cpp
        message_d2/dc_welding_detection.cpp
        message_d2/session_stop.cpp

        message_d20/variant.cpp
        message_d20/supported_app_protocol.cpp
        message_d20/session_setup.cpp
        message_d20/common.cpp
        message_d20/authorization_setup.cpp
        message_d20/authorization.cpp
        message_d20/service_discovery.cpp
        message_d20/service_detail.cpp
        message_d20/service_selection.cpp
        message_d20/dc_charge_parameter_discovery.cpp
        message_d20/schedule_exchange.cpp
        message_d20/dc_cable_check.cpp
        message_d20/dc_pre_charge.cpp
        message_d20/power_delivery.cpp
        message_d20/dc_charge_loop.cpp
        message_d20/dc_welding_detection.cpp
        message_d20/session_stop.cpp
        message_d20/ac_charge_parameter_discovery.cpp
        message_d20/ac_charge_loop.cpp

        tbd_controller.cpp    
)

if (NOT ISO15118_LINK_CUSTOM_MBEDTLS)
    set(MBEDTLS_LINK_DEPENDENCIES
        mbedtls
        mbedx509
        mbedcrypto
    )
else ()
    set(MBEDTLS_LINK_DEPENDENCIES
        mbedtls_custom
        mbedx509_custom
        mbedcrypto_custom
    )
endif ()

target_link_libraries(iso15118
    PUBLIC
        # FIXME (aw): would be nice if we could make this private!
        fsm::fsm
    PRIVATE
        Threads::Threads

        ${MBEDTLS_LINK_DEPENDENCIES}

        iso15118::v2gtp
        iso15118::exi_20
)

# FIXME (aw): do we want to have this public here?
target_compile_features(iso15118 PUBLIC cxx_std_17)
