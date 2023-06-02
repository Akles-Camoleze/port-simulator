#ifndef PORT_SIMULATOR_SHIP_COMPONENT_H
#define PORT_SIMULATOR_SHIP_COMPONENT_H
#define STACKS_QUANTITY 4

#include "../../structs/stack/stack.h"

typedef struct Ship {
    int id;
    int time_stay;
    int load;
    Stack stacks[STACKS_QUANTITY];
} Ship;

/*

_______||10||___
\----------300-|
 \____________/
~~~~~~~~~~~~~~~~~~
*/

#endif //PORT_SIMULATOR_SHIP_COMPONENT_H
