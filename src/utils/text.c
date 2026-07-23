#include "text.h"
#include "fonts/yarara_font_8x8.h"

#include <gb/gb.h>
#include <gb/metasprites.h>
#include <stdint.h>

uint8_t get_glyph_index(char character) {
    if (character >= 'a' && character <= 'z')
        return character - 'a';
    if (character >= 'A' && character <= 'Z')
        return character - 'A';
    if (character >= '0' && character <= '9')
        return (character - '0') + 26;

    switch (character) {
    case '!':
        return 36;
    case ':':
        return 37;
    case '?':
        return 38;
    case '\\':
        return 39;
    case '=':
        return 40;
    case ',':
        return 41;
    case '.':
        return 42;
    case '<':
        return 43;
    case '>':
        return 44;
    }

    return 0xFF; // no glyph for this character
}

uint8_t draw_sprite_text_8x8(const char *text, uint8_t start_x, uint8_t start_y,
                             uint8_t sprite_idx, uint8_t palette_number) {
    uint8_t x = start_x;
    uint8_t current_sprite = sprite_idx;

    for (uint8_t i = 0; text[i] != '\0' && current_sprite < 40; ++i) {
        uint8_t glyph_index = get_glyph_index(text[i]);

        if (glyph_index == 0xFF)
            continue;

        current_sprite += move_metasprite_ex(
            yarara_font_8x8_metasprites[FONT8_BASE_TILE + glyph_index],
            FONT8_BASE_TILE, palette_number, current_sprite, x + 8,
            start_y + 24);

        x += 8;
    }

    return current_sprite; // next free sprite index
}
