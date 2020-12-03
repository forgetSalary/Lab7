#ifndef GRAPHMATRIX_LISTSGRAPH_H
#define GRAPHMATRIX_LISTSGRAPH_H

#endif //GRAPHMATRIX_LISTSGRAPH_H

#ifndef GRAPHMATRIX_LISTS_H
#include "lists.h"
#endif

#ifndef GRAPHMATRIX_MATRIX_H
#include "matrixgraph.h"
#endif


#define list(graph,index)               graph->lists[index]
#define vertex_name_head(graph,index)   (_VALUE_OF(vertex,list_graph->lists[0]->head)).name

typedef struct list_graph{
    list_t** lists;
    vertex* vertexes;

    int size;
}list_graph_t;

list_graph_t* list_graph_create(int size);

list_graph_t* matrix_to_list(mtrx_grph_t* matrix_graph);

void print_list_graph(list_graph_t* graph);

void list_graph_free(list_graph_t* graph);