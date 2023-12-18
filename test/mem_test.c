//
// Created by SHAVIN on 12/19/2023.
//

#include "stdio.h"
#include "inttypes.h"

#include "../mem_sys.h"



extern uint8_t mem[MEM_SIZE];

int main(int argc, char *argv[]) {
    fill_int32(0, 0xABCDEF11);

    printf("mem[0] = %X\nmem[1] = %X\nmem[2] = %X\nmem[3] = %X\n", mem[0], mem[1], mem[2], mem[3]);
    printf("reading integer: %X\n", read_int32(0));

    fill_int16(4, 0x9988);
    printf("\nmem[4] = %X\nmem[5] = %X", mem[4], mem[5]);
    printf("\nreading integer: %X\n", read_int16(4));

    fill_uint16(6, 0x9988);
    printf("\nmem[6] = %X\nmem[7] = %X", mem[6], mem[7]);
    printf("\nreading integer: %X\n", read_uint16(6));


}
