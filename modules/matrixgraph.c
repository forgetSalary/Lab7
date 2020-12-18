#include "matrixgraph.h"

void print_graph(mtrx_grph_t* graph){
    printf("|v\t|");

    for (int i=0; i<graph->size; i++){
        print_vertex("%v\t|",graph->vertexes[i]);
    }
    printf("\n|");

    for (int i=0; i<graph->size; i++){

        printf("\t|");
    }
    printf("\t|\n");

    for (int i=0; i<graph->size; i++){
        print_vertex("|%v\t",graph->vertexes[i]);
        for (int j=0; j<graph->size; j++){
            printf("|%d\t",graph->matrix[i][j]);
        }
        printf("|\n");
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

    _FOR_(i,size){graph->vertexes[i].color = DEFAULT_CONSOLE_COLOR;}
    graph->size = size;

    return graph;
}

mtrx_grph_t* init_graph_from_str(char* str){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int order=0;
    char next_char=' ';

    int i=0;
    do{
        if (next_char!=' '){
            order++;
        }
        next_char = str[i];
        i++;
    }while (next_char!='\n');


    MATRIX_LOC(data,int,order,order)

    int str_len = strchr(str,'\n') - str;
    _FOR_(i,order){
        _FOR_(j,order){
            next_char = str[2*j+i*(str_len+1)];
            data[i][j] = next_char-48;
        }
    }

    mtrx_grph_t* graph = matrixGraph_create(order);
    graph->matrix = data;

    return graph;
}

mtrx_grph_t* init_graph_from_cgi_client(){
    int data_length = CONTENT_LENGTH;
    char* data = post_data(data_length);
    if (!data_length){printf("error,%d\n",data_length);exit(1);}

    mtrx_grph_t* graph = init_graph_from_str(data);
    free(data);
    row_vertexes(graph->vertexes,graph->size,0);

    return graph;
}

int edge_count(mtrx_grph_t* graph, int kind){
    int count = 0;
    for (int i = 0; i < graph->size; ++i) {
        for (int j = 0; j < graph->size; ++j) {
            if (graph->matrix[i][j]){
                count ++;
            }
        }
    }

    if (kind>=2){
        count /= 2;
    }

    return count;
}

incd_matrix_grph_t* incd_matrixGraph_create(int vertex_count,int edges_count){
    incd_matrix_grph_t* graph = new(incd_matrix_grph_t);

    MATRIX_LOC(matrix,int,edges_count,vertex_count)
    graph->matrix = matrix;
    graph->edges_count = edges_count;
    graph->vertexes_count = vertex_count;
    graph->vertexes_names = new_block(int,vertex_count);
    graph->weights = new_block(int,edges_count);


    return graph;
}

incd_matrix_grph_t* adj_to_incd(mtrx_grph_t* adj_graph,int kind){
    int vertex_count = adj_graph->size;
    int edges_count = edge_count(adj_graph,kind);

    incd_matrix_grph_t* incd_graph = incd_matrixGraph_create(vertex_count,edges_count);
    init_empty_matrix(incd_graph->matrix,vertex_count,edges_count);
    incd_graph->edges_count = edges_count;
    incd_graph->vertexes_count = vertex_count;
    fill(incd_graph->vertexes_names,vertex_count,adj_graph->vertexes[i].name)

    edges_count = 0;

    int c=0;
    int i,j;
    for (i=c; i<adj_graph->size; i++){
        for (j=c; j<adj_graph->size;j++ ) {
            if (adj_graph->matrix[i][j]){
                incd_graph->matrix[i][edges_count] = 1;
                if (kind>=2){incd_graph->matrix[j][edges_count] = 1;}
                else{incd_graph->matrix[j][edges_count] = -1; }
                incd_graph->weights[edges_count] = adj_graph->matrix[i][j];
                edges_count++;
            }
        }
        c++;
    }


    return incd_graph;
}


void print_incd_matrixGraph(incd_matrix_grph_t* graph){
    printf("| \t|");

    for (int i=0; i<graph->edges_count; i++){
        printf("e%d\t|",i+1);
    }
    printf("\n|w");

    for (int i=0; i<graph->edges_count; i++){
        printf("\t|%d",graph->weights[i]);
    }
    printf("\t|\n");

    for (int i=0; i<graph->edges_count; i++){

        printf("|\t");
    }
    printf("|\t|\n");


    for (int i=0; i<graph->vertexes_count; i++){
        printf("|v%d\t",graph->vertexes_names[i]);
        for (int j=0; j<graph->edges_count; j++){
            printf("| %d\t",graph->matrix[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

void remove_vertex(mtrx_grph_t* graph, int vrtxindex){
    int data_size;

    void* dst;
    void* src;

    //удаляем строку
    for (int i=0; i<graph->size;i++){
        for (int j = vrtxindex; j < graph->size-1; j++) {
            graph->matrix[j][i] = graph->matrix[j+1][i];
        }
    }

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

