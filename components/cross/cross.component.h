#ifndef PORT_SIMULATOR_CROSS_COMPONENT_H
#define PORT_SIMULATOR_CROSS_COMPONENT_H
#define CROSS_QUANTITY 5

#include <stdbool.h>
#include "../../structs/stack/stack.h"
#include "../docks/docks.component.h"

typedef struct Dock Dock;

typedef struct Cross {
    Stack stack;
    int time_left;
} Cross;

typedef struct Cross *Crosses;

void initialize_crosses(Crosses *crosses);

Cross *manager_crosses(Crosses *crosses, void (*operation)(Crosses *));

void select_cross(Crosses *crosses);

void cross_handler(Crosses *crosses);

void show_crosses(Crosses *crosses);

void to_cross(Dock *dock, Crosses *crosses, Node_Container *node);

#endif //PORT_SIMULATOR_CROSS_COMPONENT_H
