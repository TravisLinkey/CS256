cmake_minimum_required(VERSION 3.10)
project(Exception_Handling)

set(CMAKE_CXX_STANDARD 11)

add_executable(Exception_Handling main.cpp Employee.cpp Employee.h ProductionWorker.cpp ProductionWorker.h IO.cpp IO.h)