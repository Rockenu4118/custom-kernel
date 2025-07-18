; kernel/boot.s
section .multiboot
    align 4
    dd 0x1BADB002        ; magic number (GRUB requirement)
    dd 0x00              ; flags
    dd - (0x1BADB002 + 0x00) ; checksum

section .text
    align 4
    global _start
    extern kernel_main

_start:
    mov esp, stack_top     ; Set up stack
    call kernel_main       ; Call the C kernel
.hang:
    cli
    hlt
    jmp .hang

section .bss
    align 16
stack_bottom:
    resb 16384             ; 16 KB stack
stack_top: