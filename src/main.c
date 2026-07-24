#include "backgrounds/menu_background.h"
#include "fonts/orochi_jp_16x16.h"
#include "fonts/yarara_font_8x8.h"
#include "utils/text.h"

#include <gb/cgb.h>
#include <gb/gb.h>
#include <gb/hardware.h>
#include <stdint.h>

/** Load and draw the menu background map. */
void load_menu_background(void) {
    set_bkg_data(0, menu_background_TILE_COUNT,
                 menu_background_tiles); // load tiles into VRAM
    set_bkg_palette(0, menu_background_PALETTE_COUNT,
                    menu_background_palettes);        // palette 0
    set_bkg_tiles(0, 0, 20, 18, menu_background_map); // load map into bkg
}

/** Load the 8x8 Yarara Font tiles as sprites. */
void load_yarara_font_8x8(void) {
    set_sprite_data(FONT_1_BASE_TILE, yarara_font_8x8_TILE_COUNT,
                    yarara_font_8x8_tiles);
    set_sprite_palette(1, 1, yarara_font_8x8_palettes);
}

/** Load the Orochi Japanese 16x16 logo sprites. */
void load_orochi_jp_16x16(void) {
    set_sprite_data(FONT_2_BASE_TILE, orochi_jp_16x16_TILE_COUNT,
                    orochi_jp_16x16_tiles);
    set_sprite_palette(1, 1, orochi_jp_16x16_palettes);
}

/**
 * Draw the Orochi logo onto the menu header.
 *
 * @param sprite_idx    The starting sprite index (0-39).
 */
uint8_t draw_menu_logo(uint8_t sprite_idx) {
    uint8_t current_sprite = sprite_idx;

    current_sprite +=
        move_metasprite_ex(orochi_jp_16x16_metasprites[0], FONT_2_BASE_TILE, 1,
                           current_sprite, 52, 40);
    current_sprite +=
        move_metasprite_ex(orochi_jp_16x16_metasprites[1], FONT_2_BASE_TILE, 1,
                           current_sprite, 68, 40);
    current_sprite = draw_sprite_text_8x8("OROCHI", 80, 20, current_sprite, 1);

    return current_sprite;
}

void main(void) {
    DISPLAY_OFF;
    HIDE_BKG;

    SPRITES_8x16;

    hide_sprites_range(0, MAX_HARDWARE_SPRITES);

    load_menu_background();

    load_yarara_font_8x8();
    load_orochi_jp_16x16();

    uint8_t current_sprite = draw_menu_logo(0);

    DISPLAY_ON;
    SHOW_BKG;
    SHOW_SPRITES;

    static uint8_t first_sprite = 0;

    while (1) {
        vsync();
    }
}
