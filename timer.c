#include "timer.h"
void timer_handler(struct regs* r)
{
	terminal_initialize();
	terminal_writestring("timer");
	for(;;);
}
void timer_install()
{
	
	timer_phase(18.22);
	irq_install_handler(0, timer_handler);
}
void timer_phase(int hz)
{
	int divisor = 1193180 / hz;	/* Calculate our divisor */
	
	outportb(0x43, 0x36);		/* Set our command byte to 0x36 */
	outportb(0x40, divisor & 0xFF);	/* Set low byte of divisor */
	outportb(0x40, divisor >> 8);	/* Set high byte of divisor */
}