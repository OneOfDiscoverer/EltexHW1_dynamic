#include "list.h"

void pushObj(list **ptr){
    *ptr = calloc(1,sizeof(list));
}

void popObj(list **ptr){
    free(*ptr);
}
