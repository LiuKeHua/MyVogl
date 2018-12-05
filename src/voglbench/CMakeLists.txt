

include_directories(
    ${LibBackTrace_INCLUDE}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${SRC_DIR}/voglcore
    ${CMAKE_BINARY_DIR}/voglinc
    ${SRC_DIR}/voglcommon
    ${SRC_DIR}/libtelemetry
    ${SRC_DIR}/extlib/loki/include/loki
    ${SDL2_INCLUDE}
)

set(SRC_LIST
    voglbench.cpp
)


SET(TARGET_SRC
	${SRC_LIST}
)

SET(LIB_EXTERNAL_DEPS
	SDL2_LIBRARY
	
)

SET(LIB_INTERNAL_DEPS
	voglcore
	voglcommon
)
SET(PROJECT_NAME voglbench)
VSP_ADD_EXE(${PROJECT_NAME})


add_dependencies(${PROJECT_NAME} voglgen_make_inc)
if (TARGET SDL)
    add_dependencies(${PROJECT_NAME} SDL)
endif ()


build_options_finalize()
