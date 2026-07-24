#include "text.h"
#include "fonts/yarara_font_8x8.h"

#include <gb/gb.h>
#include <gb/metasprites.h>
#include <stdint.h>

uint8_t get_glyph_index(char character) {
    uint8_t index;

    if (character >= 'a' && character <= 'z')
        index = character - 'a';
    else if (character >= 'A' && character <= 'Z')
        index = character - 'A';
    else if (character >= '0' && character <= '9')
        index = (character - '0') + 26;
    else {
        switch (character) {
        case '!':
            index = 36;
            break;
        case ':':
            index = 37;
            break;
        case '?':
            index = 38;
            break;
        case '\\':
            index = 39;
            break;
        case '=':
            index = 40;
            break;
        case ',':
            index = 41;
            break;
        case '.':
            index = 42;
            break;
        case '<':
            index = 43;
            break;
        case '>':
            index = 44;
            break;
        case '大':
            index = 45;
            break;
        case '蛇':
            index = 46;
            break;
        default:
            return 0xFF;
        }
    }

    return index;
}

uint8_t draw_sprite_text_8x8(const char *text, uint8_t start_x, uint8_t start_y,
                             uint8_t sprite_idx, uint8_t palette_number) {
    uint8_t x = start_x;
    uint8_t current_sprite = sprite_idx;

    for (uint8_t i = 0; text[i] != '\0' && current_sprite < 40; ++i) {
        uint8_t glyph_index = get_glyph_index(text[i]);

        if (glyph_index == 0xFF)
            continue;

        glyph_index += glyph_index + 1;

        current_sprite += move_metasprite_ex(
            yarara_font_8x8_metasprites[glyph_index], FONT_1_BASE_TILE,
            palette_number, current_sprite, x + 8, start_y + 24);

        x += 8;
    }

    return current_sprite; // next free sprite index
}
