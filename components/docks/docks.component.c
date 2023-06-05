#include "docks.component.h"

void initialize_docks(Docks *docks) {
    for (int i = 0; i < MOORING_AREA_QUANTITY; ++i) {
        new_queue(&(docks[i]->queue));
        docks[i]->car_uses = 0;
    }
}

Queue *get_smaller_queue(Docks *docks) {
    Queue *smaller = &(*docks)->queue;
    for (int i = 1; i < MOORING_AREA_QUANTITY; ++i) {
        if (docks[i]->queue.size < smaller->size) {
            smaller = &(docks[i]->queue);
        }
    }

    return smaller;
}

void show_mooring_areas(Docks *docks) {
    for (int i = 0; i < MOORING_AREA_QUANTITY; ++i) {
        printf("\n------------------------------------------------");
        printf("\nDoca %d: Possui %d navio(s)"
               "\nCarrinho usado %d vez(es)",
               i + 1,
               docks[i]->queue.size,
               docks[i]->car_uses
        );
        print_queue(&(docks[i]->queue));
        printf("\n------------------------------------------------\n");
    }
}

void hoist(Docks *docks, Crosses *crosses) {
    for (int i = 0; i < MOORING_AREA_QUANTITY; ++i) {
        Node_Ship *node = get_first(&docks[i]->queue);
        if (!empty(1, node)) {
            Ship *ship = node->ship;
            Stack *stack = select_ship_stack(ship);
            Node_Container *popped = pop(stack);
            if (!empty(1, popped)) {
                to_cross(docks[i], crosses, popped);
                decrease_load(ship);
            }
            if (check_load(ship, 0)) {
                unqueue(&(docks[i]->queue));
            }
        }
    }
}

void to_transport(Dock *dock, Cross **cross, bool transport) {
    if (transport) {
        dock->car_uses++;
        (*cross)->time_left = 2;
    }
}