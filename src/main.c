#include "backgrounds/menu_background.h"
#include "fonts/yarara_font_8x8.h"
#include "utils/text.h"

#include <gb/cgb.h>
#include <gb/gb.h>
#include <gb/hardware.h>
#include <stdbool.h>

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
    set_sprite_data(FONT8_BASE_TILE, yarara_font_8x8_TILE_COUNT,
                    yarara_font_8x8_tiles);
    set_sprite_palette(1, 1, yarara_font_8x8_palettes);
}

void main(void) {
    DISPLAY_OFF;
    HIDE_BKG;

    hide_sprites_range(0, MAX_HARDWARE_SPRITES);

    load_menu_background();
    load_yarara_font_8x8();

    draw_sprite_text_8x8("Orochi", 56, 8, 0, 1);

    DISPLAY_ON;
    SHOW_BKG;
    SHOW_SPRITES;

    static uint8_t first_sprite = 0;

    while (1) {
        vsync();
    }
}
