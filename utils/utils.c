#include "utils.h"

int gen_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

bool empty(int n, ...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) {
        void *ptr = va_arg(args, void *);
        if (ptr != NULL) {
            va_end(args);
            return false;
        }
    }
    va_end(args);
    return true;
}

float average_calculator(float numerator, float denominator) {
    if (denominator == 0.0) return denominator;
    return numerator / denominator;
}

void get_time_uni(int *time_uni) {
    printf("\n--------------------------------Uni %03d--------------------------------", *time_uni);
    (*time_uni)++;
}
