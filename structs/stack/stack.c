#include "stack.h"

void new_stack(Stack *stack) {
    stack->top = NULL;
    stack->size = 0;
}

void push(Stack *stack, Container *container) {
    Node_Container *new_node = (Node_Container *) malloc(sizeof(Node_Container));
    new_node->container = container;
    new_node->next = NULL;
    if (!empty(1, (void *) stack->top)) {
        new_node->next = stack->top;
    }
    stack->top = new_node;
    stack->size++;
}

Node_Container *pop(Stack *stack) {
    if (empty(1, (void *) stack->top)) return NULL;
    Node_Container *rm_node = stack->top;
    stack->top = stack->top->next;
    rm_node->next = NULL;
    return rm_node;
}