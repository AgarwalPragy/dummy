cmake_minimum_required(VERSION 3.22)
project(kd)

set(CMAKE_CXX_STANDARD 14)


add_executable(kd
        main.cpp
        class.cpp
        lib.cpp)

target_include_directories(kd PRIVATE "/usr/include/python3.10/")
target_link_libraries(kd "python3.10")