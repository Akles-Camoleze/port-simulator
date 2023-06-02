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


void new_stack(Stack *stack);

void push(Stack *stack, Container *container);

Node_Container *pop(Stack *stack);

void print_stack(Stack *stack);

#endif //PORT_SIMULATOR_STACK_H