#ifndef GRAPHMATRIX_LIMITEDQUEUE_H
#define GRAPHMATRIX_LIMITEDQUEUE_H

#endif //GRAPHMATRIX_LIMITEDQUEUE_H

#include "malloc.h"
#include "string.h"

typedef struct limited_queue_s {
    int* data;
    size_t first;
    size_t last;
    size_t value_size;
    size_t length;
    size_t limit;

}lim_queue;

#define lim_queue_free(q) free(q->data), free(q)

lim_queue* lim_queue_create(size_t limit);

int lim_queue_push(lim_queue* queue,int value);

int lim_queue_pop(lim_queue* queue);