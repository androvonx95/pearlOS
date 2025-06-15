/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

/* Includes */
#include <stddef.h>
#include <cpu/port.h>
#include <kernel/config.h>

#define VIDEO_MEMORY_OFFSET (uint*) 0xb8000

/* Config */
#define DISPLAY_WIDTH  80
#define DISPLAY_HEIGHT 25

/* Don't touch these */
#define DISPLAY_SCROLL_DEBUG           80
#define DISPLAY_SCROLL_DETECTION_DEBUG -2

/* Colour */
#define TRANSPARENT 0x00
#include <drivers/display_color.h>

/* Code */
#define INIT_VIDEO char* video_memory = (char*) VIDEO_MEMORY_OFFSET

/* Kernel API */
void printc(char character);
void cprintc(char character, char color);
void print(char* text, uint32_t depth);
void cprint(char* text, uint32_t depth, byte color);
void printnl();
void display_clear();
void display_scroll();
void display_theme(char color);
void display_deletec();
void display_init();
void rowcpy(uint dest, uint src);
void set_cursor_position(uint column, uint row);