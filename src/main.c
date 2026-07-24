#include "views/menu.h"

#include <gb/cgb.h>
#include <gb/gb.h>
#include <stdint.h>

void main(void) {
    uint8_t current_sprite = 0;

    DISPLAY_OFF;

    load_menu();

    DISPLAY_ON;

    SHOW_SPRITES;

    current_sprite = run_menu_loop(current_sprite);
}
