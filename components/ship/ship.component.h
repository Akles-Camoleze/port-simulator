#ifndef PORT_SIMULATOR_SHIP_COMPONENT_H
#define PORT_SIMULATOR_SHIP_COMPONENT_H
#define STACKS_SHIP_QUANTITY 4

#include "../../structs/stack/stack.h"

typedef struct Stack Stack;
typedef struct Dock Dock;

typedef struct Ship {
    int id;
    int load;
    float time_stay;
    Stack *stacks;
} Ship;

Ship *new_ship();

void get_containers(Ship *ship);

Stack *select_ship_stack(Ship *ship);

void decrease_load(Ship *ship);

bool check_load(Ship *ship, int load);

void set_time_stay(Ship *ship, Dock *dock, float crosses_average);

#endif //PORT_SIMULATOR_SHIP_COMPONENT_H
