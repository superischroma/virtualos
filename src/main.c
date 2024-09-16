#include "../include/vos.h"
#include "../include/log.h"
#include "../include/vga.h"
#include "../include/util.h"
#include "../include/terminal.h"

char* PROGRAM_NAME;

int main(int argc, char** argv)
{
    PROGRAM_NAME = argv[0];

    if (!init_vga())
    {
        finalize_vga();
        return EXIT_FAILURE;
    }

    vos_t vos;
    vos.mem = calloc(MEMORY_SIZE, sizeof(uint8_t));
    vos.vga_addr = 0x0000;

    vos.terminal.cursor_x = vos.terminal.cursor_y = 0;
    vos.terminal.foreground_color = 0x07;
    vos.terminal.background_color = 0x00;

    for (;;)
    {
        if (!work_vga())
            break;
    }

    free(vos.mem);
    finalize_vga();
    return EXIT_SUCCESS;
}