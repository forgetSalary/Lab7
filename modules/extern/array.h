#ifndef GRAPHMATRIX_ARRAY_H
#define GRAPHMATRIX_ARRAY_H

#endif //GRAPHMATRIX_ARRAY_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

typedef struct array_s {
    void* data;
    size_t value_size;
    size_t data_size;
}array_t;

typedef struct numbers_s {
    int* data;
    size_t size;
}numbers_t;

int get_int_index(int* arr, int size, int num);

#define numbers_get_index(numbers,num) get_int_index(numbers->data,numbers->size,num)
#define fill(block,block_size,value) for(int i=0; i<block_size; i++){block[i] = value;}

array_t* array_create(size_t value_size,size_t data_size);

numbers_t* numbers(int size);

void print_numbers(numbers_t* arr);

void row(int* array,int size, int begin);

void* get_value(array_t* arr, unsigned int index);

void fill_num(numbers_t* arr,int value);