cmake_minimum_required(VERSION 3.15)

cmake_minimum_required(VERSION 3.15)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# setup project with root folder name
get_filename_component(ROOT_PROJECT_NAME ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(ROOT_PROJECT_NAME ${ROOT_PROJECT_NAME} NAME)
get_filename_component(VIEW_NAME ${CMAKE_SOURCE_DIR} NAME)
project(${ROOT_PROJECT_NAME}_${VIEW_NAME})

SET(CONAN_DISABLE_CHECK_COMPILER true)

enable_testing()

include(${CMAKE_BINARY_DIR}/conanworkspace.cmake)
conan_workspace_subdirectories()