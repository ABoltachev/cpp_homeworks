cmake_minimum_required(VERSION 3.16)

project(homeworks_tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp addressbook.cpp)
