cmake_minimum_required(VERSION 3.29)
project(Praktikum1 C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pedantic -Wextra -pedantic-errors")

add_executable(Praktikum1 main.c)
target_link_libraries(Praktikum1 m)