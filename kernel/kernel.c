//
// Created by aj on 7/18/25.
//

#include "vga.h"
#include "keyboard.h"
#include "utils.h"

void kernel_main(void)
{
    vga_init();
    vga_clear();
    vga_write("Welcome!\n");
    vga_write("Type commands and press Enter\n\n");

    char command[128];

    while (1) 
    {
        vga_write("> ");
        keyboard_getline(command, 128);

        if (strcmp(command, "clear") == 0) {
            vga_clear();
        }
        else if (strcmp(command, "help") == 0) {
            vga_write("Commands:\n");
            vga_write("  -clear\n");
            vga_write("  -help\n");
            vga_write("  -echo\n");
            vga_write("  -halt\n");
        }
        else if (strncmp(command, "echo ", 5) == 0) {
            vga_write(command + 5);
            vga_put('\n');
        }
        else if (strcmp(command, "halt") == 0) {
            vga_write("Halting...\n");
            while (1) asm volatile("hlt");
        }
        else if (command[0] != '\0') {
            vga_write("Unknown command: ");
            vga_write(command);
            vga_put('\n');
        }
    }
}