#include "weighted_graphs.h"

int ecntr(mtrx_grph_t* graph, int v_index){
    int* dists = new_block(int,graph->size);
    bfsd_matrix(graph,v_index,dists);
    int e = max_int(dists,graph->size);
    del(dists);
    return e;
}

int diam(mtrx_grph_t* graph){
    int* ecntrs = new_block(int,graph->size);
    FOR(i,graph->size){
        ecntrs[i] = ecntr(graph, i);
    }
    int d = max_int(ecntrs,graph->size);
    del(ecntrs);
    return d;
}

int rad(mtrx_grph_t* graph){
    int* ecntrs = new_block(int,graph->size);
    FOR(i,graph->size){
        ecntrs[i] = ecntr(graph, i);
    }
    int r = min_int(ecntrs,graph->size);
    del(ecntrs);
    return r;
}

int* vertexes_with_ecntr(mtrx_grph_t* graph, int ecntr_to_find){
    int* vertexes = NULL;
    int ecntr_exact;
    for (int i = 0; i < graph->size; i++) {
        ecntr_exact = ecntr(graph, i);
        if (ecntr_exact == ecntr_to_find){
            buf_push(vertexes,i);
        }
    }
    return vertexes;
}

int* vertexes_with_degree(mtrx_grph_t* graph, int degree){
    int* vertexes = NULL;
    int count;
    for (int i = 0; i < graph->size; i++) {
        count=0;
        for (int j = 0; j < graph->size; j++) {
            if (graph->matrix[i][j]!=0){count++;}
        }
        if (count == degree){
            buf_push(vertexes,i);
        }
    }
    return vertexes;
}

int ecntr_incd(incd_matrix_grph_t* graph, int v_index){
    int* dists = new_block(int,graph->vertexes_count);
    bfsd_incd_matrix(graph,v_index,dists);
    int e = max_int(dists,graph->vertexes_count);
    del(dists);
    return e;
}

int diam_incd(incd_matrix_grph_t* graph){
    int* ecntrs = new_block(int,graph->vertexes_count);
    FOR(i,graph->vertexes_count){
        ecntrs[i] = ecntr_incd(graph, i);
    }
    int d = max_int(ecntrs,graph->vertexes_count);
    del(ecntrs);
    return d;
}

int rad_incd(incd_matrix_grph_t* graph){
    int* ecntrs = new_block(int,graph->vertexes_count);
    FOR(i,graph->vertexes_count){
        ecntrs[i] = ecntr_incd(graph, i);
    }
    int r = min_int(ecntrs,graph->vertexes_count);
    del(ecntrs);
    return r;
}

int* vertexes_with_ecntr_incd(incd_matrix_grph_t* graph, int ecntr_to_find){
    int* vertexes = NULL;
    int ecntr_exact;
    for (int i = 0; i < graph->vertexes_count; i++) {
        ecntr_exact = ecntr_incd(graph, i);
        if (ecntr_exact == ecntr_to_find){
            buf_push(vertexes,i);
        }
    }
    return vertexes;
}

int* vertexes_with_degree_incd(incd_matrix_grph_t* graph, int degree){
    int* vertexes = NULL;
    int count;
    for (int i = 0; i < graph->vertexes_count; i++) {
        count=0;
        for (int j = 0; j < graph->edges_count; j++) {
            if (graph->matrix[i][j]!=0){count++;}
        }
        if (count == degree){
            buf_push(vertexes,i);
        }
    }
    return vertexes;
}