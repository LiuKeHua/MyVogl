
option(VOGLTRACE_NO_PUBLIC_EXPORTS "Don't define any public GL exports in libvogltraceXX.so, this .so will only be useful for manual loading" FALSE)



include_directories(${CMAKE_CURRENT_BINARY_DIR})


set(SRC_LIST
    ${SRC_LIST}
    vogl_trace.cpp
    vogl_intercept.cpp
    # vogl_remote.cpp
    # ${SRC_DIR}/common/channel.cpp
    # ${SRC_DIR}/common/mtqueue.cpp
    # ${SRC_DIR}/common/channelmgr.cpp
    # ${SRC_DIR}/common/toclientmsg.cpp
    # ${SRC_DIR}/common/pinggame.cpp
)



if (VOGLTRACE_NO_PUBLIC_EXPORTS)
	message("libvogltrace.so will NOT define GL/GLX public exports")
    add_compiler_flag("-DNO_PUBLIC_EXPORTS")
else()
	message("libvogltrace.so will define GL/GLX public exports")
endif()

include_directories(
    ${LibBackTrace_INCLUDE}
    ${SRC_DIR}/extlib/loki/include/loki
    ${SRC_DIR}/voglcommon
    ${CMAKE_BINARY_DIR}/voglinc
    ${SRC_DIR}/voglcore
    ${SRC_DIR}/libtelemetry
    ${LibJpegTurbo_INCLUDE}
)



if (MSVC)
    if (BUILD_X64)
        set(SRC_LIST ${SRC_LIST} vogl_trace_x64.def)
    else()
        set(SRC_LIST ${SRC_LIST} vogl_trace_x86.def)
    endif()
endif()



SET(LIB_SOURCES
	${SRC_LIST}
)

SET(LIB_EXTERNAL_DEPS
	PTHREADS_LIBRARY
	JPEG_LIBRARY
)


SET(LIB_INTERNAL_DEPS
	voglcommon
	voglcore
)

SET(PROJECT_NAME vogltrace )
VSP_ADD_LIBRARY(${PROJECT_NAME})


add_dependencies(${PROJECT_NAME} voglgen_make_inc)

build_options_finalize()

