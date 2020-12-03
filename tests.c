#include "tests.h"
void init_matrix(mtrx_grph_t* graph, int MAX, float chance, char** args){
    int wt = strcmp(args[2], "wt");
    if (strcmp(args[1], "ornd") == 0) {
        if(wt == 0){init_random_oriented_matrix(graph->matrix, graph->size, MAX, chance);}
        else {init_bin_oriented_matrix(graph->matrix, graph->size, chance);}
    }
    else{
        if(wt == 0){init_random_symetric_matrix(graph->matrix, graph->size, MAX, chance);}
        else{init_bin_symetric_matrix(graph->matrix, graph->size, chance);}
    }
}

void test_dfs_matrix(int SIZE, int vrtx){
    printf("DFS distances, matrix graph\n");
    mtrx_grph_t* matrix_graph = matrixGraph_create(SIZE);
    srand( time(NULL) );

    init_bin_symetric_matrix(matrix_graph->matrix,SIZE,0.5);

//    int matrix[5][5] ={{0,1,0,1,0},
//                       {1,0,1,0,1},
//                       {0,1,0,0,0},
//                       {1,0,0,0,1},
//                       {0,1,0,1,0}};
//
//    _FOR_(i,5){
//        memcpy(matrix_graph->matrix[i],matrix[i],sizeof(int)*5);
//    }

    row(matrix_graph->vertexes,SIZE,0);

    print_graph(matrix_graph);

    //print_matrix(stdout,matrix_graph->matrix,matrix_graph->size,',');

    numbers_t* distances = numbers(SIZE);

    printf("Depth-first search from '%d'\n",vrtx);
    dfs_matrix(matrix_graph,vrtx,distances);
    dist_log(matrix_graph->vertexes,vrtx,distances);
}

void test_dfs_lists(int SIZE, int vrtx){
    printf("\nDFS distances, lists graph\n");
    mtrx_grph_t* matrix_graph = matrixGraph_create(SIZE);

    srand( time(NULL) );
    init_bin_symetric_matrix(matrix_graph->matrix,SIZE,0.5);

//    int matrix[5][5] ={{0,1,0,1,0},
//                       {1,0,1,0,1},
//                       {0,1,0,0,0},
//                       {1,0,0,0,1},
//                       {0,1,0,1,0}};
//
//    _FOR_(i,5){
//        memcpy(matrix_graph->matrix[i],matrix[i],sizeof(int)*5);
//    }

    row(matrix_graph->vertexes,SIZE,0);

    list_graph_t* list_graph = matrix_to_list(matrix_graph);

    //print_matrix(stdout,matrix_graph->matrix,matrix_graph->size,',');
    print_list_graph(list_graph);

    //print_matrix(stdout,matrix_graph->matrix,matrix_graph->size,',');

    numbers_t* distances = numbers(SIZE);

    printf("Depth-first search from '%d'\n",vrtx);
    int* component = NULL;
    bool* visited = calloc(matrix_graph->size,1);
    dfs_lists(list_graph,vrtx,distances,component,visited);
    dfs_log(component);
    dist_log(matrix_graph->vertexes,vrtx,distances);
    free(visited);
}

void test_bfs_matrix(int SIZE,int vrtx){
    printf("\nBFS distances, matrix graph\n");
    mtrx_grph_t* matrix_graph = matrixGraph_create(SIZE);

    srand( time(NULL) );
    init_bin_symetric_matrix(matrix_graph->matrix,SIZE,0.2);

//    int matrix[5][5] ={{0,1,0,1,0},
//                       {1,0,1,0,1},
//                       {0,1,0,0,0},
//                       {1,0,0,0,1},
//                       {0,1,0,1,0}};
//
//    _FOR_(i,5){
//        memcpy(matrix_graph->matrix[i],matrix[i],sizeof(int)*5);
//    }

    row(matrix_graph->vertexes,SIZE,0);

    print_graph(matrix_graph);

    //print_matrix(stdout,matrix_graph->matrix,matrix_graph->size,',');

    numbers_t* distances = numbers(SIZE);

    printf("Breadth-first search from '%d'\n",vrtx);
    //printf("Custom queue\n");
    clock_t start_time, finish_time;

    start_time=clock();
    bfs_matrix(matrix_graph,vrtx,distances);
    finish_time=clock();

    double wait_time = (double)(finish_time - start_time) / CLOCKS_PER_SEC;
    printf("Time:%f s\n",wait_time);

    dist_log(matrix_graph->vertexes,vrtx,distances);
//
//    FILE* output = fopen(PATH"Queue test\\matrix.test","w");
//    print_matrix(output,matrix_graph->matrix,matrix_graph->size,' ');
//    fclose(output);

    free(distances->data);
    free(distances);
}

