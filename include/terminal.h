#ifndef __VOS_TERMINAL_H__
#define __VOS_TERMINAL_H__

#include "vos.h"

void terminal_putchar(vos_t* vos, char c);
void terminal_puts(vos_t* vos, char* s);

#endif