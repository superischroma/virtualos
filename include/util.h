#ifndef __VOS_UTIL_H__
#define __VOS_UTIL_H__

#include <stdio.h>
#include <stdint.h>

void dump_memory(FILE* stream, uint8_t* mem, uint64_t start, uint64_t end);

#endif