#ifndef PORT_SIMULATOR_UTILS_H
#define PORT_SIMULATOR_UTILS_H
#ifdef _WIN32
#include <windows.h>
#else

#include <unistd.h>

#endif

#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

int gen_number(int min, int max);

void sleep_milliseconds(unsigned long milliseconds);

bool empty(int n, ...);

float average_calculator(float numerator, float denominator);

#endif //PORT_SIMULATOR_UTILS_H
