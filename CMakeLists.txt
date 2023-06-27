cmake_minimum_required(VERSION 3.5)
project(MatrixTemplate)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES MatrixTemplate.cpp MatrixTemplate.h UtilsMatrixTemplate.h)
add_executable(MatrixTemplate main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(MatrixTemplate core)