#ifndef GRAPHMATRIX_AL_STRING_H
#define GRAPHMATRIX_AL_STRING_H

#endif //GRAPHMATRIX_AL_STRING_H

#include <malloc.h>
#include "stdarg.h"

typedef struct string_s {
    char* data;

    size_t data_size;
    size_t lenght;
}string_t;


int _cdecl str_len(const char* str);

string_t* str_init(int data_size);

string_t* str_del(string_t* string);

string_t* str_dup(const char* src);