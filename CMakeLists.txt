cmake_minimum_required(VERSION 3.22)
project(homeworks_tests)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp stllib/array.hpp stllib/vector.hpp stllib/set.tpp stllib/set.hpp stllib/algorithms.hpp stllib/algorithms.tpp)
