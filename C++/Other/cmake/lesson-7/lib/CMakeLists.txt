project(lib VERSION 1.0.0)

add_library(
    some-output
    SHARED
        src/output/output.h
        src/output/output.cpp
)

target_include_directories(some-output PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_compile_definitions(some-output PUBLIC SOME_RANDOM_STUFF=69)
