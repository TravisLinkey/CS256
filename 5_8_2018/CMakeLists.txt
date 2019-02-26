cmake_minimum_required(VERSION 3.8)
project(5_8_2018)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp PersonData.cpp PersonData.h CustomerData.cpp CustomerData.h PreferredCustomer.cpp PreferredCustomer.h)
add_executable(5_8_2018 ${SOURCE_FILES})