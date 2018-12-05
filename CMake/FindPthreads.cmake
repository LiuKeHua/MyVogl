
SET(PTHREADS_ROOT "" CACHE PATH "The root of the VRPN_ROOT")


if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(_lib_suffix x64)
else()
	set(_lib_suffix x86)
endif()



FIND_PATH(pThreads_INCLUDE_DIR pthread.h
  PATH_SUFFIXES inc include Frameworks 
  HINTS
  ${PROJECT_SOURCE_DIR}/ThirdParty/pthreads.2
  )
MARK_AS_ADVANCED(pThreads_INCLUDE_DIR)

MACRO(FIND_PTHREADS_LIBRARY MYLIBRARY MYLIBRARYNAME)  
  FIND_LIBRARY(${MYLIBRARY}
    NAMES ${MYLIBRARYNAME}
    PATH_SUFFIXES lib lib/${_lib_suffix} 
    PATHS
	${PROJECT_SOURCE_DIR}/ThirdParty/pthreads.2
    )
  MARK_AS_ADVANCED(${MYLIBRARY})
ENDMACRO(FIND_PTHREADS_LIBRARY LIBRARY LIBRARYNAME)


# Find release (optimized) libs

FIND_PTHREADS_LIBRARY(PTHREADS_LIBRARY  pthreadVC2)


# Find debug libs

FIND_PTHREADS_LIBRARY(PTHREADS_LIBRARY_DEBUG pthreadVC2)


if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(PTHREAD_SRC_LIB "${PROJECT_SOURCE_DIR}/ThirdParty/pthreads.2/lib/x64/pthreadVC2.lib" )
    set(PTHREAD_SRC_DLL "${PROJECT_SOURCE_DIR}/ThirdParty/pthreads.2/dll/x64/pthreadVC2.dll" )
else()
    set(PTHREAD_SRC_LIB "${PROJECT_SOURCE_DIR}/ThirdParty/pthreads.2/lib/x86/pthreadVC2.lib" )
    set(PTHREAD_SRC_DLL "${PROJECT_SOURCE_DIR}/ThirdParty/pthreads.2/dll/x86/pthreadVC2.dll" )
endif()
