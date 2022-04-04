cmake_minimum_required(VERSION 3.16)
project(out VERSION 1.0.0)

add_library(
    some-output
    SHARED
        output.h
        output.cpp
)

add_executable(out main.cpp)

target_link_libraries(out PRIVATE some-output)
