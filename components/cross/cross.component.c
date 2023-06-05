#include "cross.component.h"

void initialize_crosses(Crosses *crosses) {
    crosses->list = (List *) malloc(sizeof(List));
    new_list(crosses->list);
    crosses->total_time_left = 0;
    crosses->average_time = (float) 0.0;
    for (int i = 0; i < CROSS_QUANTITY; i++) {
        Cross *cross = (Cross *) malloc(sizeof(Cross));
        cross->stack = (Stack *) malloc(sizeof(Stack));
        new_stack(cross->stack);
        cross->time_left = 0;
        cross->spare = i != (CROSS_QUANTITY - 1) ? false : true;
        to_list(crosses->list, cross, CROSS_QUANTITY);
    }
}

Cross *manager_crosses(Crosses *crosses, int (*operation)(Node_Cross **, int)) {
    Node_Cross *node = crosses->list->first;
    crosses->total_time_left = operation(&node, crosses->total_time_left);
    if (node != NULL) {
        node->cross->spare = false;
        return node->cross;
    }
    return NULL;
}

int select_cross(Node_Cross **first, int basic_time) {
    while ((*first) != NULL && !(*first)->cross->spare) {
        (*first) = (*first)->next;
    }
    return basic_time;
}

int cross_handler(Node_Cross **first, int basic_time) {
    while ((*first)->next != NULL) {
        if ((*first)->cross->time_left != EMPTY) {
            for (int i = 0; i < (*first)->cross->time_left + 1; ++i) {
                pop((*first)->cross->stack);
            }
            if (--(*first)->cross->time_left == EMPTY) {
                (*first)->cross->spare = true;
            }
            basic_time--;
        }
        (*first) = (*first)->next;
    }
    return basic_time;
}


void show_crosses(Crosses *crosses) {
    int i = 1;
    Node_Cross *node = crosses->list->first;
    printf("\n------------------------------------------------\n"
           "Travessas: Possui tempo total de espera %d e average_time de espera %.1f",
           crosses->total_time_left,
           crosses->average_time
    );
    while (node != NULL) {
        printf("\nTravessa %d: Possui tamanho %d e tempo de espera %d",
               i,
               node->cross->stack->size,
               node->cross->time_left
        );
        i++;
        node = node->next;
    }
    printf("\n------------------------------------------------\n");
}

Cross *to_cross(Dock *dock, Crosses *crosses, Node_Container *node) {
    STACK_SIZE max = FOR_CROSS;
    Cross *cross = dock->current_cross;
    if (cross->stack->size == max || cross->time_left != 0) {
        dock->current_cross = manager_crosses(crosses, select_cross);
        cross = dock->current_cross;
    }
    if (!empty(1, cross)) {
        push(cross->stack, node->container, max);
        if (cross->stack->size == max) {
            to_transport(dock, &cross);
            crosses->total_time_left += DRAIN_OUT_TIME;
        }
    }
    return cross;
}
