#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs/stack/stack.h"
#include "structs/queue/queue.h"
#include "utils/utils.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
int main() {
    srand(time(NULL));
    Queue queue;
    new_queue(&queue);

    Ship *new_container1 = (Ship *) malloc(sizeof(Container));
    new_container1->id = gen_number(1, 999);
    new_container1->load = gen_number(4, 16);
    to_queue(&queue, new_container1);

    Ship *new_container2 = (Ship *) malloc(sizeof(Container));
    new_container2->id = gen_number(1, 999);
    new_container2->load = gen_number(4, 16);
    to_queue(&queue, new_container2);

    Ship *new_container3 = (Ship *) malloc(sizeof(Container));
    new_container3->id = gen_number(1, 999);
    new_container3->load = gen_number(4, 16);
    to_queue(&queue, new_container3);

    Ship *new_container4 = (Ship *) malloc(sizeof(Container));
    new_container4->id = gen_number(1, 999);
    new_container4->load = gen_number(4, 16);
    to_queue(&queue, new_container4);
    print_queue(&queue);
    return 0;
}
#pragma clang diagnostic pop
