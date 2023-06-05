#include "cross.component.h"

void initialize_crosses(Crosses *crosses) {
    crosses->cross = (Cross *) malloc(CROSS_QUANTITY * sizeof(Cross));
    crosses->total_time_left = 0;
    crosses->average_time = (float) 0.0;
    for (int i = 0; i < CROSS_QUANTITY; i++) {
        Cross *cross = &((*crosses).cross[i]);
        new_stack(&cross->stack);
        cross->time_left = 0;
    }
}

Cross *manager_crosses(Crosses *crosses, int (*operation)(Cross **, int)) {
    Cross *cross = crosses->cross;
    crosses->total_time_left = operation(&cross, crosses->total_time_left);
    return cross;
}

int select_cross(Cross **crosses, int basic_time) {
    Cross *last_cross = *crosses + CROSS_QUANTITY - 1;
    while (*crosses != last_cross && ((*crosses)->stack.size == FOR_CROSS || (*crosses)->time_left != 0)) {
        (*crosses)++;
    }

    return basic_time;
}

int cross_handler(Cross **crosses, int basic_time) {
    for (int i = 0; i < CROSS_QUANTITY; ++i) {
        if ((*crosses)[i].time_left > EMPTY) {
            for (int j = 0; j < ((*crosses)[i].time_left + 1); j++) pop(&(*crosses)[i].stack);
            (*crosses)[i].time_left--;
            basic_time--;
        }
    }

    return basic_time;
}


void show_crosses(Crosses *crosses) {
    printf("\n------------------------------------------------\n"
           "Travessas: Possui tempo total de espera %d e average_time de espera %.1f",
           crosses->total_time_left,
           crosses->average_time
    );
    for (int i = 0; i < CROSS_QUANTITY; ++i) {
        printf("\nTravessa %d: Possui tamanho %d e tempo de espera %d",
               i + 1,
               crosses->cross[i].stack.size,
               crosses->cross[i].time_left
        );
    }
    printf("\n------------------------------------------------\n");
}

void to_cross(Dock *dock, Crosses *crosses, Node_Container *node) {
    STACK_SIZE max = FOR_CROSS;
    Cross *cross = manager_crosses(crosses, select_cross);
    push(&cross->stack, node->container, max);
    if (cross->stack.size == max) {
        to_transport(dock, &cross);
        crosses->total_time_left += DRAIN_OUT_TIME;
    }
}
