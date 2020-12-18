#include "array.h"

array_t* array_create(size_t value_size,size_t data_size){
    array_t* arr = malloc(sizeof(array_t));
    arr->data = malloc(value_size*data_size);

    arr->value_size = value_size;
    arr->data_size = data_size;

    return arr;
}

void* get_value(array_t* arr, unsigned int index){
    if (index<arr->data_size && index>0){
        uint8_t* ptr_to_value = arr->data;
        ptr_to_value+=arr->value_size*index;
        return ptr_to_value;
    }
    else{
        assert("Index is out of range");
        return NULL;
    }
}

numbers_t* numbers(int size){
    numbers_t* arr = malloc(sizeof(numbers_t));
    arr->data = malloc(sizeof(int)*size);
    arr->size = size;

    return arr;
}

void numbers_free(numbers_t* arr){
    free(arr->data);
    free(numbers);
}

int get_int_index(int* arr, size_t size, int num){
    for(int i=0;i<size;i++){
        if (arr[i] == num){
            return i;
        }
    }
    return -1;
}

int max_int(int* arr, size_t len){
    int max_val = INT32_MIN;
    for (size_t i = 0; i<len; i++){
        max_val = max(max_val,arr[i]);
    }
    return max_val;
}

int min_int(int* arr, size_t len){
    int min_val = INT32_MAX;
    for (size_t i = 0; i<len; i++){
        if (arr[i]>0){
            min_val = min(min_val,arr[i]);
        }

    }
    return min_val;
}


void print_numbers(numbers_t* array){
    for(int i=0;i<array->size-1;i++){
        printf("%d,",array->data[i]);
    }
    printf("%d\n",array->data[array->size-1]);
}

void fill_num(numbers_t* array,int value){
    for(int i=0;i<array->size;i++){
        array->data[i]=value;
    }
}