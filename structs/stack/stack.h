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

typedef enum {
    EMPTY = 0,
    FOR_SHIP = 4,
    FOR_CROSS = 5
} STACK_SIZE;

/**
 * Cria nova pilha, alocando na memória
 * @param stack ponteiro da pilha a ser alocada
 */
void new_stack(Stack *stack);

/**
 * Empilha container
 * @param stack: pilha a ser empilhada
 * @param container: dado a ser empilhado
 * @param max: tamanho maximo da pilha
 */
void push(Stack *stack, Container *container, int max);

/**
 * Desempilha container
 * @param stack: pilha a ser desempilhada
 * @return nó do respectivo container desempilhado
 */
Node_Container *pop(Stack *stack);

#endif //PORT_SIMULATOR_STACK_H