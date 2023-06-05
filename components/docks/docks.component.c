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
        Node_Ship *node = docks[i]->queue.front;
        if (!empty(1, node)) {
            Ship *ship = node->ship;
            Stack *stacks = ship->stacks;
            Stack *last_stack = stacks + STACKS_SHIP_QUANTITY - 1;
            while (stacks != last_stack && stacks->size == 0) stacks++;
            Node_Container *popped = pop(stacks);
            if (popped != NULL) {
                STACK_SIZE max = FOR_CROSS;
                Cross *cross = manager_crosses(crosses, select_cross);
                push(&cross->stack, popped->container, max);
                if (cross->stack.size == max) {
                    docks[i]->car_uses++;
                    cross->time_left = 2;
                }
                ship->load--;
            }
            if (ship->load == 0) {
                unqueue(&(docks[i]->queue));
            }
        }
    }
}