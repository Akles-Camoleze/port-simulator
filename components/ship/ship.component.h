#ifndef PORT_SIMULATOR_SHIP_COMPONENT_H
#define PORT_SIMULATOR_SHIP_COMPONENT_H
#define STACKS_QUANTITY 4

#include "../../structs/stack/stack.h"

typedef struct Stack Stack;

typedef struct Ship {
    int id;
    int time_stay;
    int load;
    Stack *stacks;
} Ship;

/*

_______||10||___
\----------300-|
 \____________/
~~~~~~~~~~~~~~~~~~
*/

#endif //PORT_SIMULATOR_SHIP_COMPONENT_H
