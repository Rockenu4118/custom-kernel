//
// Created by aj on 7/18/25.
//

#include "vga.h"

void kernel_main(void)
{
    vga_init();
    vga_write("Hello from my new sexy kernel!\n");
}
