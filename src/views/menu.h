#pragma once

#include <stdint.h>

/** Load and draw the menu background map. */
void load_menu_background(void);

/** Load the 8x8 Yarara Font tiles as sprites. */
void load_yarara_font_8x8(void);

/** Load the Orochi Japanese 16x16 logo sprites. */
void load_orochi_jp_16x16(void);

/** Draw the menu background. */
void draw_menu_background(void);

/**
 * Draw the Orochi logo onto the menu header.
 *
 * Returns the next free sprite index after drawing the logo.
 *
 * @param sprite_idx    The starting sprite index (0-39).
 */
uint8_t draw_menu_logo(uint8_t sprite_idx);

/** Load the menu and its resources. */
void load_menu(void);

/**
 * Run the menu loop.
 *
 * Returns the next free sprite index after finishing the loop.
 */
uint8_t run_menu_loop(uint8_t sprite_idx);
