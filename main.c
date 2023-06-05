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
    initialize_docks(&docks);
    initialize_crosses(&crosses);

    do {
        int ships = gen_number(1, 4);
        for (int i = 0; i < ships; ++i) {
            Queue *smaller = get_smaller_queue(&docks);
            if (smaller->size < DOCK_MAX_SIZE) {
                Ship *ship = new_ship();
                to_queue(smaller, ship);
            }
        }
        show_mooring_areas(&docks);
        show_crosses(&crosses);
        manager_crosses(&crosses, cross_handler);
        hoist(&docks, &crosses);
    } while (getchar() == '\n');

    return 0;
}

#pragma clang diagnostic pop
