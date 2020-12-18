#include "tests.h"
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 8
#define density 0.5

int check_graph_args(int argc, char* argv[]){
    int kind_of_graph;
    if (argc > 2) {
        int wt = strcmp(argv[2], "wt");
        if (strcmp(argv[1], "ornd") == 0) {
            if (wt == 0) {kind_of_graph = 0;}//ориентировнный взвешанный
            else {kind_of_graph = 1;}//ориентировнный невзвешанный
        } else {
            if (wt == 0) {kind_of_graph = 2;}//неориентировнный взвешанный
            else { kind_of_graph = 3;}//неориентировнный невзвешанный
        }
        return kind_of_graph;
    }
    else{
        printf("Two arguments expected");
        return -1;
    }
}

int main(int argc, char* argv[]){
//    int kind_of_graph = check_graph_args(argc,argv);
//    (kind_of_graph == -1 ?  exit(1) : 0);
//
//    int SIZE;
//    float density;
//    printf("Enter size and density to init graph: \n");
//    scanf("%d%f", &SIZE,&density);


    lab8(SIZE,density,0);

    return 0;
}