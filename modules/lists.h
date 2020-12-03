#ifndef GRAPHMATRIX_LISTS_H
#define GRAPHMATRIX_LISTS_H

#endif //GRAPHMATRIX_LISTS_H

#include <stdio.h>
#include <string.h>

#ifndef GRAPHMATRIX_TOOLS_H
#include "extern/tools.h"
#endif

#ifndef GRAPHMATRIX_VERTEX_H
#include "vertex.h"
#endif

#ifndef GRAPHMATRIX_CONSOLECOLORS_H
#include "extern/consoleColors.h"
#endif

typedef struct node{
    void* value;

    struct node* last;
    struct node* next;
}node_t;

typedef struct list{
    node_t* head;
    node_t* tail;

    int depth;

}list_t;

node_t* push(node_t* tail, void* value);

void* list_pop(list_t* list);

list_t* list_create();

void append(list_t* list, void* value);

void print_list(list_t* list,const char* format);

void list_free(list_t* list);

int que_isempty(list_t* queue);

void que_insert(list_t* queue, void* value);

void* que_remove(list_t* queue);