#ifndef GRAPHMATRIX_ARRAY_H
#define GRAPHMATRIX_ARRAY_H

#endif //GRAPHMATRIX_ARRAY_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#define fill(block,block_size,value)    if (block && block_size){for(size_t i=0; i<block_size; i++){block[i] = value;}}
#define random_int(min,max)             min + rand()%(max - min +1)
#define random_ints(arr,size,min,max)   fill(arr,size,random_int(min,max))
#define row(dst,size,begin)             fill(dst,size,i+begin)

typedef struct array_s {
    void* data;
    size_t value_size;
    size_t data_size;
}array_t;

typedef struct numbers_s {
    int* data;
    size_t size;
}numbers_t;

int get_int_index(int* arr, size_t size, int num);

int max_int(int* arr, size_t len);

int min_int(int* arr, size_t len);

#define numbers_get_index(numbers,num) get_int_index(numbers->data,numbers->size,num)

array_t* array_create(size_t value_size,size_t data_size);

numbers_t* numbers(int size);

void print_numbers(numbers_t* arr);

void* get_value(array_t* arr, unsigned int index);

void fill_num(numbers_t* arr,int value);