#include "tools.h"

int bytescmp(char* _buf1,char* _buf2,size_t size){
    int count = 0;

    for (int i=0; i<size; i++){
        if (_buf1[i] == _buf2[i]){
            count++;
        }
    }

    if (count==size){
        return 0;
    }
    else{
        return 1;
    }
}


int get_index_from_exact_value(char* array, int size, void* value, size_t value_size){
    int index=0;

    for (int i=0; i<size;i++) {
        if (bytescmp(array,(char*)value,value_size)==0){
            return index;
        }
        else{
            index++;
        }
        array += value_size;
    }

    return -1;
}
int get_index_from_ptr(char** array, int size, void* value, size_t value_size){
    int index=0;

    for (int i=0; i<size;i++) {
        if (bytescmp(array[i],(char*)value,value_size)==0){
            return index;
        }
        else{
            index++;
        }
    }

    return -1;
}


int get_index(char value_is_ptr,void* array, int size, void* value, size_t value_size){
    int index;
    if (value_is_ptr){
        index=get_index_from_ptr((char**)array,size,value,value_size);
    }
    else{
        index=get_index_from_exact_value((char*)array,size,value,value_size);
    }

    return index;
}

void row(int* array,int size, int begin){
    for (int i=0; i<size;i++){
        array[i]=i+begin;
    }
}


void intmove(int* dst, int* src, int size){
    for (int i=0;i<size;i++){
        *(dst+i)=*(src+i);
    }
}

int one_or_zero(float chance){
    int a = rand()%100;
    if ((float)a<(100*chance)){
        return 1;
    }
    else{
        return 0;
    }
}

int positive_or_zero(int max, double chance){
    int a = rand()%100;
    if ((float)a<(100*chance)){
        return 1+rand()%max;
    }
    else{
        return 0;
    }
}

int fst_false(bool* arr,int size){
    int count=0;

    while (arr[count] && count<size){
        count++;
    }
    if (count==size){
        return -1;
    }
    else{
        return count;
    }

}
