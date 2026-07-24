#pragma once

#include "fonts/yarara_font_8x8.h"

#include <stdbool.h>
#include <stdint.h>

#define FONT_1_BASE_TILE 1
#define FONT_2_BASE_TILE (FONT_1_BASE_TILE + yarara_font_8x8_TILE_COUNT + 1)

/** A blank metasprite. */
static const metasprite_t blank_metasprite[] = {
    METASPR_ITEM(-4, -4, 0, S_PAL(0)), METASPR_TERM};

/** Load the 8x8 Yarara Font tiles as sprites. */
void load_yarara_font_8x8(void);

/** Load the Orochi Japanese 16x16 logo sprites. */
void load_orochi_jp_16x16(void);

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
