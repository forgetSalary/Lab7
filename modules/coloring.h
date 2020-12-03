#ifndef GRAPHMATRIX_COLORING_H
#define GRAPHMATRIX_COLORING_H

#endif //GRAPHMATRIX_COLORING_H

#ifndef GRAPHMATRIX_LISTSGRAPH_H
#include "listsGraph.h"
#endif

#ifndef GRAPHMATRIX_DFS_H
#include "dfs.h"
#endif

#ifndef GRAPHMATRIX_BFS_H
#include "bfs.h"
#endif


int** indp_sets(mtrx_grph_t* graph);

int color_graph(mtrx_grph_t* graph,int** colors);

void log_indp_sets(FILE* stream, int** sets);

void log_indp_sets_to_json(FILE* stream, int** sets);

void free_indp_sets(int** sets);