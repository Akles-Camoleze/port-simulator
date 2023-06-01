#ifndef PORT_SIMULATOR_NODE_H
#define PORT_SIMULATOR_NODE_H

#include "../../components/container/container.component.h"
#include "../../components/ship/ship.component.h"

#define DECLARE_NODE_TYPE(T) \
typedef struct Node_##T { \
    T data; \
    struct Node_##T *next; \
} Node_##T;

DECLARE_NODE_TYPE(Container)
DECLARE_NODE_TYPE(Ship)

typedef void (*print_node_data)(void*);

typedef void (*free_node)(void*);


#endif //PORT_SIMULATOR_NODE_H
