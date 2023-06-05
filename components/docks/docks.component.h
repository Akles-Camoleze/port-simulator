#ifndef PORT_SIMULATOR_DOCKS_COMPONENT_H
#define PORT_SIMULATOR_DOCKS_COMPONENT_H
#define MOORING_AREA_QUANTITY 4
#define DOCK_MAX_SIZE 20

#include "../../structs/queue/queue.h"
#include "../cross/cross.component.h"

typedef struct Docks {
    Queue dock[MOORING_AREA_QUANTITY];
} Docks;

void initialize_docks(Docks *docks);

Queue *get_smaller_queue(Docks *docks);

void show_mooring_areas(Docks *docks);

void hoist(Docks *docks, Crosses *crosses);

#endif //PORT_SIMULATOR_DOCKS_COMPONENT_H
