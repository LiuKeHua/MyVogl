
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
)

include_directories(
    ${SRC_DIR}/voglcore
    ${CMAKE_BINARY_DIR}/voglinc
    ${SRC_DIR}/voglcommon
    ${SRC_DIR}/libtelemetry
    ${SRC_DIR}/extlib/loki/include/loki
    ${SDL2_INCLUDE}
)

set(SRC_LIST
    ${SRC_LIST}
    vogl_replay_tool.cpp
    replay_tool_dump.cpp
    replay_tool_parse.cpp
    replay_tool_info.cpp
    replay_tool_json.cpp
    replay_tool_find.cpp
    replay_tool_compare_hash.cpp
    replay_tool_replay.cpp
    replay_tool_syms.cpp
    replay_tool_trace.cpp
#    vogl_remote.cpp
#    ../common/channel.cpp
)

# add_compiler_flag("-DVOGL_REMOTING")


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

SET(PROJECT_NAME voglreplay )

VSP_ADD_EXE(${PROJECT_NAME})


add_dependencies(${PROJECT_NAME} voglgen_make_inc)


build_options_finalize()

