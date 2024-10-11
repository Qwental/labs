cmake_minimum_required(VERSION 3.5.0)
project(fund_labs VERSION 0.1.0 LANGUAGES C)

list(APPEND CMAKE_C_FLAGS "-lm -Wall -Werror -Wextra -std=c99 -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment")

set(CMAKE_C_FLAGS_LABS "-lm -Wall -Werror -Wextra -std=c99 -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment"
    CACHE STRING "Compiler flags in labs build"
    FORCE)

message("General compiler flags: " ${CMAKE_C_FLAGS})
message("Debug build compiler flags: " ${CMAKE_C_FLAGS})
message("Labs build compiler flags: " ${CMAKE_C_FLAGS})

# EXECUTABLES:
# LAB1
add_executable(task10.out lab1/task10/task10_main.c lab1/task10/task10_functions.c)
add_executable(task4.out lab1/task4/task4_main.c lab1/task4/task4_functions.c)
add_executable(task9.out lab1/task9/task9_main.c lab1/task9/task9_functions.c)
add_executable(task2.out lab1/task2/task2_main.c lab1/task2/task2_functions.c)
add_executable(task6.out lab1/task6/task6_main.c lab1/task6/task6_functions.c)
add_executable(task7.out lab1/task7/task7_main.c lab1/task7/task7_functions.c)
