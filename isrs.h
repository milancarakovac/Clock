#ifndef ISRS_H
#define ISRS_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "utils.h"
#include "terminal.h"
#include "idt.h"

struct regs
{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
        /* our 'push byte #' and ecodes do this */
    //unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
};


void isrs_install();
void fault_handler(struct regs* r);
#endif