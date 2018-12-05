

include_directories(
    "${SRC_DIR}/extlib/include"
    )

set(SRC_LIST
    ${SRC_LIST}
    pxfmt.cpp
    pxfmt.h
    pxfmt_fxt1.cpp
    pxfmt_s3tc.cpp
    pxfmt_etc.cpp
    pxfmt_internal.h
    pxfmt_internal.cpp
    pxfmt_dlopen.h
    pxfmt_gl.h
    pxfmt_case_statements.inl
    texcompress_etc_tmp.h
)


SET(LIB_SOURCES
	${SRC_LIST}
)

SET(LIB_EXTERNAL_DEPS
	
)


SET(LIB_INTERNAL_DEPS

)

SET(PROJECT_NAME pxfmt )
VSP_ADD_LIBRARY(${PROJECT_NAME} STATIC)



build_options_finalize()

