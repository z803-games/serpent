#include <gb/gb.h>
#include <stdint.h>

uint8_t get_character_vram_tile(char character) {
    uint8_t vram_tile = 0;

    if (character >= 'a' && character <= 'z')
        vram_tile = (character - 'a') + 1;
    else if (character >= 'A' && character <= 'Z')
        vram_tile = (character - 'A') + 1;
    else if (character >= '0' && character <= '9')
        vram_tile = (character - '0') + 27;
    else {
        switch (character) {
        case '!':
            vram_tile = 37;
            break;
        case ':':
            vram_tile = 38;
            break;
        case '?':
            vram_tile = 39;
            break;
        case '\\':
            vram_tile = 40;
            break;
        case '=':
            vram_tile = 41;
            break;
        case ',':
            vram_tile = 42;
            break;
        case '.':
            vram_tile = 43;
            break;
        case '<':
            vram_tile = 44;
            break;
        case '>':
            vram_tile = 45;
            break;
        }
    }

    return vram_tile;
}

uint8_t draw_text(char *text, uint8_t start_tile_x, uint8_t start_tile_y) {
    uint8_t *vram_address = get_bkg_xy_addr(start_tile_x, start_tile_y);

    for (uint8_t i = 0; text[i] != '\0'; ++i) {
        uint8_t vram_tile = get_character_vram_tile(text[i]);
        set_vram_byte(vram_address++, vram_tile);
    }

    return vram_address; // return end VRAM address
}
