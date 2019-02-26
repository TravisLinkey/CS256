cmake_minimum_required(VERSION 3.8)
project(CS256_HW4_3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Ship.cpp Ship.h CruiseShip.cpp CruiseShip.h CargoShip.cpp CargoShip.h)
add_executable(CS256_HW4_3 ${SOURCE_FILES})