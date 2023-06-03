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

Cross *get_cross(Crosses *crosses);

#endif //PORT_SIMULATOR_CROSS_COMPONENT_H