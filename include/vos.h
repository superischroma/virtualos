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

    uint64_t pc;

    uint64_t vga_addr;


    struct {
        uint32_t cursor_x;
        uint32_t cursor_y;
        uint8_t foreground_color;
        uint8_t background_color;
    } terminal;
} vos_t;

#endif