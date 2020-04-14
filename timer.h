#ifndef TIMER_H
#define TIMER_H
#include "idt.h"
#include "irq.h"
#include "utils.h"
#include "terminal.h"
void timer_handler(struct regs* r);
void timer_install();
void timer_phase(int hz);
#endif
