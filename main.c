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
        printf("{\n");
        printf("  \"travessas\": [");
        char comma = ',';
        for (int i = 0; i < CROSS_QUANTITY; ++i) {
            if (i == CROSS_QUANTITY - 1) comma = 0;
            printf("\n    {"
                   "\n      \"quantidadeContainer\": %d,"
                   "\n      \"tempoDeEspera\": %d"
                   "\n    }%c",
                   crosses[i].stack.size,
                   crosses[i].time_left,
                   comma
            );
        }
        printf("\n  ],");
        printf("\n  \"docas\": [");
        show_mooring_areas(&docks);
        printf("\n  ]");
        printf("\n}");
        manager_cross(&crosses, cross_handler);
        hoist(&docks, &crosses);
    } while (getchar() == '\n');

    return 0;
}

#pragma clang diagnostic pop
