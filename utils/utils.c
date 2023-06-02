#include "utils.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
int gen_number(int min, int max) {
    return min + rand() % (max - min + 1);
}
#pragma clang diagnostic pop

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