void test_bfs_lists(int SIZE,int vrtx_index){
    printf("\nBFS distances, lists graph\n");
    mtrx_grph_t* matrix_graph = matrixGraph_create(SIZE);

    srand( time(NULL) );
    init_bin_symetric_matrix(matrix_graph->matrix,SIZE,0.2);

//    int matrix[5][5] ={{0,1,0,1,0},
//                       {1,0,1,0,1},
//                       {0,1,0,0,0},
//                       {1,0,0,0,1},
//                       {0,1,0,1,0}};
//
//    _FOR_(i,5){
//        memcpy(matrix_graph->matrix[i],matrix[i],sizeof(int)*5);
//    }

    row(matrix_graph->vertexes,SIZE,0);

    list_graph_t* list_graph = matrix_to_list(matrix_graph);

    //print_matrix(stdout,matrix_graph->matrix,matrix_graph->size,',');
    print_list_graph(list_graph);

    numbers_t* distances = numbers(SIZE);

    printf("Breadth-first search from ");
    print_vertex("'%v'\n",list_graph->vertexes[vrtx_index]);

    //printf("Custom queue\n");

    bfs_lists(list_graph,vrtx_index,distances);
    dist_log(matrix_graph->vertexes,vrtx_index,distances);
}

void test_components(int SIZE){
    printf("\nDFS distances, lists graph\n");
    mtrx_grph_t* matrix_graph = matrixGraph_create(SIZE);
    srand( time(NULL) );
    init_bin_symetric_matrix(matrix_graph->matrix,SIZE,0.2);
    row(matrix_graph->vertexes,SIZE,0);

    list_graph_t* list_graph = matrix_to_list(matrix_graph);

    print_list_graph(list_graph);

    int*** result = components_and_dist_dfs_Lists(list_graph);
    components_log(result[0]);
    dists_log(result[1],matrix_graph->vertexes,list_graph->size);
}

void test_bfsd_matrix(int SIZE,int MAX,int argc, char** argv){
    if (argc > 2) {
        printf("\nBFSD matrix graph\n");
        mtrx_grph_t *matrix_graph = matrixGraph_create(SIZE);
        srand(time(NULL));
        row_vertexes(matrix_graph->vertexes, SIZE, 1);

        init_matrix(matrix_graph,MAX,0.5,argv);

        print_graph(matrix_graph);
        //print_matrix(stdout, matrix_graph->matrix, SIZE, SIZE, ',');

        numbers_t *distances = numbers(SIZE);
        bfsd_matrix(matrix_graph, 0, distances);
        dist_log(matrix_graph->vertexes, 0, distances);
    }
    else{printf("Two arguments expected");}
}

void test_indp_sets(int SIZE,char** argv){
    mtrx_grph_t* graph = matrixGraph_create(SIZE);
    srand(time(NULL));
    row_vertexes(graph->vertexes, SIZE, 1);

    init_matrix(graph,SIZE,0.5,argv);

    print_matrix(stdout,graph->matrix,SIZE,SIZE,',');

    int** colors = indp_sets(graph);
    printf("\n");
    log_indp_sets(stdout,colors);
    free_indp_sets(colors);

    print_matrix(stdout,graph->matrix,SIZE,SIZE,',');
    printf("\n%d colors were found\n",color_graph(graph,colors));
    free_indp_sets(colors);

    print_graph(graph);
}

void test_kursach(int argc, char** argv){
    if (argc > 2) {
        int SIZE;
        float density;

        scanf("%d", &SIZE);
        scanf("%f", &density);

        mtrx_grph_t *graph = matrixGraph_create(SIZE);
        srand(time(NULL));
        row_vertexes(graph->vertexes, SIZE, 1);

        init_matrix(graph, SIZE, density, argv);
        //print_matrix(stdout,graph->matrix,SIZE,SIZE,',');
        FILE *json = fopen(JS_OUTPUT_PATH, "w");

        fprintf(json, "{\"matrix\": \"");
        print_matrix_to_json(json, graph->matrix, SIZE);
        fprintf(json, "\",\"sets\": \"");

        int **colors = indp_sets(graph);
        //printf("\n");
        //log_indp_sets(stdout,colors);
        log_indp_sets_to_json(json, colors);
        fprintf(json, "\"}");

        free_indp_sets(colors);
    }
}

void test_vertex(){
    list_t* list = list_create();

    vertex array[]={
            {1,1},
            {2,2},
    };

    append(list,&array[0]);
    append(list,&array[1]);

    print_list(list,"%v");
    print_list(list,"%v");
    print_list(list,"%v");

    list_free(list);
}

void test_numbers(){
    numbers_t* nums = numbers(20);
    row(nums->data,20, 1);
    print_numbers(nums);
}

void test_stretchy_buffers(){
    int** buffer=NULL;

    buf_push(buffer,NULL);
    buf_push(buffer,NULL);
    buf_push(buffer,NULL);

    buf_push(buffer[0],0);

    buf_push(buffer[1],0);
    buf_push(buffer[1],1);

    buf_push(buffer[2],0);
    buf_push(buffer[2],1);
    buf_push(buffer[2],2);

    _FOR_(i,buf_len(buffer)){
        _FOR_(j,buf_len(buffer[i])){
            printf("%d,",buffer[i][j]);
        }
        printf("\n");
    }
}

void test(){
    int* buf = NULL;

    buf_push(buf,1);

}
