cmake_minimum_required(VERSION 3.24)
project(C_project C)

set(CMAKE_C_STANDARD 11)

add_executable(C_project
        src/main.c includes/shell.h src/builtin/console.c src/builtin/strings.c src/builtin/env.c)
