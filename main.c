#include <time.h>
#include "components/docks/docks.component.h"
#include "components/cross/cross.component.h"

int main() {
    srand(time(NULL));
    Docks docks;
    Crosses crosses;
    int time_uni = 1;
    initialize_crosses(&crosses);
    initialize_docks(&docks, crosses.list);

    do {
        get_time_uni(&time_uni);
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
        printf("'Enter' para continuar ");
    } while (getchar() == '\n');

    return 0;
}