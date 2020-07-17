cmake_minimum_required(VERSION 3.10)
project(main)

set(CMAKE_CXX_STANDARD 14)

add_executable(main src/main.cpp)
add_executable(run_tests tests/tests.cpp)
