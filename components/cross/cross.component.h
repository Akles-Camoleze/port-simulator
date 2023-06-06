#ifndef PORT_SIMULATOR_CROSS_COMPONENT_H
#define PORT_SIMULATOR_CROSS_COMPONENT_H
#define CROSS_QUANTITY 5
#define DRAIN_OUT_TIME 2

#include <stdbool.h>
#include "../../structs/stack/stack.h"
#include "../docks/docks.component.h"
#include "../../structs/list/list.h"

typedef struct Dock Dock;
typedef struct Node_Container Node_Container;
typedef struct Node_Cross Node_Cross;
typedef struct Stack Stack;
typedef struct List List;

typedef struct Cross {
    int id;
    int time_left;
    bool spare;
    Stack *stack;
} Cross;

typedef struct Crosses {
    List *list;
    int total_time_left;
    float average_time;
} Crosses;

void initialize_crosses(Crosses *crosses);

Cross *manager_crosses(Crosses *crosses, int (*operation)(Node_Cross **, int));

int select_cross(Node_Cross **crosses, int);

int cross_handler(Node_Cross **first, int);

void show_crosses(Crosses *crosses);

Cross *get_dock_cross(Dock *dock, Crosses *crosses);

#endif //PORT_SIMULATOR_CROSS_COMPONENT_H
