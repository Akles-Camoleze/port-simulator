#ifndef PORT_SIMULATOR_DOCKS_COMPONENT_H
#define PORT_SIMULATOR_DOCKS_COMPONENT_H
#define DOCKS_QUANTITY 4
#define DOCK_MAX_SIZE 20

#include "../../structs/queue/queue.h"
#include "../cross/cross.component.h"

typedef struct Cross Cross;
typedef struct Crosses Crosses;
typedef struct Queue Queue;
typedef struct List List;

typedef struct Dock {
    Queue *queue;
    Cross *current_cross;
    int car_uses;
    int total_load;
    float average_time;
} Dock;

typedef struct Dock Docks[DOCKS_QUANTITY];

/**
 * Inicializa as docas
 * @param docks: ponteiro para docas a serem inicializadas
 * @param list: ponteiro para lista de travessas
 */
void initialize_docks(Docks *docks, List *list);

/**
 * Recupera doca com menor tamanho de fila
 * @param docks: ponteiro para as docas
 * @return ponteiro para a doca de menor tamanho de fila
 */
Dock *get_smaller_dock(Docks *docks);

/**
 * Exibi as docas
 * @param: Docas a serem exibidas
 */
void show_mooring_areas(Docks *docks);

/**
 * Realiza o processo de descarregamento de navios e caregamento das travessas
 * @param docks: Docas a serem realizadas o processo
 * @param crosses: travessas para o carregamento
 */
void hoist(Docks *docks, Crosses *crosses);

/**
 * Realiza o deslocamento da travessa, movimentação do carrinho
 * @param dock: ponteiro para a doca a se realizar a operação
 * @param cross: ponteiro para travessa a ser deslocada
 */
void to_transport(Dock *dock, Cross **cross);

/**
 * Recupera a média do tempo de espera das docas
 * @param docks: docas a serem obtidas as médias
 * @param crosses_average: média de tempo de espera das travessas
 */
void get_docks_averages(Docks *docks, float crosses_average);

#endif //PORT_SIMULATOR_DOCKS_COMPONENT_H
