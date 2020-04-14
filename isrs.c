#include "isrs.h"
__attribute__ ((interrupt)) void isr0(struct regs *r){
	asm("cli");
	terminal_writestring("Division By Zero Exception");
	
	asm("sti");
}

__attribute__ ((interrupt)) void isr1(struct regs *r){
	asm("cli");
	terminal_writestring("Debug Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr2(struct regs *r){
	asm("cli");
	terminal_writestring("Non Maskable Interrupt Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr3(struct regs *r){
	asm("cli");
	terminal_writestring("Breakpoint Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr4(struct regs *r){
	asm("cli");
	terminal_writestring("Into Detected Overflow Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr5(struct regs *r){
	asm("cli");
	terminal_writestring("Out Of Bounds Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr6(struct regs *r){
	asm("cli");
	terminal_writestring("Invalid Opcode Exception");
	asm("sti");
	}
	
__attribute__ ((interrupt)) void isr7(struct regs *r){
	asm("cli");
	terminal_writestring("No Coprocessor Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr8(struct regs *r,uint16_t error_code){
	asm("cli");
	terminal_writestring("Double Fault Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr9(struct regs *r){
	asm("cli");
	terminal_writestring("Coprocessor Segment Overrun Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr10(struct regs *r ,uint16_t error_code){
	asm("cli");
	terminal_writestring("Bad TSS Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr11(struct regs *r ,uint16_t error_code){
	asm("cli");
	terminal_writestring("Segment Not Present Exception ");
	asm("sti");
}

__attribute__ ((interrupt)) void isr12(struct regs *r ,uint16_t error_code){
	asm("cli");
	terminal_writestring("Stack Fault Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr13(struct regs *r ,uint16_t error_code){
	asm("cli");
	terminal_writestring("General Protection Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr14(struct regs *r ,uint16_t error_code){
	asm("cli");
	terminal_writestring("Page Fault Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr15(struct regs *r){
	asm("cli");
	terminal_writestring("Unknown Interrupt Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr16(struct regs *r){
	asm("cli");
	terminal_writestring("Coprocessor Fault Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr17(struct regs *r){
	asm("cli");
	terminal_writestring("Alignment Check Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr18(struct regs *r){
	asm("cli");
	terminal_writestring("Machine Check Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr19(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr20(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr21(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr22(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr23(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr24(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr25(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr26(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr27(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr28(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr29(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}

__attribute__ ((interrupt)) void isr30(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}
__attribute__ ((interrupt)) void isr31(struct regs *r){
	asm("cli");
	terminal_writestring("Reserved Exception");
	asm("sti");
}


void isrs_install()
{
	idt_set_gate(0,  (unsigned)isr0, 0x08, 0x8E);
	idt_set_gate(1,  (unsigned)isr1, 0x08, 0x8E);
	idt_set_gate(2,  (unsigned)isr2, 0x08, 0x8E);
	idt_set_gate(3,  (unsigned)isr3, 0x08, 0x8E);
	idt_set_gate(4,  (unsigned)isr4, 0x08, 0x8E);
	idt_set_gate(5,  (unsigned)isr5, 0x08, 0x8E);
	idt_set_gate(6,  (unsigned)isr6, 0x08, 0x8E);
	idt_set_gate(7,  (unsigned)isr7, 0x08, 0x8E);
	idt_set_gate(8,  (unsigned)isr8, 0x08, 0x8E);
	idt_set_gate(9,  (unsigned)isr9, 0x08, 0x8E);
	idt_set_gate(10, (unsigned)isr10, 0x08, 0x8E);
	idt_set_gate(11, (unsigned)isr11, 0x08, 0x8E);
	idt_set_gate(12, (unsigned)isr12, 0x08, 0x8E);
	idt_set_gate(13, (unsigned)isr13, 0x08, 0x8E);
	idt_set_gate(14, (unsigned)isr14, 0x08, 0x8E);
	idt_set_gate(15, (unsigned)isr15, 0x08, 0x8E);
	idt_set_gate(16, (unsigned)isr16, 0x08, 0x8E);
	idt_set_gate(17, (unsigned)isr17, 0x08, 0x8E);
	idt_set_gate(18, (unsigned)isr18, 0x08, 0x8E);
	idt_set_gate(19, (unsigned)isr19, 0x08, 0x8E);
	idt_set_gate(20, (unsigned)isr20, 0x08, 0x8E);
	idt_set_gate(21, (unsigned)isr21, 0x08, 0x8E);
	idt_set_gate(22, (unsigned)isr22, 0x08, 0x8E);
	idt_set_gate(23, (unsigned)isr23, 0x08, 0x8E);
	idt_set_gate(24, (unsigned)isr24, 0x08, 0x8E);
	idt_set_gate(25, (unsigned)isr25, 0x08, 0x8E);
	idt_set_gate(26, (unsigned)isr26, 0x08, 0x8E);
	idt_set_gate(27, (unsigned)isr27, 0x08, 0x8E);
	idt_set_gate(28, (unsigned)isr28, 0x08, 0x8E);
	idt_set_gate(29, (unsigned)isr29, 0x08, 0x8E);
	idt_set_gate(30, (unsigned)isr30, 0x08, 0x8E);
	idt_set_gate(31, (unsigned)isr31, 0x08, 0x8E);
	
}

