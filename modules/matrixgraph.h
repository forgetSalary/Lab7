#ifndef GRAPHMATRIX_MTRXGRPH_H
#define GRAPHMATRIX_MTRXGRPH_H

#endif //GRAPHMATRIX_MTRXGRPH_H

#include <stdio.h>
#include <string.h>
#include <windows.h>

#ifndef GRAPHMATRIX_VERTEX_H
#include "vertex.h"
#endif

#ifndef GRAPHMATRIX_CGI_H
#include "extern/cgi.h"
#endif

#include "matrix.h"

typedef struct matrix_graph_s{
    int**   matrix;
    vertex* vertexes;
    int     size;
}mtrx_grph_t;

typedef struct incd_matrix_grph{
    int**   matrix;
    int*    vertexes_names;
    int*    weights;
    int     edges_count;
    int     vertexes_count;
}incd_matrix_grph_t;

mtrx_grph_t* matrixGraph_create(int size);

mtrx_grph_t* init_graph_from_str(char* str);

mtrx_grph_t* init_graph_from_cgi_client();

incd_matrix_grph_t* incd_matrixGraph_create(int vertex_count,int edges_count);

int edge_count(mtrx_grph_t* grpah, int kind);

incd_matrix_grph_t* adj_to_incd(mtrx_grph_t* adj_graph,int kind);

void remove_vertex(mtrx_grph_t* graph, int vrtxindex);

void remove_vrtx_sectors(mtrx_grph_t* graph, int vrtxindex);

void add_vrtx(mtrx_grph_t* graph,int new_vrtx);

void print_graph(mtrx_grph_t* graph);

void print_incd_matrixGraph(incd_matrix_grph_t* graph);

void row_vertexes(vertex* vertexes,int size,int begin);

void print_graph_to_browser(mtrx_grph_t* graph);

void matrixGraph_free(mtrx_grph_t* graph);

