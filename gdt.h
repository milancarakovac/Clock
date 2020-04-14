#ifndef GDT_H
#define GDT_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


/* Special pointer which includes the limit: The max bytes
*  taken up by the GDT, minus 1. Again, this NEEDS to be packed */

extern void gdt_flush();
void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
void gdt_install();
#endif