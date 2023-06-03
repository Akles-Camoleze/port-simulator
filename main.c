#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs/stack/stack.h"
#include "structs/queue/queue.h"
#include "utils/utils.h"
#include "components/mooring_area/mooring_area.component.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "EndlessLoop"

int main() {
    srand(time(NULL));
    MooringAreas areas;
    initialize_areas(&areas);

    do {
        int ships = gen_number(1, 4);
        for (int i = 0; i < ships; ++i) {
            Queue *smaller = get_smaller_queue(&areas);
            Ship *ship = (Ship *) malloc(sizeof(Ship));
            ship->id = gen_number(1, 999);
            ship->load = gen_number(4, 16);
            ship->time_stay = gen_number(1, 50);
            to_queue(smaller, ship);
        }
    } while (getchar() == '\n');

    printf("{");
    char comma = ',';
    for (int i = 0; i < MOORING_AREA_QUANTITY; ++i) {
        if(i == MOORING_AREA_QUANTITY - 1) comma = 0;
        printf("\n\t\"%d\": {\n"
               "\t\t\"navios\": [",
               i + 1
        );
        print_queue(&(areas.mooring_area[i]));
        printf("\n\t\t]");
        printf("\n\t}%c", comma);
    }
    printf("\n}");

    return 0;
}

#pragma clang diagnostic pop
