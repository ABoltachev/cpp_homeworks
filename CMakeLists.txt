cmake_minimum_required(VERSION 3.16)

project(homeworks_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp)

add_library(stllib_lib stllib/array.cpp stllib/vector.cpp stllib/set.hpp stllib/algorithms.hpp)

target_link_libraries(main stllib_lib)
