
SET(MyCategory MyTest)

FIND_PACKAGE(SDL2)
FIND_PACKAGE(JPEG)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/voglcore
	${SDL2_INCLUDE_DIR}
	${JPEG_INCLUDE_DIR}
)


if (MSVC)
    set (PTHREAD_DEST ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR})

    add_custom_target(copy_deps ALL
                      ${CMAKE_COMMAND} -E make_directory ${PTHREAD_DEST}
                      COMMAND ${CMAKE_COMMAND} -E copy_if_different ${PTHREAD_SRC_DLL} ${PTHREAD_DEST}
					  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${JPEG_SRC_DLL} ${PTHREAD_DEST}
					  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SDL2_SRC_DLL} ${PTHREAD_DEST}
                      COMMENT "Copying necessary DLLs to output directory ."
                      VERBATIM
    )
endif()



add_subdirectory(extlib/pxfmt)
add_subdirectory(voglcore) # 1
add_subdirectory(voglgen) # 2
add_subdirectory(voglcommon) # 3
add_subdirectory(voglreplay) # 4
add_subdirectory(voglbench) # 5
add_subdirectory(vogltrace) # 6
add_subdirectory(vogltest) # 7
add_subdirectory(glxspheres) # 8
add_subdirectory(vogleditor) # 9
#add_subdirectory(voglserver) # 9

add_subdirectory(ktxtool) # 13
