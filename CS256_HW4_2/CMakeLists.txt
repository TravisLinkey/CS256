cmake_minimum_required(VERSION 3.8)
project(_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ParkedCar.cpp ParkedCar.h ParkingMeter.cpp ParkingMeter.h ParkingTicket.cpp ParkingTicket.h PoliceOfficer.cpp PoliceOfficer.h)
add_executable(_2 ${SOURCE_FILES})