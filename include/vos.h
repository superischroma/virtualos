#ifndef __VOS_H__
#define __VOS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MEMORY_SIZE 65536

extern char* PROGRAM_NAME;

typedef struct {
    uint8_t* mem;
    uint16_t* vga;
    uint64_t pc;
} vos_t;

#endif