cmake_minimum_required(VERSION 3.5.0)
project(fund_labs VERSION 0.1.0 LANGUAGES C)

list(APPEND CMAKE_CXX_FLAGS "-Wall -Werror  -Wsign-compare")

set(CMAKE_CXX_FLAGS_LABS "-g -Wall -Wextra -Werror -lm -std=c99,undefined -fno-sanitize-recover=all -O2"
    CACHE STRING "Compiler flags in labs build"
    FORCE)

message("General compiler flags: " ${CMAKE_CXX_FLAGS})
message("Debug build compiler flags: " ${CMAKE_CXX_FLAGS_DEBUG})
message("Labs build compiler flags: " ${CMAKE_CXX_FLAGS_LABS})


# EXECUTABLES:
add_executable(task10 lab1/task10/task10_main.c lab1/task10/task10_functions.c)
add_executable(task4 lab1/task4/task4_main.c lab1/task4/task4_functions.c)
add_executable(task9 lab1/task9/task9_main.c lab1/task9/task9_functions.c)



