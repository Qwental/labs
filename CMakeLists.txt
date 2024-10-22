cmake_minimum_required(VERSION 3.5.0)
project(fund_labs VERSION 0.1.0 LANGUAGES C)

list(APPEND CMAKE_C_FLAGS "-lm -Wall -Werror -Wextra -std=c99 -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment")

set(CMAKE_C_FLAGS_LABS "-lm  -Wall -Werror -Wextra -std=c99 -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment"
    CACHE STRING "Compiler flags in labs build"
    FORCE)

message("General compiler flags: " ${CMAKE_C_FLAGS})
message("Debug build compiler flags: " ${CMAKE_C_FLAGS})
message("Labs build compiler flags: " ${CMAKE_C_FLAGS})

# EXECUTABLES:
# LAB1
#add_executable(task9.out lab1/task9/task9_main.c lab1/task9/task9_functions.c)

add_executable(task1_9.out
    lab1/task9/task9_main.c
    include/DEFAULT_LIBS_FUNC_CODES.h
    include/DEFAULT_FUNCTIONS.h
    src/DEFAULT_FUNCTIONS.c
    lab1/task9/include/task9_functions.h
    lab1/task9/src/task9_functions.c
)


add_executable(task1_2.out
    lab1/task2/task2_main.c
    include/DEFAULT_LIBS_FUNC_CODES.h
    include/DEFAULT_FUNCTIONS.h
    src/DEFAULT_FUNCTIONS.c
    lab1/task2/include/task2_functions.h 
    lab1/task2/src/task2_functions.c
)

add_executable(task1_6.out 
    lab1/task6/task6_main.c
    include/DEFAULT_LIBS_FUNC_CODES.h
    include/DEFAULT_FUNCTIONS.h
    src/DEFAULT_FUNCTIONS.c
    lab1/task6/include/task6_functions.h 
    lab1/task6/src/task6_functions.c
)

add_executable(task1_7.out 
    lab1/task7/task7_main.c
    include/DEFAULT_LIBS_FUNC_CODES.h
    include/DEFAULT_FUNCTIONS.h
    src/DEFAULT_FUNCTIONS.c
    lab1/task7/include/task7_functions.h
    lab1/task7/src/task7_functions.c
)

add_executable(task2_1.out 
    include/DEFAULT_LIBS_FUNC_CODES.h
    include/DEFAULT_FUNCTIONS.h
    src/DEFAULT_FUNCTIONS.c

    lab2/task1/task2_1_main.c
    lab2/task1/include/task2_1_functions.h
    lab2/task1/src/task2_1_functions.c
)

add_executable(task2_2.out 
    include/DEFAULT_LIBS_FUNC_CODES.h
    include/DEFAULT_FUNCTIONS.h
    src/DEFAULT_FUNCTIONS.c

    lab2/task2/task2_2_main.c
    lab2/task2/include/task2_2_functions.h
    lab2/task2/src/task2_2_functions.c
)


add_executable(task2_7.out 
    include/DEFAULT_LIBS_FUNC_CODES.h
    include/DEFAULT_FUNCTIONS.h
    src/DEFAULT_FUNCTIONS.c

    lab2/task7/task2_7_main.c
    lab2/task7/include/task2_7_functions.h
    lab2/task7/src/task2_7_functions.c
)

add_executable(task2_4.out 
    include/DEFAULT_LIBS_FUNC_CODES.h
    include/DEFAULT_FUNCTIONS.h
    src/DEFAULT_FUNCTIONS.c

    lab2/task4/task2_4_main.c
    lab2/task4/include/task2_4_functions.h
    lab2/task4/src/task2_4_functions.c
)

