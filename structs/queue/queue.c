#include "queue.h"

void new_queue(Queue *queue) {
    queue->rear = queue->front = NULL;
    queue->size = 0;
}

void to_queue(Queue *queue, Ship *ship) {
    Node_Ship *new_ship = (Node_Ship *) malloc(sizeof(Node_Ship));
    new_ship->ship = ship;
    new_ship->next = NULL;
    if (empty(1, (void *) queue->rear, (void *) queue->rear)) {
        queue->front = new_ship;
    } else {
        queue->rear->next = new_ship;
    }
    queue->rear = new_ship;
    queue->size++;
}

Node_Ship *unqueue(Queue *queue) {
    if (empty(1, (void *) queue->rear, (void *) queue->rear)) return NULL;
    Node_Ship *rm_ship = queue->front;
    queue->front = queue->front->next;
    rm_ship->next = NULL;
    queue->size--;
    return rm_ship;
}

void print_queue(Queue *queue) {
    Node_Ship *aux = queue->front;
    while (!empty(1, aux)) {
        Ship *ship = aux->ship;
        printf("\n╠═══════════════════════╬═════════════════════╬═══════════════════════╣"
               "\n║          %03d          ║         %03d         ║        %06.2f         ║",
               ship->id, ship->load,
               ship->time_stay
        );
        aux = aux->next;
    }
}

Node_Ship *get_first(Queue *queue) {
    return queue->front;
}
