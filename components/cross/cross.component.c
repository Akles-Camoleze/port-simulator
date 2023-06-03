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

Cross *get_cross(Crosses *crosses) {
    STACK_SIZE max = FOR_CROSS;
    Cross *cross = *crosses;
    Cross *last_cross = cross + CROSS_QUANTITY - 1;
    while (cross != last_cross && cross->stack->size == max) {
        cross->time_left = 2;
        cross++;
    }

    return cross;
}