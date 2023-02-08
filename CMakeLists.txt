cmake_minimum_required(VERSION 3.16)

project(homeworks_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp)

add_library(containers_lib containers/array.cpp containers/vector.cpp)

target_link_libraries(main containers_lib)
