cmake_minimum_required(VERSION 3.10)
project(tga_transformation)

set(CMAKE_CXX_STANDARD 11)

add_executable(main src/main.cpp)
add_executable(run_tests tests/tests.cpp)
