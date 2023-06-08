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

/**
 * Cria lista, alocando na memória
 * @param list: ponteiro da lista a ser alocada
 */
void new_list(List *list);

/**
 * Adiciona travessa na lista
 * @param list: ponteiro da lista a receber a travessa
 * @param cross: ponteiro da travessa a ser adicionada
 * @param tam: tamanho maximo da lista
 */
void to_list(List *list, Cross *cross, int max);

#endif //PORT_SIMULATOR_LIST_H
