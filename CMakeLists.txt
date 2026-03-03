cmake_minimum_required(VERSION 3.31)
project(CustomKernel C)

set(CMAKE_C_STANDARD 23)

add_executable(CustomKernel
        kernel/kernel.c
        kernel/vga.c
        kernel/keyboard.c)
