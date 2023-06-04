#include "cross.component.h"

void initialize_crosses(Crosses *crosses) {
    *crosses = (Crosses) malloc(CROSS_QUANTITY * sizeof(Cross));
    for (int i = 0; i < CROSS_QUANTITY; i++) {
        Cross *cross = &((*crosses)[i]);
        new_stack(&cross->stack);
        cross->time_left = 0;
    }
}

Cross *cross_handler(Crosses *crosses, void (*operation)(Crosses *, Cross *, int)) {
    STACK_SIZE size = FOR_CROSS;
    Cross *cross = *crosses;
    Cross *last_cross = cross + CROSS_QUANTITY - 1;
    if (operation == decrease) size = EMPTY;
    operation(&cross, last_cross, size);
    return cross;
}

void increase(Crosses *crosses, Cross *last_cross, int size) {
    for (Crosses *cross = crosses; *cross <= last_cross; (*cross)++) {
        if ((*cross)->stack.size != size && (*cross)->time_left == 0) {
            break;
        }
        if (*cross == last_cross) break;
    }
}

void decrease(Crosses *crosses, Cross *last_cross, int size) {
    for (Crosses *cross = crosses; *cross <= last_cross; (*cross)++) {
        if ((*cross)->time_left > size) {
            for (int j = 0; j < ((*cross)->time_left + 1); j++) pop(&(*cross)->stack);
            (*cross)->time_left--;
        }
        if (*cross == last_cross) break;
    }
}
