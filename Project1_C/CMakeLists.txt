cmake_minimum_required(VERSION 3.8)
project(Project1_C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c Auditorium.h Auditorium.c)
add_executable(Project1_C ${SOURCE_FILES})