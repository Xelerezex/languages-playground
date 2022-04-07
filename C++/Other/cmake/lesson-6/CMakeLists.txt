cmake_minimum_required(VERSION 3.16)
project(out VERSION 1.1.2)

set(my_list 1 2 3 4 5 6)
set_property(
    GLOBAL
    PROPERTY FOO
    "${my_list}"
)

get_cmake_property(foo_value FOO)
message(STATUS "VALUE IS: ${foo_value}")
