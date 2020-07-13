cmake_minimum_required(VERSION 3.10)
project(project2)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(tests)
add_executable(project2.out src/main.cpp)
