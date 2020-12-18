#include "coloring.h"

#define ret return

static void mark_all_visited(bool* visited, int** indp_sets){
    FOR(i,buf_len(indp_sets)){
        FOR(j,buf_len(indp_sets[i])){
            visited[indp_sets[i][j]]=1;
        }
    }
}

int** indp_sets(mtrx_grph_t* graph){
    int** sets = NULL;//массив незавсимых множеств (далее НМ) вершин
    bool* visited = (bool*)calloc(graph->size,1);//см. по телу цикла
    int v_index = 0;//следующий эллемент НМ
    int count = 0;

    while (v_index!=-1){
        buf_push(sets,NULL);//создаем новое НМ
        while (v_index!=-1){
            visited[v_index]=1; //здесь visited хранит все вершины всех НМ,
            // и все смежные врешины, каждой вершины текущего НМ
            buf_push(sets[count],v_index);// пополняем текущее НМ

            FOR(i,graph->size){//отсеиваем неподходящие вершины для текущего НМ
                if ((graph->matrix[v_index][i] or graph->matrix[i][v_index]) and !visited[i]){
                    visited[i]=1;
                }
            }
            v_index = fst_false(visited,graph->size);// находим подходящую вершину для текущего НМ, если есть
        }//если такой вершины не нашлось, то еще одно НМ найдено

        memset(visited,0,graph->size);  //
        mark_all_visited(visited,sets);     //здесь visited хранит только лишь все вершины всех НМ

        v_index = fst_false(visited,graph->size);// находим первую вершину следующего НМ, если есть
        count++;
    }                                           // если нет, то все независимые множества найдены
    free(visited);

    ret sets;
}

int** indp_sets_removing(mtrx_grph_t* graph){
    int** sets = NULL;//массив незавсимых множеств (далее НМ) вершин
    bool* visited = (bool*)calloc(graph->size,1);//см. по телу цикла
    int v_index = 0;//следующий эллемент НМ
    int count = 0;
    size_t* indexes = new_block(size_t,graph->size);

    while (graph->size>0){
        buf_push(sets,NULL);//создаем новое НМ
        while (v_index!=-1){
            visited[v_index]=1; //здесь visited хранит все вершины всех НМ,
            // и все смежные врешины, каждой вершины текущего НМ
            buf_push(sets[count],graph->vertexes[v_index].name);// пополняем текущее НМ

            FOR(i,graph->size){//отсеиваем неподходящие вершины для текущего НМ
                if (graph->matrix[v_index][i] and !visited[i]){
                    visited[i]=1;

                }
            }
            v_index = fst_false(visited,graph->size);// находим подходящую вершину для текущего НМ, если есть
        }//если такой вершины не нашлось, то еще одно НМ найдено

        memset(visited,0,graph->size);  //
        for (int i = 0; i < buf_len(sets[count]); i++) {
            remove_vertex(graph,get_vertex_index(graph->vertexes,sets[count][i],graph->size));
        }

        v_index = 0;// находим первую вершину следующего НМ, если есть
        count++;
    }                                           // если нет, то все независимые множества найдены
    free(visited);

    ret sets;
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

void free_indp_sets(int** sets){
    _FOR_(i,buf_len(sets)){
        buf_free(sets[i]);
    }
    buf_free(sets);
}