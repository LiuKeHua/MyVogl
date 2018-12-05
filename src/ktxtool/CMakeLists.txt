
include_directories(
    ${SRC_DIR}/voglcore
    ${SRC_DIR}/extlib/pxfmt
    ${SRC_DIR}/extlib/include
    )

include_directories(
    ${SRC_DIR}/voglcore
    ${CMAKE_BINARY_DIR}/voglinc
    )

set(SRC_LIST
    ${SRC_LIST}
    ktxtool.cpp
)


SET(TARGET_SRC
	${SRC_LIST}
)

SET(LIB_EXTERNAL_DEPS
	PTHREADS_LIBRARY
)


SET(LIB_INTERNAL_DEPS
    voglcore
    pxfmt
)

SET(PROJECT_NAME ktxtool )
VSP_ADD_EXE(${PROJECT_NAME})


build_options_finalize()

