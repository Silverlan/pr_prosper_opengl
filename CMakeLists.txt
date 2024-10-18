include(${CMAKE_SOURCE_DIR}/cmake/pr_common.cmake)

set(PROJ_NAME pr_prosper_opengl)
pr_add_library(${PROJ_NAME} SHARED)

pr_add_dependency(${PROJ_NAME} client TARGET PUBLIC)

add_subdirectory(external_libs/prosper_opengl)
pr_add_dependency(${PROJ_NAME} prosper_opengl TARGET PUBLIC)

pr_add_headers(${PROJ_NAME} "include/")
pr_add_sources(${PROJ_NAME} "src/")


pr_set_target_folder(prosper_opengl modules/rendering/opengl)
pr_set_target_folder(glad modules/rendering/opengl)

pr_finalize(${PROJ_NAME} FOLDER modules/rendering/opengl)
