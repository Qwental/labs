cmake_minimum_required(VERSION 3.29)
project(labs C)

set(CMAKE_C_STANDARD 11)

include_directories(lab1/task1)
include_directories(lab1/task10)

add_executable(labs
    lab1/task1/functions.h
    lab1/task1/main.c
    lab1/task1/tempCodeRunnerFile.c
    lab1/task1/test.c
    lab1/task10/functions.h
    lab1/task10/main.c
    lab1/task10/test.c
    lab1/task2/main.c)
