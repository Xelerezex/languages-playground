project(main VERSION 1.0.0)

add_executable(main main.cpp)

print_variables()

target_link_libraries(main PRIVATE some-output)
