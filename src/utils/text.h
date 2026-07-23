#pragma once

#include <stdbool.h>
#include <stdint.h>

#define FONT8_BASE_TILE 1

/**
 * Get the sequential glyph index (0-based) of a character within the
 * font sheet.
 *
 * Returns 0xFF if the character has no glyph.
 */
uint8_t get_glyph_index(char character);

/**
 * Draw text with the 8x8 Yarara Font using hardware sprites.
 *
 * Returns the next free sprite index after drawing the text.
 *
 * @param text          The string of text to draw onto the sprite layer.
 * @param start_x       The x-position of the text, anchored on the left.
 * @param start_y       The y-position of the text, anchored at the top.
 * @param sprite_idx    The starting sprite index (0-39).
 * @param palette       The palette number to use for the text.
 */
uint8_t draw_sprite_text_8x8(const char *text, uint8_t start_x, uint8_t start_y,
                             uint8_t sprite_idx, uint8_t palette_number);
