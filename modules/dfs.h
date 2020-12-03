#ifndef GRAPHMATRIX_DFS_H
#define GRAPHMATRIX_DFS_H

#endif //GRAPHMATRIX_DFS_H

#ifndef GRAPHMATRIX_LISTSGRAPH_H
#include "listsGraph.h"
#endif

#ifndef GRAPHMATRIX_TOOLS_H
#include "tools.h"
#endif

void dfs_log(int* component);

void components_log(int** components);

void dists_log(int** dists,int* vertexes, int graph_size);

void hardStack_matrix_dist(mtrx_grph_t* graph, int v_index, numbers_t* dist);

void hardStack_lists_dist(list_graph_t* graph,int v_index, int* dist, int** component, bool* visited);

void dfs_matrix(mtrx_grph_t* graph, int v_index, numbers_t* dist);

void dfs_lists(list_graph_t* graph, int v_index, int* dist, int** component, bool* visited);

void hard_stack_matrix(mtrx_grph_t* graph, bool* visited, int v_index);

void virtual_stack_matrix(mtrx_grph_t* graph, bool* visited, int v_index);

void hardStack_lists(list_graph_t* graph, bool* visited, int v_index);

void components_dfs_Matrix(mtrx_grph_t* graph, void DFS(mtrx_grph_t*, bool* visited,int));

void components_dfs_Lists(list_graph_t* graph);

int*** components_and_dist_dfs_Lists(list_graph_t* graph);