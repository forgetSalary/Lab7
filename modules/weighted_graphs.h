#ifndef GRAPHMATRIX_WEIGHTED_GRAPHS_H
#define GRAPHMATRIX_WEIGHTED_GRAPHS_H

#endif //GRAPHMATRIX_WEIGHTED_GRAPHS_H

#ifndef GRAPHMATRIX_BFS_H
#include "bfs.h"
#endif

#ifndef GRAPHMATRIX_TOOLS_H
#include "tools.h"
#endif

int ecntr(mtrx_grph_t* graph, int v_index);

int diam(mtrx_grph_t* graph);

int rad(mtrx_grph_t* graph);

int* vertexes_with_ecntr(mtrx_grph_t* graph, int ecntr_to_find);

int* vertexes_with_degree(mtrx_grph_t* graph, int degree);

int ecntr_incd(incd_matrix_grph_t* graph, int v_index);

int diam_incd(incd_matrix_grph_t* graph);

int rad_incd(incd_matrix_grph_t* graph);

int* vertexes_with_ecntr_incd(incd_matrix_grph_t* graph, int ecntr_to_find);

int* vertexes_with_degree_incd(incd_matrix_grph_t* graph, int degree);