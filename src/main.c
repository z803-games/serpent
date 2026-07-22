#include "smile.h"

#include <gb/cgb.h>
#include <gb/gb.h>
#include <stdint.h>

void main(void) {
    SPRITES_8x16; // use 8x16 sprites instead of 8x8 sprites (this is a macro)

    set_sprite_data(0, 8, smile); // copy smile sprite into VRAM
    set_sprite_tile(0, 0); // assign sprite 0 to tile 0 from sprite memory (tile
                           // 0 comes with tiles 1 as well)
    move_sprite(0, 75, 75); // move to x = 75, y = 75

    set_sprite_tile(1, 2);      // sprite 1 = tiles 2 and 3
    move_sprite(1, 75 + 8, 75); // 75 + width of 8

    SHOW_SPRITES;

    while (1) {
        set_sprite_tile(1, 6);
        delay(500);
        set_sprite_tile(1, 2);
        delay(500);

        vsync();
    }
}
