#include "listsGraph.h"

bool is_adjacent(list_graph_t* graph, int v_index, int u_index){
    bool adjacency;

    for (int i=0; i<graph->size; i++){
        
    }

    return adjacency;
};


list_graph_t* list_graph_create(int size){
    list_graph_t* graph = malloc(sizeof(list_graph_t));

    graph->lists = new_block(list_t*,size);
    graph->vertexes = new_block(vertex,size);

    graph->size = size;

    return graph;
}

list_graph_t* matrix_to_list(mtrx_grph_t* matrix_graph){
    int size = matrix_graph->size;

    list_graph_t* list_graph = list_graph_create(size);

    list_t* nextList;

    //init head of lists and fill array of vertexes
    for (int i=0; i<size; i++){
        list_graph->vertexes[i].name = matrix_graph->vertexes[i].name;
        list_graph->vertexes[i].color = matrix_graph->vertexes[i].color;

        list_graph->lists[i] = list_create();
        append(list_graph->lists[i],&(list_graph->vertexes[i]));
    }

    for (int i=0; i<size; i++){
        nextList = list_graph->lists[i];

        for (int j=0; j<size; j++){
            if (matrix_graph->matrix[i][j]){
                append(nextList,&(list_graph->vertexes[j]));
            }
        }

    }

    return list_graph;
}

void print_list_graph(list_graph_t* graph){
    for (int i=0; i<graph->size; i++) {
        print_list(graph->lists[i],"%v");
    }
    printf("\n");
}

void list_graph_free(list_graph_t* graph){
    for (int i=0; i<graph->size; i++){
        list_free(graph->lists[i]);
    }

    free(graph);
}

