#ifndef PORT_SIMULATOR_STACK_H
#define PORT_SIMULATOR_STACK_H

#include <stdlib.h>
#include <stdbool.h>
#include "../node/node.h"
#include "../../components/container/container.component.h"
#include "../../utils/utils.h"

enum STACKS_SIZE {
    FOR_SHIP = 4,
    FOR_CROSS
};

typedef struct Stack {
    Node_Container *top;
    int size;
} Stack;

void new_stack(Stack *stack);

void push(Stack *stack, Container *container);

Node_Container *pop(Stack *stack);

#endif //PORT_SIMULATOR_STACK_H