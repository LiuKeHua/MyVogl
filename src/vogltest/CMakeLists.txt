
SET(PROJECT_NAME vogltest)
set(SRC_LIST
    vogltest.cpp
    voglcoretest.cpp
)


SET(TARGET_SRC
	${SRC_LIST}
)

SET(LIB_EXTERNAL_DEPS

	PTHREADS_LIBRARY
	JPEG_LIBRARY
	SDL2_LIBRARY
)

SET(LIB_INTERNAL_DEPS
	voglcore
)

VSP_ADD_EXE(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
	opengl32.lib
	glu32.lib
)

if (TARGET SDL)
    add_dependencies(${PROJECT_NAME} SDL)
endif ()



build_options_finalize()

