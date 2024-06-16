set(INSTALL_PATH "modules/graphics/opengl")
pr_install_create_directory("${INSTALL_PATH}")
pr_install_targets(pr_prosper_opengl prosper_opengl INSTALL_DIR "${INSTALL_PATH}")
