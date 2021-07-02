cmake_minimum_required(VERSION 3.12)

include("../CMakeShared.txt")

set(PROJ_NAME pr_prosper_opengl)

project(${PROJ_NAME} CXX)

# set(PRECOMPILED_HEADER "stdafx")

link_external_library(iclient)
link_external_library(glfw)
link_external_library(iglfw)
link_external_library(prosper)
link_external_library(prosper_opengl)
link_external_library(client)
link_external_library(wgui)
add_external_library(luajit)
if(WIN32)
	add_external_library(lua)
endif()

add_include_dir(glm)
add_include_dir(alsoundsystem)
add_include_dir(materialsystem)
add_include_dir(cmaterialsystem)

add_def(ALSYS_LIBRARY_TYPE)

link_generic_module_libraries()
register_pragma_module(${PROJ_NAME})

add_subdirectory(external_libs/prosper_opengl)

#

set(DEPENDENCY_PROSPER_OPENGL_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/external_libs/prosper_opengl/include CACHE PATH "Path to include directory.")
search_lib_recursive_ext(DEPENDENCY_PROSPER_OPENGL_LIBRARY prosper_opengl)
set(DEPENDENCY_GLAD_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/external_libs/prosper_opengl/third_party_libs/glad/include CACHE PATH "Path to include directory.")

#

add_dependencies(${PROJ_NAME} prosper_opengl prosper)

set_target_properties(pr_prosper_opengl PROPERTIES FOLDER modules/graphics/opengl)
set_target_properties(prosper_opengl PROPERTIES FOLDER modules/graphics/opengl)

set_property(GLOBAL PROPERTY PRAGMA_MODULE_SKIP_TARGET_PROPERTY_FOLDER 1)
