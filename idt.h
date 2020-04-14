#ifndef IDT_H
#define IDT_H
#include "utils.h"
#include "terminal.h"

 
 void idt_install();
extern void idt_load();
 void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
#endif