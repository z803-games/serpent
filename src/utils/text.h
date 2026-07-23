#pragma once

#include <stdint.h>

uint8_t get_character_vram_tile(char character);
uint8_t *draw_text(char *text, uint8_t start_tile_x, uint8_t start_tile_y);
