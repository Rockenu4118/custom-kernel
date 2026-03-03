#include "keyboard.h"

static uint8_t buf_pos = 0;

static char get_key() 
{
    while (1) {
        while ((inb(KBD_STATUS_PORT) & 0x01) == 0) {
            asm volatile("nop");
        }

        uint8_t scancode = inb(KBD_DATA_PORT);

        if (scancode & 0x80) continue;

        char c = keymap[scancode];
        if (c != 0) return c;
    }
}

void keyboard_getline(char* buf, uint32_t max_len)
{
    buf_pos = 0;
    buf[0] = '\0';

    while (1) {
        char c = get_key();

        if (c == '\n') {
            buf[buf_pos] = '\0';
            vga_put('\n');
            return;
        } 
        else if (c == '\b') {
            if (buf_pos > 0) {
                buf_pos--;
                vga_col--;
                vga_put(' ');
                vga_col--;
            }
        }
        else if (buf_pos < max_len - 1) {
            buf[buf_pos++] = c;
            vga_put(c);
        }
    }
}

