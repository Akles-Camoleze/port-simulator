#include "container.component.h"

Container  *new_container() {
    return (Container *) malloc(sizeof(Container));
}