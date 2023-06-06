#include "docks.component.h"

void initialize_docks(Docks *docks, List *list) {
    Node_Cross *node = list->first;
    for (int i = 0; i < MOORING_AREA_QUANTITY; ++i) {
        (*docks)[i].queue = (Queue *) malloc(sizeof(Queue));
        new_queue((*docks)[i].queue);
        (*docks)[i].car_uses = 0;
        (*docks)[i].total_load = 0;
        (*docks)[i].average_time = (float) 0.0;
        (*docks)[i].current_cross = node->cross;
        node = node->next;
    }
}

Dock *get_smaller_dock(Docks *docks) {
    Dock *smaller = *docks;
    for (int i = 1; i < MOORING_AREA_QUANTITY; ++i) {
        if ((*docks)[i].queue->size < smaller->queue->size) {
            smaller = &(*docks)[i];
        }
    }
    return smaller;
}

void show_mooring_areas(Docks *docks) {
    for (int i = 0; i < MOORING_AREA_QUANTITY; ++i) {
        Dock dock = (*docks)[i];
        int cross_id = !empty(1, dock.current_cross) ? dock.current_cross->id : 0;
        printf("\n=================================================================="
               "\nDoca %d: TN: %02d | Espera: %.1f | TC: %03d | Carrinho: %03d | T: %d"
               "\n------------------------------------------------------------------",
               i + 1,
               dock.queue->size,
               dock.average_time,
               dock.total_load,
               dock.car_uses,
               cross_id
        );
        print_queue(dock.queue);
        printf("\n==================================================================\n");
    }
}

void hoist(Docks *docks, Crosses *crosses) {
    for (int i = 0; i < MOORING_AREA_QUANTITY; ++i) {
        Node_Ship *node = get_first((*docks)[i].queue);
        Cross *cross = get_dock_cross(&(*docks)[i], crosses);
        if (!empty(1, node) && !empty(1, cross)) {
            Ship *ship = node->ship;
            Stack *stack = select_ship_stack(ship);
            Node_Container *popped = pop(stack);
            if (!empty(1, popped)) {
                push(cross->stack, popped->container, FOR_CROSS);
                if (cross->stack->size == FOR_CROSS) {
                    to_transport(&(*docks)[i], &cross);
                    crosses->total_time_left += DRAIN_OUT_TIME;
                }
                decrease_load(ship);
                (*docks)[i].total_load--;
            }
            if (check_load(ship, 0)) {
                unqueue((*docks)[i].queue);
            }
        }
    }
}

void to_transport(Dock *dock, Cross **cross) {
    dock->car_uses++;
    (*cross)->time_left = DRAIN_OUT_TIME;
    (*cross)->spare = false;
}