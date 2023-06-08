#include "list.h"

void new_list(List *list) {
    list->first = list->last = NULL;
    list->size = 0;
}


void to_list(List *list, Cross *cross, int max) {
    if (list->size == max) return;
    Node_Cross *new_node = (Node_Cross *) malloc(sizeof(Node_Cross));
    new_node->cross = cross;
    new_node->next = NULL;
    if (!empty(2, (void *) list->first, list->last)) {
        list->last->next = new_node;
        list->last = list->last->next;
    } else {
        list->first = new_node;
        list->last = new_node;
    }
    list->size++;
}