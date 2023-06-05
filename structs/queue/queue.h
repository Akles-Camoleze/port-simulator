#ifndef PORT_SIMULATOR_QUEUE_H
#define PORT_SIMULATOR_QUEUE_H

#include <stdlib.h>
#include <string.h>
#include "../node/node.h"

typedef struct Queue {
    Node_Ship *front;
    Node_Ship *rear;
    int size;
} Queue;

void new_queue(Queue *queue);

void to_queue(Queue *queue, Ship *ship);

Node_Ship *unqueue(Queue *queue);

void print_queue(Queue *queue);

Node_Ship *get_first(Queue *queue);

#endif //PORT_SIMULATOR_QUEUE_H
