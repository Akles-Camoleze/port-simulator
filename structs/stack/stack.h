#ifndef PORT_SIMULATOR_STACK_H
#define PORT_SIMULATOR_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../node/node.h"
#include "../../utils/utils.h"

typedef struct Node_Container Node_Container;

typedef struct Stack {
    Node_Container *top;
    int size;
} Stack;

typedef enum STACK_SIZE {
    FOR_SHIP = 4,
    FOR_CROSS = 5
} STACK_SIZE;

void new_stack(Stack *stack);

void push(Stack *stack, Container *container, int max);

Node_Container *pop(Stack *stack);

void print_stack(Stack *stack);

#endif //PORT_SIMULATOR_STACK_H