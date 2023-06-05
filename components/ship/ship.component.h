#ifndef PORT_SIMULATOR_SHIP_COMPONENT_H
#define PORT_SIMULATOR_SHIP_COMPONENT_H
#define STACKS_SHIP_QUANTITY 4

#include "../../structs/stack/stack.h"

typedef struct Stack Stack;

typedef struct Ship {
    int id;
    int time_stay;
    int load;
    Stack *stacks;
} Ship;

Ship *new_ship();

void get_containers(Ship *ship);

Stack *select_ship_stack(Ship *ship);

void decrease_load(Ship *ship);

bool check_load(Ship *ship, int load);

#endif //PORT_SIMULATOR_SHIP_COMPONENT_H
