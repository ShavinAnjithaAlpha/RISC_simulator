cmake_minimum_required(VERSION 3.26)
project(RISC_simulator C)

set(CMAKE_C_STANDARD 11)

add_executable(RISC_simulator
        main.c
        reg_sys.h
        reg_sys.c
        mem_sys.c
        mem_sys.h
        test/mem_test.c)

add_executable(mem_test test/mem_test.c mem_sys.h mem_sys.c)
