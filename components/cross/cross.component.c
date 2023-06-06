#include "cross.component.h"

void initialize_crosses(Crosses *crosses) {
    crosses->list = (List *) malloc(sizeof(List));
    new_list(crosses->list);
    crosses->total_time_left = 0;
    crosses->average_time = (float) 0.0;
    for (int i = 0; i < CROSS_QUANTITY; i++) {
        Cross *cross = (Cross *) malloc(sizeof(Cross));
        cross->id = i + 1;
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
        return node->cross;
    }
    return NULL;
}

int select_cross(Node_Cross **first, int basic_time) {
    while ((*first) != NULL && !(*first)->cross->spare) {
        (*first) = (*first)->next;
    }
    if ((*first) != NULL && (*first)->cross->spare == true) {
        (*first)->cross->spare = false;
    }
    return basic_time;
}

int cross_handler(Node_Cross **first, int basic_time) {
    while ((*first) != NULL) {
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
    Node_Cross *node = crosses->list->first;
    printf("\n=================================================================="
           "\nTravessas: Espera: %d | Media: %.1f"
           "\n------------------------------------------------------------------",
           crosses->total_time_left,
           crosses->average_time
    );
    while (node != NULL) {
        printf("\n%d: Carga: %d | Espera: %d | Disponivel: %s",
               node->cross->id,
               node->cross->stack->size,
               node->cross->time_left,
               node->cross->spare ? "Sim" : "Nao"
        );
        node = node->next;
    }
    printf("\n==================================================================\n");
}

Cross *get_dock_cross(Dock *dock, Crosses *crosses) {
    if ((!empty(1, dock->current_cross) && dock->current_cross->time_left != 0) || empty(1, dock->current_cross)) {
        dock->current_cross = manager_crosses(crosses, select_cross);
    }
    return dock->current_cross;
}
