#ifndef GRAPHMATRIX_TESTS_H
#define GRAPHMATRIX_TESTS_H

#endif //GRAPHMATRIX_TESTS_H

#include "modules/bfs.h"
#include "modules/dfs.h"
#include "modules/coloring.h"
#include "stdio.h"
#include "time.h"

#define PATH "D:\\CPrctc\\C Graphs\\"

void init_matrix(mtrx_grph_t* graph, int MAX, float chance, char** args);

void test_dfs_matrix(int SIZE, int vrtx);

void test_dfs_lists(int SIZE,int vrtx_index);

void test_bfs_matrix(int SIZE,int vrtx);

void test_bfs_lists(int SIZE,int vrtx);

void test_bfsd_matrix(int SIZE,int MAX,int argc, char** argv);

void test_numbers();

void test_vertex();

void test_stretchy_buffers();

void test_indp_sets(int SIZE,char** argv);

void test_components(int SIZE);

void test_kursach(int argc, char** argv);