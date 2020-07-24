cmake_minimum_required(VERSION 3.16)

project(dynamic_2d_array)

# VARS
set(CPP_COMPILE_FLAGS "-g -O0 -Wall -Wextra -fsanitize=address")

# specify the C standard
# set(CMAKE_CPP_COMPILER /usr/bin/clang)
set(CMAKE_CPP_STANDARD 14)
set(CMAKE_CPP_STANDARD_REQUIRED True)

set(CMAKE_CPP_FLAGS "${CMAKE_C_FLAGS} ${C_COMPILE_FLAGS}")

add_executable(tests tests.cpp Ocean.h PRNG.h WarBoats.h Ocean.cpp PRNG.cpp)
add_executable(driver-sample driver-sample.cpp Ocean.h PRNG.h WarBoats.h Ocean.cpp PRNG.cpp)
add_executable(driver-big driver-big.cpp Ocean.h PRNG.h WarBoats.h Ocean.cpp PRNG.cpp)
add_executable(warboats main.cpp Ocean.h PRNG.h WarBoats.h Ocean.cpp PRNG.cpp)
