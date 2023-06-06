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
        printf("\n------------------------------------------------");
        printf("\nDoca %d: Possui %d navio(s), tempo medio %.1f e total de container %d"
               "\nCarrinho usado %d vez(es)",
               i + 1,
               (*docks)[i].queue->size,
               (*docks)[i].average_time,
               (*docks)[i].total_load,
               (*docks)[i].car_uses
        );
        print_queue((*docks)[i].queue);
        printf("\n------------------------------------------------\n");
    }
}

void hoist(Docks *docks, Crosses *crosses) {
    for (int i = 0; i < MOORING_AREA_QUANTITY; ++i) {
        Node_Ship *node = get_first((*docks)[i].queue);
        Cross *cross = to_cross(&(*docks)[i], crosses);
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