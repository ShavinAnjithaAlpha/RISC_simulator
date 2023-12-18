//
// Created by SHAVIN on 10/8/2023.
//

#include "mem_sys.h"


// create a memory arena for emulating the memory with size 0xffffff bytes
uint8_t mem[MEM_SIZE];

void fill_mem(uint32_t address, uint8_t value) {
    mem[address] = value;
}

void fill_int32(uint32_t address, int32_t value) {
    // fill the 32-bit integer in little endian order in memory
    // extract the LSB from the value and store it in lower address
    mem[address] = (uint8_t) (value & 0xFF);

    // extract the next 8 bit parts and store it in next addresses
    mem[address + 1] = (uint8_t) ((value >> 8) & 0xFF);
    mem[address + 2] = (uint8_t) ((value >> 16) & 0xFF);
    mem[address + 3] = (uint8_t) ((value >> 24) & 0xFF);
}

void fill_uint32(uint32_t address, uint32_t value) {
    // fill the 32-bit integer in little endian order in memory
    // extract the LSB from the value and store it in lower address
    mem[address] = (uint8_t) (value & 0xFF);

    // extract the next 8 bit parts and store it in next addresses
    mem[address + 1] = (uint8_t) ((value >> 8) & 0xFF);
    mem[address + 2] = (uint8_t) ((value >> 16) & 0xFF);
    mem[address + 3] = (uint8_t) ((value >> 24) & 0xFF);
}

void fill_int16(uint32_t address, int16_t value) {
    // fill the 16-bit integer in the little endian order in memory

    mem[address] = (uint8_t) (value & 0xFF);
    mem[address + 1] = (uint8_t) ((value >> 8) & 0xFF);
}

void fill_uint16(uint32_t address, uint16_t value) {
    // fill the 16-bit integer in the little endian order in memory

    mem[address] = (uint8_t) (value & 0xFF);
    mem[address + 1] = (uint8_t) ((value >> 8) & 0xFF);
}


// implementations of memory read functions
uint8_t read_mem(uint32_t address) {
    return mem[address];
}

int32_t read_int32(uint32_t address) {
    // read the first segment, second and forward...
    int32_t first = (int32_t) mem[address];
    int32_t second = (int32_t) (mem[address + 1] << 8);
    int32_t third = (int32_t) (mem[address + 2] << 16);
    int32_t fourth = (int32_t) (mem[address + 3] << 24);

    return (int32_t) (first | second | third | fourth);
}

uint32_t read_uint32(uint32_t address) {

    // read the first segment, second and forward...
    uint32_t first = (uint32_t) mem[address];
    uint32_t second = (uint32_t) (mem[address + 1] << 8);
    uint32_t third = (uint32_t) (mem[address + 2] << 16);
    uint32_t fourth = (uint32_t) (mem[address + 3] << 24);

    return (uint32_t) (first | second | third | fourth);
}

int16_t read_int16(uint32_t address) {

    // read the first and second segment separately
    int16_t first = (int16_t) mem[address];
    int16_t second = (int16_t) (mem[address + 1] << 8);

    return (int16_t) (first | second);
}

uint16_t read_uint16(uint32_t address) {

    // read the first and second segment separately
    uint16_t first = (uint16_t) mem[address];
    uint16_t second = (uint16_t) (mem[address + 1] << 8);

    return (uint16_t) (first | second);
}

