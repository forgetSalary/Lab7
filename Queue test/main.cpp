#include <iostream>
#include <queue>
#include <ctime>

#define PATH "D:\\CPrctc\\C Graphs\\Queue test\\"

using namespace std;

#define _FOR_(index,range)          for(int index=0;index<range;index++)

#define MATRIX_LOC(name,type,rows,cols) \
type** name = (type**)malloc(cols*sizeof(type*)); \
for(int i=0; i<cols; i++){\
    name[i] = (type*)malloc(rows*sizeof(type));\
}

#define MATRIX_FREE(matrix,cols) \
for(int i=0; i<cols; i++){\
    free(matrix[i]);\
}\
\
free(matrix);\

typedef struct matrix_graph{
    int** matrix;
    int order;
}matrix_graph_s;

void print_matrix(FILE* stream, int** matrix, int size, char _break){
    _FOR_(i,size){
        _FOR_(j,size) {
            fprintf(stream,"%d%c", matrix[i][j],_break);
        }
        fprintf(stream,"\n");
    }
}

void std_queue_bfs(matrix_graph_s* graph, int vertex_index){
    //every i in dist = -1
    int* dist = new int[graph->order];
    _FOR_(i,graph->order){dist[i]=-1;}

    queue<int> vertexes_queue;
    vertexes_queue.push(vertex_index);
    dist[vertex_index] = 0;

    int v;//next vertex

    printf("%d,",vertex_index);
    while (!vertexes_queue.empty()){
        v = vertexes_queue.front();
        vertexes_queue.pop();

        _FOR_(i,graph->order){
            if (graph->matrix[v][i] && dist[i]==-1) {
                vertexes_queue.push(i);

                dist[i]=dist[v]+1;
                //printf("%d,",i);
            }
        }
    }

    delete[] dist;
    printf("\n\n");
}

matrix_graph_s* read_graph(const char* fname){
    errno_t err;
    FILE* input;
    err = fopen_s(&input,fname,"r");

    if(err==0){
        int order=0;

        char next_char=' ';

        int position = ftell(input);
        do{
            if (next_char!=' '){
                order++;
            }
            next_char = fgetc(input);
        }while (next_char!='\n');
        fseek(input, position, SEEK_SET);

        MATRIX_LOC(data,int,order,order)

        _FOR_(i,order){
            _FOR_(j,order){
                fscanf(input,"%d",&data[i][j]);
            }
        }

        matrix_graph_s* graph = new matrix_graph_s;

        graph->matrix = data;
        graph->order = order;

        return graph;
    }
    else{
        printf( "The file '%s' was not opened\n",fname);
        return NULL;
    }


}

void test(){
    system("cls");
    int order=0;
    matrix_graph_s* graph = read_graph(PATH"matrix.test");

    if (graph){
        printf("\nStd queue\n");
        clock_t start_time, finish_time;

        start_time=clock();
        std_queue_bfs(graph,0);
        finish_time=clock();

        double wait_time = (double)(finish_time - start_time) / CLOCKS_PER_SEC;
        printf("Time:%f s\n",wait_time);


        MATRIX_FREE(graph->matrix,graph->order)
        delete [] graph;
    }
}

int main(int argc, char* argv[]) {
    test();

    return 0;
}
