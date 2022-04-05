cmake_minimum_required(VERSION 3.16)
project(out VERSION 1.0.0)

add_subdirectory(lib)
add_subdirectory(main)

set(MY_VAR "777")
message(STATUS "Output my variable in CMake: ${MY_VAR}")

if("FALSE")
    message(STATUS "FIRST IF: OK!")
else()
    message(STATUS "SECOND IF: OK!")
endif()
