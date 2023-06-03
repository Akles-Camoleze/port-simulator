#ifndef PORT_SIMULATOR_MOORING_AREA_COMPONENT_H
#define PORT_SIMULATOR_MOORING_AREA_COMPONENT_H
#define MOORING_AREA_QUANTITY 4

#include "../../structs/queue/queue.h"

typedef struct MooringAreas {
    Queue mooring_area[MOORING_AREA_QUANTITY];
} MooringAreas;

void initialize_areas(MooringAreas *areas);

Queue *get_smaller_queue(MooringAreas *areas);

#endif //PORT_SIMULATOR_MOORING_AREA_COMPONENT_H
