#include "irq.h"
static int ticks;
__attribute__((interrupt)) void irq0(struct regs *r)// timer
{
	
	asm("cli");
	terminal_initialize();
	
	if(ticks%(18*60))
	{
	outportb(0x70,(1<<7)|0x02);
	for(int i=0;i<100;i++);
	char inp = inportb(0x71);
	outportb(0x70,(1<<7)|0x04);
	for(int i=0;i<100;i++){};
	int inp2 = (int)inportb(0x71);
	terminal_writestring("\n");
	writeNumber(setHour(inp2),setMinute(inp));
	
	//Ispis datuma:
	outportb(0x70,(1<<7)|0x07);
	for(int i=0;i<100;i++){};
	int day = (int)inportb(0x71);
	outportb(0x70,(1<<7)|0x08);
	for(int i=0;i<100;i++){};
	int month = (int)inportb(0x71);
	outportb(0x70,(1<<7)|0x09);
	for(int i=0;i<100;i++){};
	int year = (int)inportb(0x71);
	writeDate(setDay(day),setMonth(month),setYear(year));
	}
	ticks++;
	outportb(0x20, 0x20);	
	asm("sti");
}

__attribute__((interrupt)) void irq1(struct regs *r)
{
	asm("cli");
	unsigned char scancode=inportb(0x60);
	if(scancode==0x02)
		change_clock_color(1);
	else if(scancode==0x03)
		change_clock_color(2);
	else if(scancode==0x04)
		change_clock_color(3);
	else if(scancode==0x05)
		change_clock_color(4);
	else if(scancode==0x06)
		change_clock_color(5);
	else if(scancode==0x07)
		change_clock_color(6);
	else if(scancode==0x08)
		change_clock_color(0x08);
	else if(scancode==0x09)
		change_clock_color(7);
	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq2(struct regs *r)
{
		asm("cli");

	
		outportb(0x20, 0x20);
		asm("sti");
}
__attribute__((interrupt)) void irq3(struct regs *r)
{
	asm("cli");

	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq4(struct regs *r)
{
	asm("cli");

	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq5(struct regs *r)
{
	asm("cli");

	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq6(struct regs *r)
{
	asm("cli");

	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq7(struct regs *r)
{
	

	asm("cli");

	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq8(struct regs *r)
{
	asm("cli");
	outportb(0xA0, 0x20);

	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq9(struct regs *r)
{
	asm("cli");
	outportb(0xA0, 0x20);

	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq10(struct regs *r)
{
	asm("cli");
	outportb(0xA0, 0x20);

	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq11(struct regs *r)
{
	asm("cli");
	outportb(0xA0, 0x20);

	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq12(struct regs *r)
{
	asm("cli");
	outportb(0xA0, 0x20);

	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq13(struct regs *r)
{
	asm("cli");
	outportb(0xA0, 0x20);

	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq14(struct regs *r)
{
	asm("cli");
	outportb(0xA0, 0x20);

	
	outportb(0x20, 0x20);
	asm("sti");
}
__attribute__((interrupt)) void irq15(struct regs *r)
{
	asm("cli");
	outportb(0xA0, 0x20);

	
	outportb(0x20, 0x20);
	asm("sti");
}

void* irq_routines[16] =
{
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0
};

void irq_install_handler(int irq, void (*handler)(struct regs* r))
{
	irq_routines[irq] = handler;
}
void irq_uninstall_handler(int irq)
{
	irq_routines[irq] = 0;
}

void irq_remap() //  =====DoubleFault===>
{
	outportb(0x20, 0x11);
	outportb(0xA0, 0x11);
	outportb(0x21, 0x20);
	outportb(0xA1, 0x28);
	outportb(0x21, 0x04);
	outportb(0xA1, 0x02);
	outportb(0x21, 0x01);
	outportb(0xA1, 0x01);
	outportb(0x21, 0x0);
	outportb(0xA1, 0x0);
	
	
}
void irq_install()
{
	irq_remap();

	idt_set_gate(32, (unsigned)irq0, 0x08, 0x8E);
	idt_set_gate(33, (unsigned)irq1, 0x08, 0x8E);
	idt_set_gate(34, (unsigned)irq2, 0x08, 0x8E);
	idt_set_gate(35, (unsigned)irq3, 0x08, 0x8E);
	idt_set_gate(36, (unsigned)irq4, 0x08, 0x8E);
	idt_set_gate(37, (unsigned)irq5, 0x08, 0x8E);
	idt_set_gate(38, (unsigned)irq6, 0x08, 0x8E);
	idt_set_gate(39, (unsigned)irq7, 0x08, 0x8E);
	idt_set_gate(40, (unsigned)irq8, 0x08, 0x8E);
	idt_set_gate(41, (unsigned)irq9, 0x08, 0x8E);
	idt_set_gate(42, (unsigned)irq10, 0x08, 0x8E);
	idt_set_gate(43, (unsigned)irq11, 0x08, 0x8E);
	idt_set_gate(44, (unsigned)irq12, 0x08, 0x8E);
	idt_set_gate(45, (unsigned)irq13, 0x08, 0x8E);
	idt_set_gate(46, (unsigned)irq14, 0x08, 0x8E);
	idt_set_gate(47, (unsigned)irq15, 0x08, 0x8E);
}
/*void irq_handler(struct regs* r)
{
	 This is a blank function pointer 
	void (*handler)(struct regs* r);
	terminal_writestring("irq\n");
	
	handler = irq_routines[r->int_no - 32];
	if (handler )
		handler(r);

	if (r->int_no >= 40)
		outportb(0xA0, 0x20);

	
	outportb(0x20, 0x20);

	
	terminal_writestring("after irq\n");
}*/