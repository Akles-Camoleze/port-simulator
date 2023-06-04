#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs/stack/stack.h"
#include "structs/queue/queue.h"
#include "utils/utils.h"
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
            Ship *ship = new_ship();
            Queue *smaller = get_smaller_queue(&docks);
            to_queue(smaller, ship);
        }
        show_mooring_areas(&docks);
        cross_handler(&crosses, decrease);
        hoist(&docks, &crosses);
    } while (getchar() == '\n');

    return 0;
}

#pragma clang diagnostic pop
