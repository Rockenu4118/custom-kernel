//
// Created by aj on 7/18/25.
//

#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define VGA_ADDRESS 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_SIZE (VGA_WIDTH * VGA_HEIGHT)

extern uint16_t* vga_buffer;
extern uint8_t vga_row;
extern uint8_t vga_col;
extern uint8_t vga_color;

void vga_init();
void vga_put(char c);
void vga_write(const char* str);
void vga_clear();

#endif //VGA_H
