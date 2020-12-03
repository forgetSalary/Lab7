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

void dist_log(vertex* vertexes, int src_vertex, numbers_t* dist);

void bfsd_matrix(mtrx_grph_t* graph,int vertex_index,numbers_t* dist);