#include "../include/terminal.h"
#include "../include/vga.h"

void terminal_putchar(vos_t* vos, char c)
{
    if (c == '\n')
    {
        vos->terminal.cursor_x = 0;
        ++(vos->terminal.cursor_y);
        return;
    }
    put_vga_glyph(vos, vos->terminal.cursor_x++, vos->terminal.cursor_y, c, vos->terminal.foreground_color, vos->terminal.background_color);
    if (vos->terminal.cursor_x >= VGA_BUFFER_GLYPH_WIDTH)
    {
        vos->terminal.cursor_x = 0;
        ++(vos->terminal.cursor_y);
    }
}

void terminal_puts(vos_t* vos, char* s)
{
    while (*s)
        terminal_putchar(vos, *s++);
}