#ifndef PORT_SIMULATOR_CROSS_COMPONENT_H
#define PORT_SIMULATOR_CROSS_COMPONENT_H
#define CROSS_QUANTITY 5
#define DRAIN_OUT_TIME 2

#include <stdbool.h>
#include "../../structs/stack/stack.h"
#include "../docks/docks.component.h"

typedef struct Dock Dock;

typedef struct Cross {
    Stack stack;
    int time_left;
} Cross;

typedef struct Crosses {
    Cross *cross;
    int total_time_left;
    float average_time;
} Crosses;

void initialize_crosses(Crosses *crosses);

Cross *manager_crosses(Crosses *crosses, int (*operation)(Cross **, int));

int select_cross(Cross **crosses, int);

int cross_handler(Cross **crosses, int);

void show_crosses(Crosses *crosses);

void to_cross(Dock *dock, Crosses *crosses, Node_Container *node);

#endif //PORT_SIMULATOR_CROSS_COMPONENT_H
