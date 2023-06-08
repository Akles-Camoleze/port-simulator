#ifndef PORT_SIMULATOR_SHIP_COMPONENT_H
#define PORT_SIMULATOR_SHIP_COMPONENT_H
#define STACKS_SHIP_QUANTITY 4

#include "../../structs/stack/stack.h"

typedef struct Stack Stack;
typedef struct Dock Dock;

typedef struct Ship {
    int id;
    int load;
    float time_stay;
    Stack *stacks;
} Ship;

/**
 * Cria novo navio, alocado na memória
 * @return ponteiro para o navio criado
 */
Ship *new_ship();

/**
 * Recebe os containes nas pilhas do navio uniformemente
 * @param ship: ponteiro para o navio a ser recebido os containers
 */
void get_containers(Ship *ship);

/**
 * Seleciona pilha não vazia do navio para descarregar
 * @param ship: ponteiro para o navio a ser descarregado
 * @return ponteiro para a pilha
 */
Stack *select_ship_stack(Ship *ship);

/**
 * Diminui em uma unidade a carga do navio
 * @param ship: navio a ter a carga decrementada
 */
void decrease_load(Ship *ship);

/**
 * Compara a carga do navio com load
 * @param ship: ponteiro para o navio a ter a carga comparada
 * @param load: valor a se comparar a carga do navio
 * @return resultado da comparação
 */
bool check_load(Ship *ship, int load);

/**
 * Define o tempo de espera do navio
 * @param ship: ponteiro para o navio a ter o tempo de espera definido
 * @param dock: ponteiro para a doca que o navio pertence
 * @param crosses_average: média de espera das travessas
 */
void set_time_stay(Ship *ship, Dock *dock, float crosses_average);

#endif //PORT_SIMULATOR_SHIP_COMPONENT_H
