#include "ship.component.h"

Ship *new_ship() {
    Ship *ship = (Ship *) malloc(sizeof(Ship));
    ship->id = gen_number(1, 999);
    ship->load = gen_number(4, 16);
    ship->time_stay = gen_number(1, 50);
    ship->stacks = (Stack *) malloc(STACKS_SHIP_QUANTITY * sizeof(Stack));
    get_containers(ship);
    return ship;
}

void get_containers(Ship *ship) {
    STACK_SIZE max = FOR_SHIP;
    for (int i = 0; i < ship->load; i++) {
        Container *container = new_container();
        push(&(ship->stacks[i % STACKS_SHIP_QUANTITY]), container, max);
    }
}
