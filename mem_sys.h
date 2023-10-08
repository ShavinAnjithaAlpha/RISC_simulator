//
// Created by SHAVIN on 10/8/2023.
//

#ifndef RISC_SIMULATOR_MEM_SYS_H
#define RISC_SIMULATOR_MEM_SYS_H

#include "inttypes.h"

#define MEM_SIZE 0xffffff
#define MEM_MIN 0x0
#define MEM_MAX (MEM_SIZE - 1)

// create a memory arena for emulating the memory with size 0xffffff bytes
int8_t mem[MEM_SIZE];

void fill_mem(uint32_t address, int8_t val);
void fill_int32(uint32_t address, int32_t val);
void fill_uint32(uint32_t address, uint32_t val);
void fill_int16(uint32_t address, int16_t val);
void fill_uint16(uint32_t address, uint16_t val);

#endif //RISC_SIMULATOR_MEM_SYS_H
