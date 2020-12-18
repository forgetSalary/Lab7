#include "tests.h"
int init_matrix(mtrx_grph_t* graph, int MAX, float chance, int kind){
    switch (kind) {
        case 0:
            init_random_oriented_matrix(graph->matrix, graph->size, MAX, chance);
            break;
        case 1:
            init_bin_oriented_matrix(graph->matrix, graph->size, chance);
            break;
        case 2:
            init_random_symetric_matrix(graph->matrix, graph->size, MAX, chance);
            break;
        case 3:
            init_bin_symetric_matrix(graph->matrix, graph->size, chance);
            break;
        default:
            return 1;
    }
    return 0;

}

void test_matrix(int SIZE, float density,int kind){
    MATRIX_LOC(matrix,int,SIZE,SIZE)
    switch (kind) {
        case 0:
            init_random_oriented_matrix(matrix, SIZE, SIZE, density);
            break;
        case 1:
            init_bin_oriented_matrix(matrix, SIZE, density);
            break;
        case 2:
            init_random_symetric_matrix(matrix, SIZE, SIZE, density);
            break;
        case 3:
            init_bin_symetric_matrix(matrix, SIZE, density);
            break;
    }
    print_matrix(stdout,matrix,SIZE,SIZE,',');
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

    row_vertexes(matrix_graph->vertexes,SIZE,0);

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

    row_vertexes(matrix_graph->vertexes,SIZE,0);

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

    row_vertexes(matrix_graph->vertexes,SIZE,0);

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

    row_vertexes(matrix_graph->vertexes,SIZE,0);

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
    row_vertexes(matrix_graph->vertexes,SIZE,0);

    list_graph_t* list_graph = matrix_to_list(matrix_graph);

    print_list_graph(list_graph);

    int*** result = components_and_dist_dfs_Lists(list_graph);
    components_log(result[0]);
    dists_log(result[1],matrix_graph->vertexes,list_graph->size);
}

