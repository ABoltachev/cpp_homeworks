cmake_minimum_required(VERSION 3.16)

project(homeworks_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(AddressBookOperators)

add_library(AddressBookLib STATIC
        AddressBookOperators/AddressBookLib.cpp
        AddressBookOperators/Employee.cpp
        )

add_executable(main main.cpp)

target_link_libraries(main AddressBookLib)