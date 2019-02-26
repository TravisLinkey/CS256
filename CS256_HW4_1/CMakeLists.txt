cmake_minimum_required(VERSION 3.8)
project(_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp dice.cpp dice.h Blackjack.cpp Blackjack.h)
add_executable(_1 ${SOURCE_FILES})