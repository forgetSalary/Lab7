#ifndef GRAPHMATRIX_MTRXGRPH_H
#define GRAPHMATRIX_MTRXGRPH_H

#endif //GRAPHMATRIX_MTRXGRPH_H

#include <stdio.h>
#include <string.h>

#ifndef GRAPHMATRIX_VERTEX_H
#include "vertex.h"
#endif

#include "matrix.h"

typedef struct matrix_graph_s{
    int**   matrix;
    vertex* vertexes;
    int     size;
}mtrx_grph_t;

mtrx_grph_t* matrixGraph_create(int size);

void remove_vrtx_memmove(mtrx_grph_t* graph, int vrtxindex);

void remove_vrtx_sectors(mtrx_grph_t* graph, int vrtxindex);

void add_vrtx(mtrx_grph_t* graph,int new_vrtx);

void print_graph(mtrx_grph_t* graph);

void row_vertexes(vertex* vertexes,int size,int begin);

void print_graph_to_browser(mtrx_grph_t* graph);

void matrixGraph_free(mtrx_grph_t* graph);

int get_index(char value_is_ptr,void* array, int size, void* value, size_t value_size);

