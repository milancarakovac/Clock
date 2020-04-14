#!/bin/bash
export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"
nasm -felf32 boot.asm -o boot.o
i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c terminal.c -o terminal.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c utils.c -o utils.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c gdt.c -o gdt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c idt.c -o idt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c isrs.c -o isrs.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra  -Wattributes
i686-elf-gcc -c irq.c -o irq.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra  -Wattributes
i686-elf-gcc -c date.c -o date.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra 
i686-elf-gcc -T linker.ld -o os.bin -ffreestanding -O2 -nostdlib boot.o kernel.o gdt.o idt.o isrs.o irq.o terminal.o utils.o date.o -lgcc
grub-file --is-x86-multiboot os.bin
if grub-file --is-x86-multiboot os.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi
mkdir -p isodir/boot/grub
cp os.bin isodir/boot/os.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o os.iso isodir --xorriso=./xorriso/xorriso-1.4.6/xorriso/xorriso
qemu-system-i386 -cdrom os.iso


