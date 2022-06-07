cmake_minimum_required(VERSION 3.22)
project(trial)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_OSX_ARCHITECTURES "x86_64")

add_library(
        trial SHARED
        src/booking/booking.cpp
        src/booking/py_booking.cpp
        src/strategies/allot_first.cpp
        src/strategies/allot_last.cpp
)
