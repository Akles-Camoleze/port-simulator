#include <time.h>
#include "components/docks/docks.component.h"
#include "components/cross/cross.component.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "EndlessLoop"

int main() {
    srand(time(NULL));
    Docks docks;
    Crosses crosses;
    initialize_crosses(&crosses);
    initialize_docks(&docks, crosses.list);

    do {
        int ships = gen_number(0, 3);
        for (int i = 0; i < ships; ++i) {
            Dock *smaller = get_smaller_dock(&docks);
            if (smaller->queue->size < DOCK_MAX_SIZE) {
                Ship *ship = new_ship();
                set_time_stay(ship, smaller, crosses.average_time);
                to_queue(smaller->queue, ship);
                smaller->total_load += ship->load;
            }
        }
        get_crosses_average(&crosses);
        get_docks_averages(&docks, crosses.average_time);
        show_mooring_areas(&docks);
        show_crosses(&crosses);
        manager_crosses(&crosses, cross_handler);
        hoist(&docks, &crosses);
    } while (getchar() == '\n');

    return 0;
}

#pragma clang diagnostic pop
