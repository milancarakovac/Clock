#ifndef DATE_H
#define DATE_H

#include "utils.h"
#include "terminal.h"

void createDate(int d1,int d2, int d3,int d4,int d5,int d6, int d7, int d8);
void writeDate(int day, int month, int year);
int setDay(int inp);
int setMonth(int inp);
int setYear(int inp);
void createNumber(int firstDigit,int secondDigit,int thirdDigit,int fourthDigit);
void writeNumber(int hours, int minutes);
int setMinute(int inp);
int setHour(int inp);
#endif