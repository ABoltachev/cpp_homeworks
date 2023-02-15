cmake_minimum_required(VERSION 3.24)
project(stl)

set(CMAKE_CXX_STANDARD 17)

add_executable(stl main.cpp array/array.h array/array.tpp vector/vector.h vector/vector.tpp set/set.h set/set.tpp algorithms/algorithms.h algorithms/algorithms.tpp)
