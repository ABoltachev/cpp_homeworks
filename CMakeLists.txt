cmake_minimum_required(VERSION 3.16)

project(cpp_homeworks)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(stl main.cpp stllib/array/array.h stllib/array/array.tpp
                            stllib/vector/vector.h stllib/vector/vector.tpp
                            stllib/set/set.h stllib/set/set.tpp
                            stllib/algorithms/algorithms.h stllib/algorithms/algorithms.tpp)

