#ifndef PORT_SIMULATOR_QUEUE_H
#define PORT_SIMULATOR_QUEUE_H

#include <stdlib.h>
#include <string.h>
#include "../node/node.h"

typedef struct Node_Ship Node_Ship;

typedef struct Ship Ship;

typedef struct Queue {
    Node_Ship *front;
    Node_Ship *rear;
    int size;
} Queue;

/**
 * Cria fila, alocando na memória
 * @param queue: ponteiro da pilha a ser alocada
 */
void new_queue(Queue *queue);

/**
 * Enfilera navio
 * @param queue: fila a ser enfilerada
 * @param ship: navio a ser enfilerado
 */
void to_queue(Queue *queue, Ship *ship);

/**
 * Desenfilera navio
 * @param queue: fila a ser desenfilerada
 * @return nó do respectivo navio desenfilerado
 */
Node_Ship *unqueue(Queue *queue);

/**
 * Exibe a fila
 * @param queue: fila a ser exibida
 */
void print_queue(Queue *queue);

/**
 * Recupera primeiro navio da fila
 * @param queue: fila a ter o navio recuperado
 * @return nó do respectivo navio recuperado
 */
Node_Ship *get_first(Queue *queue);

#endif //PORT_SIMULATOR_QUEUE_H
