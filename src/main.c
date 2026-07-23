#include "fonts/yarara_font.h"
#include "utils/text.h"

#include <gb/gb.h>
#include <gb/hardware.h>

void main(void) {
    SPRITES_8x8;

    set_bkg_palette(0, 1, yarara_font_palettes);
    set_bkg_data(1, 44, yarara_font_tiles);

    fill_bkg_rect(0, 0, DEVICE_SCREEN_WIDTH, DEVICE_SCREEN_HEIGHT, 0);

    draw_text("Hello, World!", 1, 1);

    SHOW_BKG;

    while (1) {
        vsync();
    }
}
