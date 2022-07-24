cmake_minimum_required(VERSION 3.15)

project(DesignPatterns VERSION 2.0)

SET(CONAN_DISABLE_CHECK_COMPILER true)

include(${CMAKE_BINARY_DIR}/conanworkspace.cmake)
conan_workspace_subdirectories()