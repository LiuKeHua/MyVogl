
FIND_PACKAGE(SDL2)

include_directories(
    ${SRC_DIR}/extlib/loki/include/loki
    ${SRC_DIR}/voglcommon
    ${CMAKE_BINARY_DIR}/voglinc
    ${SRC_DIR}/voglcore
    ${SRC_DIR}/libtelemetry
    ${LibBackTrace_INCLUDE}
    ${SDL2_INCLUDE_DIR}
)

file( GLOB_RECURSE HDRS *.[h|inl] )

set(SRC_LIST
    ${SRC_LIST}
    ${HDRS}
	gl_types.cpp
    vogl_ctypes.cpp
    vogl_gl_utils.cpp
    vogl_entrypoints.cpp
    vogl_trace_packet.cpp
    vogl_trace_file_reader.cpp
    vogl_trace_file_writer.cpp
    vogl_context_info.cpp
    vogl_blob_manager.cpp
    vogl_texture_state.cpp
    vogl_general_context_state.cpp
    vogl_fbo_state.cpp
    vogl_renderbuffer_state.cpp
    vogl_state_vector.cpp
    vogl_texture_format.cpp
    vogl_sampler_state.cpp
    vogl_buffer_state.cpp
    vogl_query_state.cpp
    vogl_shader_state.cpp
    vogl_program_state.cpp
    vogl_fs_preprocessor.cpp
    vogl_gl_object.cpp
    vogl_gl_state_snapshot.cpp
    vogl_vao_state.cpp
    vogl_sso_state.cpp
    vogl_sync_object.cpp
    vogl_replay_window.cpp
    vogl_gl_replayer.cpp
    vogl_framebuffer_capturer.cpp
    vogl_material_state.cpp
    vogl_light_state.cpp
    vogl_texenv_state.cpp
    vogl_display_list_state.cpp
    vogl_matrix_state.cpp
    vogl_image_formats.inc
    vogl_common.cpp
    vogl_current_vertex_attrib_state.cpp
    vogl_arb_program_state.cpp
    gl_gets.inc
    vogl_handle_tracker.cpp
    vogl_default_framebuffer_state.cpp
    vogl_default_framebuffer_state.h
    vogl_shader_utils.cpp
    vogl_shader_utils.h
    vogl_msaa_texture.cpp
    vogl_msaa_texture.h
)


SET(LIB_SOURCES
	${SRC_LIST}
)

SET(LIB_EXTERNAL_DEPS
	SDL2_LIBRARY
)


SET(LIB_INTERNAL_DEPS

)

SET(PROJECT_NAME voglcommon )
VSP_ADD_LIBRARY(${PROJECT_NAME} STATIC)




add_dependencies(${PROJECT_NAME} voglgen_make_inc)



build_options_finalize()

