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

        # FIXME (aw): distinction between 'misc' and 'shared' is not clear!
        shared/fsm_logger.cpp

        io/connection_ssl.cpp
        io/connection_plain.cpp
        io/logging.cpp
        io/poll_manager.cpp
        io/sdp_packet.cpp
        io/sdp_server.cpp
        io/socket_helper.cpp

        session/iso.cpp
        session/logger.cpp
        
        d20/fsm.cpp
        d20/context.cpp
        d20/context_helper.cpp
        d20/session.cpp
        d20/config.cpp

        d20/state/supported_app_protocol.cpp
        d20/state/session_setup.cpp
        d20/state/authorization_setup/handle_request.cpp
        d20/state/authorization_setup/transition.cpp
        d20/state/authorization/handle_request.cpp
        d20/state/authorization/transition.cpp
        d20/state/service_discovery/handle_request.cpp
        d20/state/service_discovery/transition.cpp
        d20/state/service_detail/handle_request.cpp
        d20/state/service_detail/transition.cpp
        d20/state/service_selection/handle_request.cpp
        d20/state/service_selection/transition.cpp
        d20/state/dc_charge_parameter_discovery/handle_request.cpp
        d20/state/dc_charge_parameter_discovery/transition.cpp
        d20/state/schedule_exchange/handle_request.cpp
        d20/state/schedule_exchange/transition.cpp
        d20/state/dc_cable_check/handle_request.cpp
        d20/state/dc_cable_check/transition.cpp
        d20/state/dc_pre_charge/handle_request.cpp
        d20/state/dc_pre_charge/transition.cpp
        d20/state/power_delivery/handle_request.cpp
        d20/state/power_delivery/transition.cpp
        d20/state/dc_charge_loop/handle_request.cpp
        d20/state/dc_charge_loop/transition.cpp

        message/variant.cpp
        message/supported_app_protocol.cpp
        message/session_setup.cpp
        message/common.cpp
        message/authorization_setup.cpp
        message/authorization.cpp
        message/service_discovery.cpp
        message/service_detail.cpp
        message/service_selection.cpp
        message/dc_charge_parameter_discovery.cpp
        message/schedule_exchange.cpp
        message/dc_cable_check.cpp
        message/dc_pre_charge.cpp
        message/power_delivery.cpp
        message/dc_charge_loop.cpp

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
