if ((NOT USING_OPENSSL) AND ISO15118_LINK_CUSTOM_MBEDTLS)
    add_subdirectory(mbedtls)
endif ()
