#pragma once

#include <stdint.h>

/** Load and draw the menu background map. */
void load_menu_background(void);

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
