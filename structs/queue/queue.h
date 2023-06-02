#ifndef PORT_SIMULATOR_QUEUE_H
#define PORT_SIMULATOR_QUEUE_H

#include "../node/node.h"

typedef struct Queue {
    Node_Ship *front;
    Node_Ship *rear;
    int size;
} Queue;

void new_queue(Queue *queue);

void to_queue(Queue *queue, Ship *ship);

Node_Ship *unqueue(Queue *queue);

#endif //PORT_SIMULATOR_QUEUE_H
