#include "coloring.h"

#define ret return

void reset_visited(bool* visited, int** indp_sets){
    _FOR_(i,buf_len(indp_sets)){
        _FOR_(j,buf_len(indp_sets[i])){
            visited[indp_sets[i][j]]=1;
        }
    }
}

int** indp_sets(mtrx_grph_t* graph){
    int** sets = NULL;
    bool* visited = (bool*)calloc(graph->size,1);

    int v_index = 0;

    int count = 0;
    while (v_index!=-1){
        buf_push(sets,NULL);
        while (v_index!=-1){
            visited[v_index]=1;
            buf_push(sets[count],v_index);

            _FOR_(i,graph->size){
                if (graph->matrix[v_index][i] and !visited[i]){
                    visited[i]=1;
                }
            }

            v_index = fst_false(visited,graph->size);
        }
        memset(visited,0,graph->size);
        reset_visited(visited,sets);
        count++;

        v_index = fst_false(visited,graph->size);
    }

    //log

    return sets;
}

int color_graph(mtrx_grph_t* graph,int** colors){
    int K = buf_len(colors);

    _FOR_(i,buf_len(colors)){
        _FOR_(j,buf_len(colors[i])){
            graph->vertexes[colors[i][j]].color = (char)i;
        }
    }

    ret K;
}

void log_indp_sets(FILE* stream, int** sets){
    _FOR_(i,buf_len(sets)){
        _FOR_(j,buf_len(sets[i])){
            fprintf(stream,"%d,",sets[i][j]);
        }
        fprintf(stream,"\n");
    }
}

void log_indp_sets_to_json(FILE* stream, int** sets){
    _FOR_(i,buf_len(sets)){
        _FOR_(j,buf_len(sets[i])){
            fprintf(stream,"%d,",sets[i][j]);
        }
        fprintf(stream,"\\n");
    }
}

void free_indp_sets(int** sets){
    _FOR_(i,buf_len(sets)){
        buf_free(sets[i]);
    }
    buf_free(sets);
}