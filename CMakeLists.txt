cmake_minimum_required(VERSION 3.17)
project(A2BlackJack)

set(CMAKE_CXX_STANDARD 14)

add_executable(A2BlackJack private/main.cpp private/deck.cpp public/deck.h private/input.cpp public/input.h)