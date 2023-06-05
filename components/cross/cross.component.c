#include "cross.component.h"

void initialize_crosses(Crosses *crosses) {
    *crosses = (Crosses) malloc(CROSS_QUANTITY * sizeof(Cross));
    for (int i = 0; i < CROSS_QUANTITY; i++) {
        Cross *cross = &((*crosses)[i]);
        new_stack(&cross->stack);
        cross->time_left = 0;
    }
}

Cross *manager_crosses(Crosses *crosses, void (*operation)(Crosses *)) {
    Cross *cross = *crosses;
    operation(&cross);
    return cross;
}

void select_cross(Crosses *crosses) {
    Cross *last_cross = *crosses + CROSS_QUANTITY - 1;
    while (*crosses != last_cross && ((*crosses)->stack.size == FOR_CROSS || (*crosses)->time_left != 0)) {
        (*crosses)++;
    }
}

void cross_handler(Crosses *crosses) {
    for (int i = 0; i < CROSS_QUANTITY; ++i) {
        if ((*crosses)[i].time_left > EMPTY) {
            for (int j = 0; j < ((*crosses)[i].time_left + 1); j++) pop(&(*crosses)[i].stack);
            (*crosses)[i].time_left--;
        }
    }
}


void show_crosses(Crosses *crosses) {
    for (int i = 0; i < CROSS_QUANTITY; ++i) {
        printf("Travessa %d: Possui tamanho %d e tempo de espera %d\n",
               i + 1,
               (*crosses)[i].stack.size,
               (*crosses)[i].time_left
        );
    }
}

void to_cross(Dock *dock, Crosses *crosses, Node_Container *node) {
    STACK_SIZE max = FOR_CROSS;
    Cross *cross = manager_crosses(crosses, select_cross);
    push(&cross->stack, node->container, max);
    to_transport(dock, &cross, cross->stack.size == max);
}
