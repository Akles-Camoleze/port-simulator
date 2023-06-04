#include "cross.component.h"

void initialize_crosses(Crosses *crosses) {
    *crosses = (Crosses) malloc(CROSS_QUANTITY * sizeof(Cross));
    for (int i = 0; i < CROSS_QUANTITY; ++i) {
        Cross *cross = &((*crosses)[i]);
        cross->stack = (Stack *) malloc(sizeof(Stack));
        new_stack(cross->stack);
        cross->time_left = 0;
    }
}

Cross *cross_handler(Crosses *crosses, void (*operation)(Cross *, Cross *, int)) {
    STACK_SIZE size = FOR_CROSS;
    Cross *cross = *crosses;
    Cross *last_cross = cross + CROSS_QUANTITY - 1;
    if (operation == decrease) size = EMPTY;
    operation(cross, last_cross, size);
    return cross;
}

void increase(Cross *cross, Cross *last_cross, int size) {
    while (cross != last_cross && cross->stack->size == size) {
        cross->time_left = 2;
        cross++;
    }
}

void decrease(Cross *cross, Cross *last_cross, int size) {
    while (cross != last_cross) {
        if (cross->time_left > size) {
            cross->time_left--;
        }
        cross++;
    }
}
