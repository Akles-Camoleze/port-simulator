#include "mooring_area.component.h"

void initialize_areas(MooringAreas *areas) {
    for (int i = 0; i < MOORING_AREA_QUANTITY; ++i) {
        new_queue(&(areas->mooring_area[i]));
    }
}

Queue *get_smaller_queue(MooringAreas *areas) {
    Queue *smaller = areas->mooring_area;
    for (int i = 1; i < MOORING_AREA_QUANTITY; ++i) {
        if (areas->mooring_area[i].size < smaller->size) {
            smaller = &(areas->mooring_area[i]);
        }
    }

    return smaller;
}