cmake_minimum_required(VERSION 3.22)
project(trial)

set(CMAKE_CXX_STANDARD 23)

add_library(
        trial SHARED
        src/booking/booking.cpp
        src/strategies/allot_first.h
        src/strategies/allot_last.h
)
