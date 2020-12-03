#include "limitedQueue.h"

lim_queue* lim_queue_create(size_t limit){
    lim_queue* queue = malloc(sizeof(lim_queue));

    queue->data = malloc(sizeof(int)*limit);
    queue->limit = limit;
    queue->length = 0;
    queue->first = 0;
    queue->last = -1;

    return queue;
}

int lim_queue_push(lim_queue* queue,int value){
    queue->length ++;

    if (queue->length <= queue->limit){
        queue->last++;
        queue->data[queue->last]=value;
        return 1;
    }
    else{
        return 0;
    }
}

int lim_queue_pop(lim_queue* queue){
    queue->length --;

    if (queue->length >= 0){
        queue->first++;
        return queue->data[queue->first-1];
    }
    else{
        return NULL;
    }
}
