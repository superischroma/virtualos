#include "../include/log.h"
#include "../include/vos.h"

int errorf(char* fmt, ...)
{
    va_list v;
    va_start(v, fmt);
    int i = fprintf(stderr, "%s: error: ", PROGRAM_NAME) + vfprintf(stderr, fmt, v);
    va_end(v);
    return i;
}