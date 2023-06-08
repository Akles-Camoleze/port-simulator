#ifndef PORT_SIMULATOR_UTILS_H
#define PORT_SIMULATOR_UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

int gen_number(int min, int max);

bool empty(int n, ...);

float average_calculator(float numerator, float denominator);

void get_time_uni(int *time_uni);

#endif //PORT_SIMULATOR_UTILS_H
