//
// Created by SHAVIN on 10/8/2023.
//

#include<stdio.h>
#include "mem_sys.h"
#include "reg_sys.h"

extern uint8_t mem[MEM_SIZE];

void fill_reg(uint8_t reg, int32_t val) {
    if (reg < 0 || reg >= BASE_REGISTER_COUNT) return;
    base_regs[reg] = val;
}

// dump the register system to a file or standard output stream
void reg_dump() {
    for (int i = 0; i < BASE_REGISTER_COUNT; i++) {
        printf("X%d : %d\n", i, base_regs[i]);
    }

    printf("PC : %d", PC);
}

void jump(int32_t address) {
    PC = address % MEM_SIZE;
}

int32_t get_reg(uint8_t reg) {
    if (reg < 0 || reg >= BASE_REGISTER_COUNT) return 0;
    return base_regs[reg];
}
