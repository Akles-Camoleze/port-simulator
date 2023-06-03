#include "docks.component.h"

void initialize_docks(Docks *docks) {
    for (int i = 0; i < MOORING_AREA_QUANTITY; ++i) {
        new_queue(&(docks->dock[i]));
    }
}

Queue *get_smaller_queue(Docks *docks) {
    Queue *smaller = docks->dock;
    for (int i = 1; i < MOORING_AREA_QUANTITY; ++i) {
        if (docks->dock[i].size < smaller->size) {
            smaller = &(docks->dock[i]);
        }
    }

    return smaller;
}

void show_mooring_areas(Docks *docks) {
    printf("{");
    char comma = ',';
    for (int i = 0; i < MOORING_AREA_QUANTITY; ++i) {
        if (i == MOORING_AREA_QUANTITY - 1) comma = 0;
        printf("\n\t\"%d\": {\n"
               "\t\tquantidadeNavios:%d\n"
               "\t\t\"navios\": [",
               i + 1,
               docks->dock[i].size
        );
        print_queue(&(docks->dock[i]));
        printf("\n\t\t]");
        printf("\n\t}%c", comma);
    }
    printf("\n}");
}

void hoist(Docks *docks, Crosses *crosses) {
    for (int i = 0; i < MOORING_AREA_QUANTITY; ++i) {
        Node_Ship *node = docks->dock[i].front;
        if (!empty(1, node)) {
            Ship *ship = node->ship;
            Stack *stacks = ship->stacks;
            Stack *last_stack = stacks + STACKS_SHIP_QUANTITY - 1;
            while (stacks != last_stack && stacks->size == 0) stacks++;
            Node_Container *popped = pop(stacks);
            if (popped != NULL) {
                STACK_SIZE max = FOR_CROSS;
                Cross *cross = get_cross(crosses);
                push(cross->stack, popped->container, max);
                ship->load--;
            }
            if (ship->load == 0) {
                unqueue(&(docks->dock[i]));
            }
        }
    }
}