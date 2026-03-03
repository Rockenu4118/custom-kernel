ARCH = i386
CC = gcc
AS = nasm
LD = ld

CFLAGS = -m32 -std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -m elf_i386 -T linker.ld -nostdlib

BUILD = build
KERNEL = $(BUILD)/kernel.elf
ISO = iso

SOURCES = kernel/boot.s kernel/kernel.c kernel/vga.c

all: $(KERNEL)

$(KERNEL): $(SOURCES)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c kernel/kernel.c -o $(BUILD)/kernel.o
	$(CC) $(CFLAGS) -c kernel/vga.c -o $(BUILD)/vga.o
	$(CC) $(CFLAGS) -c kernel/keyboard.c -o $(BUILD)/keyboard.o
	$(CC) $(CFLAGS) -c kernel/utils.c -o $(BUILD)/utils.o
	$(AS) -f elf32 kernel/boot.s -o $(BUILD)/boot.o
	$(LD) $(LDFLAGS) -o $(KERNEL) $(BUILD)/boot.o $(BUILD)/kernel.o $(BUILD)/vga.o $(BUILD)/keyboard.o $(BUILD)/utils.o

iso: all
	@mkdir -p $(ISO)/boot/grub
	cp $(KERNEL) $(ISO)/boot/kernel.elf
	cp grub/grub.cfg $(ISO)/boot/grub/
	grub-mkrescue -o myos.iso $(ISO)

run: iso
	qemu-system-i386 -cdrom myos.iso

clean:
	rm -rf $(BUILD) $(ISO) myos.iso

