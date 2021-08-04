cmake_minimum_required (VERSION 3.5)

project (HelloWorld)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_file "{source_dir}/*.cpp")

add_executable (firstproj ${source_files})
