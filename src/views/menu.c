#include "backgrounds/menu_background.h"
#include "fonts/orochi_jp_16x16.h"
#include "fonts/yarara_font_8x8.h"
#include "utils/text.h"

#include <gb/gb.h>
#include <gb/hardware.h>
#include <gb/metasprites.h>
#include <stdint.h>

void load_menu_background(void) {
    set_bkg_data(0, menu_background_TILE_COUNT,
                 menu_background_tiles); // load menu bkg tiles into VRAM
    set_bkg_palette(
        0, menu_background_PALETTE_COUNT,
        menu_background_palettes); // set palette 0 to the menu bkg palette
}

void load_yarara_font_8x8(void) {
    set_sprite_data(FONT_1_BASE_TILE, yarara_font_8x8_TILE_COUNT,
                    yarara_font_8x8_tiles);
    set_sprite_palette(1, 1, yarara_font_8x8_palettes);
}

void load_orochi_jp_16x16(void) {
    set_sprite_data(FONT_2_BASE_TILE, orochi_jp_16x16_TILE_COUNT,
                    orochi_jp_16x16_tiles);
    set_sprite_palette(1, 1, orochi_jp_16x16_palettes);
}

void draw_menu_background(void) {
    set_bkg_tiles(0, 0, 20, 18, menu_background_map);
}

uint8_t draw_menu_logo(uint8_t sprite_idx) {
    uint8_t current_sprite = sprite_idx;

    current_sprite +=
        move_metasprite_ex(orochi_jp_16x16_metasprites[0], FONT_2_BASE_TILE, 1,
                           current_sprite, 52, 40); // 大
    current_sprite +=
        move_metasprite_ex(orochi_jp_16x16_metasprites[1], FONT_2_BASE_TILE, 1,
                           current_sprite, 68, 40); // 蛇
    current_sprite = draw_sprite_text_8x8("OROCHI", 80, 20, current_sprite, 1);

    return current_sprite;
}

void load_menu(void) {
    HIDE_BKG;
    SPRITES_8x16;

    hide_sprites_range(0, MAX_HARDWARE_SPRITES);

    load_menu_background();
    load_yarara_font_8x8();
    load_orochi_jp_16x16();

    SHOW_BKG;
    SHOW_SPRITES;
}

uint8_t run_menu_loop(uint8_t sprite_idx) {
    draw_menu_background();
    uint8_t current_sprite = draw_menu_logo(sprite_idx);

    /* This loop should eventually break on certain conditions.
     * (For example, when the user enters a level.)
     *
     * Omitted for now because there is nothing to loop at the moment. And, of
     * course, we do want the function to return.
     */
    // while (1) {
    //     vsync();
    // }

    return current_sprite;
}
