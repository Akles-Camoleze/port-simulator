#ifndef PORT_SIMULATOR_STACK_H
#define PORT_SIMULATOR_STACK_H

#include "../node/node.h"
#include "../../components/container/container.component.h"

enum STACKS_SIZE {
    FOR_SHIP = 4,
    FOR_CROSS
};

typedef struct Stack {
    Node_Container *top;
    int size;
} Stack;

#endif //PORT_SIMULATOR_STACK_H