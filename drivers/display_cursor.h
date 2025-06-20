/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

/* Includes */
#include <cpu/port.h>
#include <stddef.h>

/* Defines */
#define REG_DISPLAY_CTRL 0x3d4
#define REG_DISPLAY_DATA 0x3d5

/* Functions */
uint32_t get_cursor_position_x(void);
uint32_t get_cursor_position_y(void);
uint get_cursor_offset();
void set_cursor_offset(uint offset);