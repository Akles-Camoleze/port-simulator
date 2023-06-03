#include "cross.component.h"

void initialize_crosses(Crosses *crosses) {
    *crosses = (Cross *) malloc(CROSS_QUANTITY * sizeof(Cross));
}