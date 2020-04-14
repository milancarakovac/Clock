#ifndef UTILS_H
#define UTILS_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
void *memcpy(void *dest, const void *src, size_t count);

void *memset(void *dest, char val, size_t count);


unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count);



unsigned char inportb (unsigned short _port);


void outportb (unsigned short _port, unsigned char _data);
#endif