void test_bfsd_matrix(int SIZE,int MAX,int kind_of_graph){
    printf("\nBFSD matrix graph\n");
    mtrx_grph_t *matrix_graph = matrixGraph_create(SIZE);
    srand(time(NULL));
    row_vertexes(matrix_graph->vertexes, SIZE, 1);

    init_matrix(matrix_graph,MAX,0.5,kind_of_graph);

    print_graph(matrix_graph);
    //print_matrix(stdout, matrix_graph->matrix, SIZE, SIZE, ',');

    int* distances = new_block(int,SIZE);
    bfsd_matrix(matrix_graph, 0, distances);
    dist_log(matrix_graph->vertexes, 0, distances);


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

void test_kursach(){
    mtrx_grph_t* graph = init_graph_from_cgi_client();

    cnt_type("text/plain");

    int **colors = indp_sets(graph);
    log_indp_sets(stdout, colors);

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

void test_stretchy_buffers_pushing(){
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

void test_stretchy_buffers_const_sized(){
    int* buffer = NULL;
    buffer = buf__grow(buffer,3,sizeof(int));

    buf_push(buffer,1);
    buf_push(buffer,2);
    buf_push(buffer,3);


    FOR(i,buf_len(buffer)){
        printf("%d,",buffer[i]);
    }

}

void test_incd_matrix_graph(int adj_mtrx_order, float density, int kind_of_graph){
    mtrx_grph_t* adj_matrix_graph = matrixGraph_create(adj_mtrx_order);
    srand( time(NULL) );

    init_matrix(adj_matrix_graph,adj_mtrx_order,density,kind_of_graph);
    row_vertexes(adj_matrix_graph->vertexes,adj_mtrx_order,0);

    incd_matrix_grph_t* incd_matrix_graph = adj_to_incd(adj_matrix_graph,kind_of_graph);
    print_graph(adj_matrix_graph);
    print_incd_matrixGraph(incd_matrix_graph);

    int* dists = new_block(int,adj_mtrx_order);

    bfsd_matrix(adj_matrix_graph,0,dists);
    dist_log(adj_matrix_graph,0,dists);

    bfsd_incd_matrix(incd_matrix_graph,0,dists);
    dist_log_incd(incd_matrix_graph,0,dists);

    del(dists);
}

void lab8(int adj_mtrx_order, float density, int kind_of_graph){
    //task 1
    mtrx_grph_t* adj_matrix_graph = matrixGraph_create(6);
    srand( time(NULL) );

    init_matrix(adj_matrix_graph,adj_mtrx_order,density,kind_of_graph);
    row_vertexes(adj_matrix_graph->vertexes,6,0);

    print_graph(adj_matrix_graph);
    int radius = rad(adj_matrix_graph);
    printf("Radius = %d\n",radius);

    int diameter = diam(adj_matrix_graph);
    printf("Diameter = %d\n\n",diameter);

    int* peripherals = vertexes_with_ecntr(adj_matrix_graph,diameter);
    int* centrals = vertexes_with_ecntr(adj_matrix_graph,radius);

    printf("Peripheral vertex: ");
    for (int i = 0; i <buf_len(peripherals); ++i){
        print_vertex("%v,",adj_matrix_graph->vertexes[peripherals[i]]);
    }
    printf("\n");

    printf("Central vertex: ");
    for (int i = 0; i <buf_len(centrals); ++i) {
        print_vertex("%v,",adj_matrix_graph->vertexes[centrals[i]]);
    }
    printf("\n");

    int* isolated = vertexes_with_degree(adj_matrix_graph,0);
    int* ends = vertexes_with_degree(adj_matrix_graph,1);

    printf("\n");
    if (buf_len(isolated)){
        printf("Isolated vertex: ");
        for (int i = 0; i <buf_len(isolated); ++i) {
            print_vertex("%v,",adj_matrix_graph->vertexes[isolated[i]]);
        }
        printf("\n");
    }
    else{
        printf("No isolated vertexes\n");
    }

    if (buf_len(ends)){
        printf("End vertex: ");
        for (int i = 0; i <buf_len(ends); ++i) {
            print_vertex("%v,",adj_matrix_graph->vertexes[ends[i]]);
        }
        printf("\n");
    }
    else{
        printf("No end vertexes\n");
    }

    //task 2
    incd_matrix_grph_t* incd_matrix_graph = adj_to_incd(adj_matrix_graph,kind_of_graph);

    printf("\n");
    print_incd_matrixGraph(incd_matrix_graph);
    radius = rad_incd(incd_matrix_graph);
    printf("Radius = %d\n",radius);

    diameter = diam_incd(incd_matrix_graph);
    printf("Diameter = %d\n\n",diameter);

    peripherals = vertexes_with_ecntr_incd(incd_matrix_graph,diameter);
    centrals = vertexes_with_ecntr_incd(incd_matrix_graph,radius);

    printf("Peripheral vertex: ");
    for (int i = 0; i <buf_len(peripherals); ++i){
        printf("%d,",incd_matrix_graph->vertexes_names[peripherals[i]]);
    }
    printf("\n");

    printf("Central vertex: ");
    for (int i = 0; i <buf_len(centrals); ++i) {
        printf("%d,",incd_matrix_graph->vertexes_names[centrals[i]]);
    }
    printf("\n");

    isolated = vertexes_with_degree_incd(incd_matrix_graph,0);
    ends = vertexes_with_degree_incd(incd_matrix_graph,1);

    printf("\n");
    if (buf_len(isolated)){
        printf("Isolated vertex: ");
        for (int i = 0; i <buf_len(isolated); ++i) {
            printf("%d,",incd_matrix_graph->vertexes_names[isolated[i]]);
        }
        printf("\n");
    }
    else{
        printf("No isolated vertexes\n");
    }

    if (buf_len(ends)){
        printf("End vertex: ");
        for (int i = 0; i <buf_len(ends); ++i) {
            printf("%d,",incd_matrix_graph->vertexes_names[ends[i]]);
        }
        printf("\n");
    }
    else{
        printf("No end vertexes\n");
    }

    buf_free(peripherals);
    buf_free(centrals);
    buf_free(isolated);
    buf_free(ends);
}

void test_coloring_time(int SIZE, float density){
    mtrx_grph_t* graph = matrixGraph_create(SIZE);
    srand(time(NULL));
    init_bin_oriented_matrix(graph->matrix,SIZE,0.3);
    row_vertexes(graph->vertexes,SIZE,0);

    clock_t start_time = clock();
    int** sets1 = indp_sets(graph);
    clock_t finish_time = clock();

    double result = (double) (finish_time - start_time) / CLOCKS_PER_SEC;

    printf("Size: %d; Density: %.2f; Time: %f; X(G):%d",SIZE,density,result,buf_len(sets1));
}

void test_cgi(){
    cnt_type("text/plain");

    int data_length = CONTENT_LENGTH;
    char* data = post_data(data_length);

    if (data_length){printf("%s;%d",data,data_length);}
    else{printf("error,%d\n",data_length);}
}

void test(){
    int* buf = NULL;

    buf_push(buf,1);

}
