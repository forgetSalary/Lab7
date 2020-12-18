#ifndef GRAPHMATRIX_TESTS_H
#define GRAPHMATRIX_TESTS_H

#endif //GRAPHMATRIX_TESTS_H

#include "modules/bfs.h"
#include "modules/dfs.h"
#include "modules/coloring.h"
#include "stdio.h"
#include "time.h"
#include "modules/weighted_graphs.h"

#define PATH "D:\\CPrctc\\C Graphs\\"

int init_matrix(mtrx_grph_t* graph, int MAX, float chance, int kind);

void test_matrix(int SIZE, float density,int kind);

void test_dfs_matrix(int SIZE, int vrtx);

void test_dfs_lists(int SIZE,int vrtx_index);

void test_bfs_matrix(int SIZE,int vrtx);

void test_bfs_lists(int SIZE,int vrtx);

void test_bfsd_matrix(int SIZE,int MAX,int kind_of_graph);

void test_numbers();

void test_vertex();

void test_stretchy_buffers_pushing();

void test_stretchy_buffers_const_sized();

void test_incd_matrix_graph(int adj_mtrx_order, float density, int kind_of_graph);

void lab8(int adj_mtrx_order, float density, int kind_of_graph);

void test_indp_sets(int SIZE,char** argv);

void test_components(int SIZE);

void test_cgi();

void test_kursach();