#ifndef PORT_SIMULATOR_DOCKS_COMPONENT_H
#define PORT_SIMULATOR_DOCKS_COMPONENT_H
#define MOORING_AREA_QUANTITY 4
#define DOCK_MAX_SIZE 20

#include "../../structs/queue/queue.h"
#include "../cross/cross.component.h"

typedef struct Cross Cross;
typedef struct Crosses Crosses;
typedef struct Queue Queue;
typedef struct List List;

typedef struct Dock {
    Queue *queue;
    Cross *current_cross;
    int car_uses;
    int total_load;
    float average_time;
} Dock;

typedef struct Dock Docks[MOORING_AREA_QUANTITY];


void initialize_docks(Docks *docks, List *list);

Dock *get_smaller_dock(Docks *docks);

void show_mooring_areas(Docks *docks);

void hoist(Docks *docks, Crosses *crosses);

void to_transport(Dock *dock, Cross **cross);

#endif //PORT_SIMULATOR_DOCKS_COMPONENT_H
