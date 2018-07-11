cmake_minimum_required(VERSION 3.10)
project(MatrixTemplate)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES main.cpp MatrixTemplate.h UtilsMatrixTemplate.h)
add_executable(MatrixTemplate ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries(MatrixTemplate core)