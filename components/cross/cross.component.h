#ifndef PORT_SIMULATOR_CROSS_COMPONENT_H
#define PORT_SIMULATOR_CROSS_COMPONENT_H
#define CROSS_QUANTITY 5

#include <stdbool.h>
#include "../../structs/stack/stack.h"

typedef struct Cross {
    Stack *stack;
    int time_left;
} Cross;

typedef struct Cross *Crosses;

void initialize_crosses(Crosses *crosses);

Cross *cross_handler(Crosses *crosses, void (*operation)(Cross *, Cross *, int));

void increase(Cross *cross, Cross *last_cross, int size);

void decrease(Cross *cross, Cross *last_cross, int size);

#endif //PORT_SIMULATOR_CROSS_COMPONENT_H
