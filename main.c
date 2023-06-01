#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
int main() {
    srand(time(NULL));

    printf("Hello, World!\n");
    return 0;
}
#pragma clang diagnostic pop
