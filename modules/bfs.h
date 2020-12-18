#ifndef GRAPHMATRIX_BFS_H
#define GRAPHMATRIX_BFS_H

#endif //GRAPHMATRIX_BFS_H

#ifndef GRAPHMATRIX_LISTSGRAPH_H
#include "listsGraph.h"
#endif

#ifndef GRAPHMATRIX_TOOLS_H
#include "tools.h"
#endif

void bfs_matrix(mtrx_grph_t* graph,int vertex_index,numbers_t* dist);

void bfs_lists(list_graph_t* graph,int vertex_index,numbers_t* dist);

void bfs_lists_lim(list_graph_t* graph,int vertex_index, int lim,numbers_t* dist);

void dist_log(mtrx_grph_t* graph, int src_vertex_index, int* dists);

void dist_log_incd(incd_matrix_grph_t* graph, int src_vertex_index, int* dists);

void bfsd_matrix(mtrx_grph_t* graph,int vertex_index,int* dists);

void bfsd_incd_matrix(incd_matrix_grph_t* graph,int vertex_index,int* dists);