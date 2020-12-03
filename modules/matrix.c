#include "matrix.h"

void init_empty_matrix(int** matrix, int size){
    for (int i=0; i<size; i++){
        for (int j=0; j<size;j++ ){
            matrix[i][j]=0;
        }
    }
}

void init_bin_symetric_matrix(int** matrix, int size, float chance){
    int c=0;

    int i,j;
    for (i=c; i<size; i++){
        for (j=c; j<size;j++ ) {
            matrix[i][j] = one_or_zero(chance);
            matrix[j][i] = matrix[i][j];
        }
        c++;
    }

    //обнуление диагонали
    for (i=0; i<size; i++){
        matrix[i][i] = 0;
    }
}

int init_random_symetric_matrix(int** matrix, int size, int max, float chance){
    int c=0;

    int i,j;
    for (i=c; i<size; i++){
        for (j=c; j<size;j++ ) {
            matrix[i][j] = positive_or_zero(max,chance);
            matrix[j][i] = matrix[i][j];
        }
        c++;
    }

    //обнуление диагонали
    for (i=0; i<size; i++){
        matrix[i][i] = 0;
    }
}

void init_random_oriented_matrix(int** matrix, int size, int max, float chance){
    int c=0;
    int i,j;
    for (i=c; i<size; i++){
        for (j=c; j<size;j++ ) {
            matrix[i][j] = positive_or_zero(max,chance);
            matrix[j][i] = 0;
        }
        c++;
    }

    //обнуление диагонали
    for (i=0; i<size; i++){
        matrix[i][i] = 0;
    }
}

void init_bin_oriented_matrix(int** matrix, int size, float chance){
    int c=0;
    int i,j;
    for (i=c; i<size; i++){
        for (j=c; j<size;j++ ) {
            matrix[i][j] = one_or_zero(chance);
            matrix[j][i] = 0;
        }
        c++;
    }

    //обнуление диагонали
    for (i=0; i<size; i++){
        matrix[i][i] = 0;
    }
}

void print_matrix(FILE* stream, int** matrix, int rows,int cols, char _break){
    _FOR_(i,cols){
        _FOR_(j,rows) {
            fprintf(stream,"%d%c", matrix[i][j],_break);
        }
        fprintf(stream,"\n");
    }
}

void print_matrix_to_json(FILE* stream, int** matrix, int size){
    _FOR_(i,size){
        _FOR_(j,size) {
            fprintf(stream,"%d,", matrix[i][j]);
        }
        fprintf(stream,"\\n");
    }
}

int** matrix_create(int size){
    MATRIX_LOC(matrix,int,size,size)

    return matrix;
}

void matrix_free(int** matrix,int size){
    MATRIX_FREE(matrix,size)
}