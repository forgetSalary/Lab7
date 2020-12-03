#include "matrixgraph.h"

void print_graph(mtrx_grph_t* graph){
    //header
    printf("|v\t");

    for (int i=0; i<graph->size; i++){
        print_vertex("|%v\t",graph->vertexes[i]);
    }
    printf("|\n");

    for (int i=0; i<graph->size; i++){
        printf("|\t");
    }
    printf("|\t|\n");

    //modules
    for (int i=0; i<graph->size; i++){
        print_vertex("|%v\t",graph->vertexes[i]);
        for (int j=0; j<graph->size; j++){
            printf("|%d\t",graph->matrix[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

void print_graph_to_browser(mtrx_grph_t* graph){
    //header
    printf("<p>|v%-9c|",' ');

    for (int i=0; i<graph->size; i++){
        printf("%10d|",graph->vertexes[i]);
    }
    printf("</p>\n<p>|");

    for (int i=0; i<graph->size; i++){

        printf("%10c|",' ');
    }
    printf("%10c|</p>\n",' ');

    //graph
    for (int i=0; i<graph->size; i++){
        printf("<p>|%-10d",graph->vertexes[i]);
        for (int j=0; j<graph->size; j++){
            printf("|%10d",graph->matrix[i][j]);
        }
        printf("|</p>\n");
    }
    printf("\n");
}

void matrixGraph_free(mtrx_grph_t* graph){
    matrix_free(graph->matrix,graph->size);
    free(graph);
}

void row_vertexes(vertex* vertexes,int size,int begin){
    for (int i=0; i<size;i++){
        vertexes[i].name = i+begin;
    }
}

mtrx_grph_t* matrixGraph_create(int size){
    mtrx_grph_t* graph = new(mtrx_grph_t);

    graph->matrix = matrix_create(size);
    graph->vertexes = new_block(vertex,size);

    //std color
    _FOR_(i,size){graph->vertexes[i].color = DEFAULT_CONSOLE_COLOR;}

    graph->size = size;

    return graph;
}

void remove_vrtx_memmove(mtrx_grph_t* graph, int vrtxindex){
    int data_size;

    void* dst;
    void* src;

    //удаляем строку
    data_size = (graph->size)*((graph->size)-vrtxindex);

    dst = &(graph->matrix[vrtxindex][0]);
    src = &(graph->matrix[vrtxindex+1][0]);

    intmove(dst,src,data_size);

    //удаляем столбец
    for (int i=0; i<graph->size;i++){
        dst = &(graph->matrix[i][vrtxindex]);
        src = &(graph->matrix[i][vrtxindex+1]);

        data_size=(graph->size)-vrtxindex;

        intmove(dst,src,data_size);
    }

    //удаляем название вершины
    dst = &(graph->vertexes[vrtxindex]);
    src = &(graph->vertexes[vrtxindex+1]);

    memmove(dst,src,(graph->size-vrtxindex)*sizeof(vertex));

    graph->size--;
}

void add_vrtx(mtrx_grph_t* graph,int new_vrtx){
    int old_size=graph->size;

    graph->matrix = (int**)realloc(graph->matrix, (old_size+1) * sizeof(int*));
    graph->matrix[old_size] = (int*)malloc((old_size+1)* sizeof(int));

    for (int i = 0; i < old_size; i++){
        graph->matrix[i] = (int*)realloc(graph->matrix[i], (old_size+1)* sizeof(int));
    }

    graph->size++;
    int new_size=graph->size;

    for (int i=0; i<new_size; i++){
        graph->matrix[new_size-1][i]=0;
        graph->matrix[i][new_size-1]=0;
    }


    graph->vertexes = realloc(graph->vertexes,sizeof(vertex)*new_size);
    graph->vertexes[new_size-1].name = new_vrtx;
}

