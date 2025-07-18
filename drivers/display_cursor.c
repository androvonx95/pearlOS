/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#include <drivers/display_cursor.h>
#include <drivers/display.h>

uint32_t get_cursor_position_x() {
  uint32_t pos = 0;
  port_byte_out(0x3D4, 0x0F);
  pos |= port_byte_in(0x3D5);
  port_byte_out(0x3D4, 0x0E);
  pos |= ((uint32_t)port_byte_in(0x3D5)) << 8;
  return pos % DISPLAY_WIDTH;
}

uint32_t get_cursor_position_y() {
  uint32_t pos = 0;
  port_byte_out(0x3D4, 0x0F);
  pos |= port_byte_in(0x3D5);
  port_byte_out(0x3D4, 0x0E);
  pos |= ((uint32_t)port_byte_in(0x3D5)) << 8;
  return pos / DISPLAY_WIDTH;
}

uint get_cursor_offset() {
    port_byte_out(REG_DISPLAY_CTRL, 14);
    uint offset = port_byte_in(REG_DISPLAY_DATA) << 8;
    port_byte_out(REG_DISPLAY_CTRL, 15);
    offset += port_byte_in(REG_DISPLAY_DATA);
    return offset * 2;
}

void set_cursor_offset(uint offset) {
    offset /= 2;
    port_byte_out(REG_DISPLAY_CTRL, 14);
    port_byte_out(REG_DISPLAY_DATA, (byte) (offset >> 8));
    port_byte_out(REG_DISPLAY_CTRL, 15);
    port_byte_out(REG_DISPLAY_DATA, (byte) (offset & 0xff));
}