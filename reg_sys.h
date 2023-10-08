#include "inttypes.h"

//
// Created by SHAVIN on 10/8/2023.
//

#ifndef RISC_SIMULATOR_REG_SYS_H
#define RISC_SIMULATOR_REG_SYS_H

#define BASE_REGISTER_COUNT 32

// define the base register conventional name according RISC-V manual
#define ZERO_REG 0
#define RA 1
#define SP 2
#define GP 3
#define TP 4

#define T0 5
#define T1 6
#define T2 7
#define T3 28
#define T4 29
#define T5 30
#define T6 31

#define FP 8

#define S0 8
#define S1 9
#define S2 18
#define S3 19
#define S4 20
#define S5 21
#define S6 22
#define S7 23
#define S8 24
#define S9 25
#define S10 26
#define S11 27

#define A0 10
#define A1 11
#define A2 12
#define A3 13
#define A4 14
#define A5 15
#define A6 16
#define A7 17

// define a macro for extract the register values
#define REG(X) base_regs[X]
#define JUMP(X) (PC = X)

// create a general purpose 32-bit 32 integer register set as integer array
int32_t base_regs[BASE_REGISTER_COUNT] = {0};

// special register to represent the program counter
int32_t PC = 0;

void fill_reg(uint8_t reg, int32_t val);
void reg_dump();
void jump(int32_t address); // safe version of the JUMP(X) macro with circular traversing
int32_t get_reg(uint8_t reg); // safe version of the REG(X) macro with bound checking

#endif //RISC_SIMULATOR_REG_SYS_H
