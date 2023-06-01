#include "utils.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
int gen_number(int min, int max) {
    return min + rand() % (max - min + 1);
}
#pragma clang diagnostic pop
