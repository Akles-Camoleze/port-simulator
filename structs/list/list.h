#ifndef PORT_SIMULATOR_LIST_H
#define PORT_SIMULATOR_LIST_H

#include "../node/node.h"

typedef struct Node_Cross Node_Cross;

typedef struct Cross Cross;

typedef struct List {
    Node_Cross *first;
    Node_Cross *last;
    int size;
} List;

void new_list(List *list);

void to_list(List *list, Cross *cross, int max);

#endif //PORT_SIMULATOR_LIST_H
