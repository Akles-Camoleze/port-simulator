#ifndef PORT_SIMULATOR_CROSS_COMPONENT_H
#define PORT_SIMULATOR_CROSS_COMPONENT_H
#define CROSS_QUANTITY 5
#define DRAIN_OUT_TIME 2

#include <stdbool.h>
#include "../../structs/stack/stack.h"
#include "../docks/docks.component.h"
#include "../../structs/list/list.h"

typedef struct Dock Dock;
typedef struct Node_Container Node_Container;
typedef struct Node_Cross Node_Cross;
typedef struct Stack Stack;
typedef struct List List;

typedef struct Cross {
    int id;
    int time_left;
    bool spare;
    Stack *stack;
} Cross;

typedef struct Crosses {
    List *list;
    int total_time_left;
    float average_time;
} Crosses;

/**
 * Incicializa todas as travessas
 * @param crosses: Ponteiro para as travessas
 */
void initialize_crosses(Crosses *crosses);

/**
 * Gerencia as travessas de acordo com operation definido
 * @param crosses: Ponteiro para as travessas
 * @param operation: Ponteiro para operação que deve ser realizada
 * @return ponteiro para travessa obtida em operation
 */
Cross *manager_crosses(Crosses *crosses, int (*operation)(Node_Cross **, int));

/**
 * Seleciona primeira travessa em crosses disponivel, caso existente
 * @param crosses: Ponteiro para o primeiro nó da pilha
 * @param basic_size: tempo total de espera das travessas
 * @return Novo tempo total de espera
 */
int select_cross(Node_Cross **crosses, int basic_time);

/**
 * Seleciona primeria travessa em crosses disponivel, caso existente
 * @param crosses: Ponteiro para o primeiro nó da pilha
 * @param basic_size: tempo total de espera das travessas
 * @return Novo tempo total de espera
 */
int cross_handler(Node_Cross **first, int basic_time);

/**
 * Exibi as travessas
 * @param crosses: Travessas a serem exibidas
 */
void show_crosses(Crosses *crosses);

/**
 * Recupera nova travessa para doca caso necessário e possível
 * @param dock: ponteiro para doca a se recuperar a travessa
 * @param crosses: travessas a serem realizado a busca
 * @return ponteiro para travessa caso exista alguma disponível,
 * null caso não exista nenhuma
 */
Cross *get_dock_cross(Dock *dock, Crosses *crosses);

/**
 * Recupera média das travessas
 * @param: Travessas a serem recuperadas a média
 */
void get_crosses_average(Crosses *crosses);

#endif //PORT_SIMULATOR_CROSS_COMPONENT_H
