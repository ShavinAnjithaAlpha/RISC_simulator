//
// Created by SHAVIN on 10/8/2023.
//

#ifndef RISC_SIMULATOR_MEM_SYS_H
#define RISC_SIMULATOR_MEM_SYS_H

#include "inttypes.h"

#define MEM_SIZE 0xffffff
#define MEM_MIN 0x0
#define MEM_MAX (MEM_SIZE - 1)

void fill_mem(uint32_t address, uint8_t val);
void fill_int32(uint32_t address, int32_t val);
void fill_uint32(uint32_t address, uint32_t val);
void fill_int16(uint32_t address, int16_t val);
void fill_uint16(uint32_t address, uint16_t val);

// functions for read the memory
uint8_t read_mem(uint32_t address);
int32_t read_int32(uint32_t address);
uint32_t read_uint32(uint32_t address);
int16_t read_int16(uint32_t address);
uint16_t read_uint16(uint32_t address);

#endif //RISC_SIMULATOR_MEM_SYS_H
