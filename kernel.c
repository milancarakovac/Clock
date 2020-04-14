#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "terminal.h"
 #include "utils.h"
 #include "gdt.h"
 #include "idt.h"
#include "isrs.h"
#include "irq.h"
#include "timer.h"
#include "date.h"
/* Check if the compiler thinks we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif



void kernel_main(void){
	gdt_install();
	idt_install();
	isrs_install();
	irq_install();
	change_clock_color((uint8_t)2);
	terminal_initialize() ;
	asm("sti");
	outportb (0x3d4,0x0a);
	outportb(0x3d5,0x20);
	for(;;);
	
}