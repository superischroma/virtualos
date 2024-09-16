#include "../include/util.h"

void dump_memory(FILE* stream, uint8_t* mem, uint64_t start, uint64_t end)
{
    for (uint64_t i = start & ~0x0F; i < ((end - 1) & ~0x0F) + 0x10; ++i)
    {
        if (i % 0x10 == 0)
            printf("%08lX | ", i);
        if (i < end)
            printf("%02X ", mem[i]);
        else
            printf("   ");
        if ((i & 0x0F) == 0x0F)
            printf("\n");
    }
}