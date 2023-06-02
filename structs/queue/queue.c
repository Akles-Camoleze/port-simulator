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
}

Node_Ship *unqueue(Queue *queue) {
    if (empty(1, (void *) queue->rear, (void *) queue->rear)) return NULL;
    Node_Ship *rm_ship = queue->front;
    queue->front = queue->front->next;
    rm_ship->next = NULL;
    return rm_ship;
}

void print_queue(Queue *queue) {
    Node_Ship *aux = queue->front;
    char *printer = NULL;
    while (!empty(1, aux)) {
        printf("\n\t\"%03d\" {\n\t\t\"carga\": %02d,\n\t\t\"espera\": 15\n\t},", aux->ship->id, aux->ship->load);
        aux = aux->next;
    }
}
