#include "ship.component.h"
int ship_id = 1;

Ship *new_ship() {
    Ship *ship = (Ship *) malloc(sizeof(Ship));
    ship->id = ship_id;
    ship->load = gen_number(4, 16);
    ship->time_stay = gen_number(1, 50);
    ship->stacks = (Stack *) malloc(STACKS_SHIP_QUANTITY * sizeof(Stack));
    get_containers(ship);
    ship_id++;
    return ship;
}

void get_containers(Ship *ship) {
    STACK_SIZE max = FOR_SHIP;
    for (int i = 0; i < ship->load; i++) {
        Container *container = new_container();
        push(&(ship->stacks[i % STACKS_SHIP_QUANTITY]), container, max);
    }
}
