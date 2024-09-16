#ifndef __VOS_VGA_H__
#define __VOS_VGA_H__

#include <stdint.h>
#include <stdbool.h>

#include "vos.h"

#define SCREEN_X 960
#define SCREEN_Y 720
#define SCREEN_UPSCALE 2
#define VGA_BUFFER_GLYPH_WIDTH (SCREEN_X / (8 * SCREEN_UPSCALE))
#define VGA_BUFFER_GLYPH_HEIGHT (SCREEN_Y / (16 * SCREEN_UPSCALE))
#define VGA_BUFFER_SIZE VGA_BUFFER_GLYPH_WIDTH * VGA_BUFFER_GLYPH_HEIGHT

bool init_vga(void);
void finalize_vga(void);
bool work_vga(void);
void put_vga_glyph(vos_t* vos, uint32_t x, uint32_t y, char glyph, uint8_t foreground, uint8_t background);

#endif