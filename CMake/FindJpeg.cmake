
SET(PTHREADS_ROOT "" CACHE PATH "The root of the VRPN_ROOT")


if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(_lib_suffix lib_x64)
else()
	set(_lib_suffix lib_x86)
endif()



FIND_PATH(JPEG_INCLUDE_DIR jpeglib.h
  PATH_SUFFIXES inc include Frameworks 
  HINTS
  ${PROJECT_SOURCE_DIR}/ThirdParty/libjpeg-turbo-2.1.3
  )
MARK_AS_ADVANCED(JPEG_INCLUDE_DIR)

MACRO(FIND_JPEG_LIBRARY MYLIBRARY MYLIBRARYNAME)  
  FIND_LIBRARY(${MYLIBRARY}
    NAMES ${MYLIBRARYNAME}
    PATH_SUFFIXES ${_lib_suffix}  lib/${_lib_suffix} 
    PATHS
	${PROJECT_SOURCE_DIR}/ThirdParty/libjpeg-turbo-2.1.3
    )
  MARK_AS_ADVANCED(${MYLIBRARY})
ENDMACRO(FIND_JPEG_LIBRARY LIBRARY LIBRARYNAME)


# Find release (optimized) libs

FIND_JPEG_LIBRARY(JPEG_LIBRARY  turbojpeg)


# Find debug libs

FIND_JPEG_LIBRARY(JPEG_LIBRARY_DEBUG turbojpeg)


if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(JPEG_SRC_DLL "${PROJECT_SOURCE_DIR}/ThirdParty/libjpeg-turbo-2.1.3/bin_x64/turbojpeg.dll" )
else()
    set(JPEG_SRC_DLL "${PROJECT_SOURCE_DIR}/ThirdParty/libjpeg-turbo-2.1.3/bin_x86/turbojpeg.dll" )
endif()
