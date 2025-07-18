//
// Created by aj on 7/18/25.
//

#include <stdint.h>
#include "vga.h"


#define VGA_ADDRESS 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

uint16_t* vga_buffer = (uint16_t*)VGA_ADDRESS;
uint8_t vga_row = 0;
uint8_t vga_col = 0;
uint8_t vga_color = 0x0F;

void vga_init()
{
    for (uint32_t i = 0 ; i < VGA_HEIGHT * VGA_WIDTH ; i++)
    {
        vga_buffer[i] = (uint16_t)' ' | (vga_color << 8);
    }
}

void vga_put(char c)
{
    if (c == '\n')
    {
        vga_row++;
        vga_col = 0;
    }
    else
    {
        vga_buffer[vga_row * VGA_WIDTH + vga_col] = (uint16_t)c | (vga_color << 8);
        vga_col++;
        if (vga_col >= VGA_WIDTH)
        {
            vga_col = 0;
            vga_row++;
        }
    }
}

void vga_write(const char* str)
{
    while (*str)
    {
        vga_put(*str++);
    }
}
