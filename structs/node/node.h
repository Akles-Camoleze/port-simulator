#ifndef PORT_SIMULATOR_NODE_H
#define PORT_SIMULATOR_NODE_H

#include "../../components/container/container.component.h"
#include "../../components/ship/ship.component.h"
#include "../../components/cross/cross.component.h"

#define DECLARE_NODE_TYPE(T, t) \
typedef struct Node_##T { \
    T *t; \
    struct Node_##T *next; \
} Node_##T;

typedef struct Ship Ship;

typedef struct Cross Cross;

DECLARE_NODE_TYPE(Container, container)
DECLARE_NODE_TYPE(Ship, ship)
DECLARE_NODE_TYPE(Cross, cross)

#endif //PORT_SIMULATOR_NODE_H
