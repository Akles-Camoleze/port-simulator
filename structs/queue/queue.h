#ifndef PORT_SIMULATOR_QUEUE_H
#define PORT_SIMULATOR_QUEUE_H

#include "../node/node.h"

typedef struct Queue {
    Node_Ship *front;
    Node_Ship *rear;
    int size;
} Queue;

#endif //PORT_SIMULATOR_QUEUE_H
