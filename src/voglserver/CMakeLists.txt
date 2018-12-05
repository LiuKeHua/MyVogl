
SET(PROJECT_NAME voglserver)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(MySources 
    server.cpp 
    ${SRC_DIR}/common/channel.cpp
    ${SRC_DIR}/common/channelmgr.cpp
    ${SRC_DIR}/common/mtqueue.cpp
    ${SRC_DIR}/common/launchsteamgame.cpp
    ${SRC_DIR}/common/toclientmsg.cpp
    ${SRC_DIR}/common/listfiles.cpp
    )


include_directories(
    ${SRC_DIR}/voglcore
    )



	
SET(TARGET_SRC
	${MySources}
)

SET(LIB_EXTERNAL_DEPS

	
)

SET(LIB_INTERNAL_DEPS
	voglcore
)

VSP_ADD_EXE(${PROJECT_NAME})




target_link_libraries(${PROJECT_NAME}
    ${CMAKE_THREAD_LIBS_INIT}
    rt
    voglcore)

build_options_finalize()

